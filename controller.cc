#include "controller.h"
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <fstream>
#include "game.h"
#include "textdisplay.h"
using namespace std;

Controller::Controller(){
   game = NULL;
   td = NULL;
   players = NULL;
   doubletime = 0;
   index = 0;
   alivep = 100;
}

Controller::~Controller(){
   delete td;
   delete game;
   delete players;
   delete playOrder;
}

void Controller::notifyG(int move){
   game->notifiedC(move);

}

void Controller::notifyGAct(string action){
   game->notifiedCAct(action);
   if(alivep== 1){
            return;
         }
}

void Controller::notifyT(char symbol, int move){
   td->notified(symbol, move);
   td->printBoard(cout);
}

void Controller::modifyBoard(char c){
   td->notified(c,-100);
   td->printBoard(cout);
}

void Controller::bankrupt(char p, bool anymoney, bool anybuilding){
   if(anymoney){
      if(anybuilding){
         cout << p << " is about to bankrupt, choose one of the following actions: "<<endl;
         cout << "bankrupt, mortgage, or trade"<<endl;
         string action;
         cin >> action;
         if(action == "bankrupt"){
            cout << "You lost!" << endl; 
            td->removePlayer(playOrder[index]);   
            game->out(index);
            playOrder[index] = '0';
            alivep -= 1;
            if(alivep == 1){
               for(int i=0; i<totalPlayer; i++){
                  if(playOrder[i]!='0'){
                     index=i;
                  }
               }
               cout << "Player " << playOrder[index] << " win!" << endl;
               cout <<"Please enter quit to end."<<endl;
               return;
            }else{
               auctionWrap(p);
            }
         }else if(action == "mortgage"){
            string property;
            cin >> property;
            mortgage(property);
         }else{
            string target;
            cin >> target;
            string give;
            cin>>give;
            string exchange;
            cin>>exchange;
            stringstream ss(exchange);
            int amount;
            if(ss >> amount){
               trade3(target, give, amount); 
            }else{
               trade2(target, give, exchange); 
            }
         }
      }else{
         cout << "You are about to bankrupt, choose one of the following actions: "<<endl;
         cout << "bankrupt" << endl;
         string br;
         cin >> br;
         cout << "You lost!" << endl;
         td->removePlayer(playOrder[index]);
cout<<"controller 105: "<<index<<endl;                  
         game->out(index);
         playOrder[index] = '0';
         alivep -= 1;
         if(alivep == 1){
            for(int i=0; i<totalPlayer; i++){
                  if(playOrder[i]!='0'){
                     index=i;
                  }
               }
            cout << "Player " << playOrder[index] << " win!" << endl;
            cout <<"Please enter quit to end."<<endl;
            return;
         }else{
            auctionWrap(p);

         }
      }
   }
}

void Controller::buy(){
      cout << "Would you like to buy this buiding? Please enter \"buy\" or \"auction\"" << endl;
      string action;
      cin >> action;
      if(action == "buy"){
         notifyGAct(action);
                  if(alivep== 1){
            return;
         }
      }else if(action == "auction"){
         cout << "This building is now on auction!" << endl;
         notifyGAct(action);
         if(alivep== 1){
            return;
         }
      }
      
}

void Controller::mortgage(string property){
   game->mortgage(property);
}

void Controller::unmortgage(string property){
   game->unmortgage(property);
}


int Controller::roll(){
   int die1 = rand() % 5 + 1;
   int die2 = rand() % 5 + 1;
   cout<<"You rolled "<<die1<<" "<<die2<<endl;
   if(die1 == die2){
      cout << "Rolled a double, Reroll! (please enter \"roll\")" << endl;
      string r;
      cin>>r;
      if(doubletime == 3){
         doubletime = 0;
         return -100;
      }else{
         doubletime += 1;
         return roll();
      }

   }else{
      doubletime = 0;
      int result=die1+die2;
      
      return result;
   }

}

int Controller::testroll(){
   int die1, die2;
   cin >> die1;
   cin >> die2;
   cout<<"You rolled "<<die1<<" "<<die2<<endl;
   if(die1 == die2){
      cout << "Rolled a double, Reroll! (please enter \"roll\")" << endl;
      string r;
      cin >> r;
      if(doubletime == 3){
         doubletime = 0;
         return -100;
      }else{
         doubletime += 1;
         return testroll();
      }

   }else{
      doubletime = 0;
      int result=die1+die2;
      return result;
   }
}

void Controller::next(){
   game->next();
}

void Controller::assets(){
   game->assets();
}


void Controller::auctionWrap(char p){
   game->auctionWrap(p);
}

void Controller::trade1(string target, int amount, string property){
   game->trade1(target, amount, property);
}

void Controller::trade3(string target, string give, int amount){
   game->trade3(target, give, amount);
}
               
void Controller::trade2(string target, string give, string exchange){
   game->trade2(target, give, exchange);
}

void Controller::improvebuy(string property){
   game->improvebuy(property);
}
                  
void Controller::improvesell(string property){
   game->improvesell(property);
}

void Controller::save(string filename){
   game->save(filename);
}

void Controller::load(ifstream &in){
//player
   int totalP=0;
   in>>totalP;
   this->game->setTotalP(totalP);
   totalPlayer=totalP;
   map<string,char> *list=new map<string,char>;
   char *order=new char[totalPlayer];
   Player **p=new Player *[totalPlayer];
   int tempPos[totalPlayer];
   for(int i=1; i<=totalPlayer; i++){
      char symbol;
      string name;
      in>>name;
      in>>symbol;
      (*list)[name]=symbol;
      order[i-1]=symbol;
      int rim;
      int bal;
      int pos;
      in>>rim;
      in>>bal;
      in>>pos;
      tempPos[i-1]=pos;
      p[i-1]=new Player(pos,name,symbol,bal,rim,this->game);
      if(pos==10){
	      int flag;//flag for if player was sent to jall
	      in>>flag;
         if(flag==1){
	        	int turns;//the number of turns they’ve been there
            in>>turns;
            game->setPlayer(p[i-1],true,turns);
         }
      }	
   }
   this->td=new TextDisplay(this, order, totalPlayer);
   for(int i=0;i<totalPlayer;i++){
      this->td->notified(order[i],tempPos[i]);
   }
   this->players=list;
   this->game->players=p;
   this->playOrder=order;
//******************************
//building
   string name;
   while(in>>name){
      string owner;
      int impro;
      in>>owner;
      in>>impro;
      this->game->setBuilding(name,owner,impro);
      for(int i=0;i<impro;i++){
         this->td->printImprove(cout,this->game->search(name),"improve");
      }
   }
}



int Controller::getAliveP(){
   return alivep;
}

void Controller::play(string file, string mode){//mode is either "-testing" or "normal",file is the filename if load mode, empty string otherwise
   game= new Game(this);
   if(file!=""){
      ifstream fs(file.c_str());
      load(fs);
      td->printBoard(cout);
      cout<<"Welcome back!"<<endl;
   }else{
      cout<<"Please enter total number of players:"<<endl;
      int totalP;
      cin>>totalP;
      this->game->setTotalP(totalP);
      totalPlayer=totalP;
      cout<<"Please set up name and symbol (eg: John $):"<<endl;
      map<string,char> *list=new map<string,char>;
      char *order=new char[totalPlayer];
      Player **pl=new Player *[totalPlayer];
      for(int i=0; i<totalPlayer;i++){
         string name;
         char symbol;
         cin>>name;
         cin>>symbol;
         (*list)[name]=symbol;
         order[i]=symbol;
         pl[i]=new Player(0,name,symbol,1500,0,this->game);
      }
      this->game->players=pl;
      this->players=list;
      this->playOrder=order;
      this->td=new TextDisplay(this, playOrder, totalPlayer);
      for(int i=0; i<totalPlayer; i++){
         td->notified(playOrder[i],0);
      }
      cout<<"Let the game start!"<<endl;
      td->printBoard(cout);
      
   }
   game->next();
   alivep = totalPlayer;
   srand(time(NULL));
   while(true){
      //start playing
      for(int i = 0; i < totalPlayer; i++){

         if(playOrder[i] == '0'){
            continue;
         }
//         index=i;
         cout << "Player " << playOrder[i] << "'s round:" << endl;

          bool alreadyroll = false;
         while(true){
           
            string command;
            if(! game->checkSent(playOrder[i]) )cin >> command;

         	if(game->checkSent(playOrder[i])){ 
               if(!alreadyroll){
         		notifyG(0);
	            alreadyroll=true;
               }
         		cin>>command;
	        }else{ 
            if(command == "roll"){
               if(alreadyroll){
                  cout << "Cannot roll again!" << endl;
               }else{
                  int move=0;
                  if(mode != "-testing"){
                     move = roll();                 
                  }else{
                     move = testroll();
                  }
                 
                  if(move==-100) notifyT(playOrder[i], -100);//three doubles in a row
                  else notifyT(playOrder[i],move);
                  notifyG(move); //Game will set the active player
                  alreadyroll = true;
               }
            }//roll if
          }
	

            if(command == "next"){
               if(alreadyroll){
                  alreadyroll = false;
                  next();
                  break;
               }
               else{
                  cout << "It is your turn!" << endl;
               }
            }// next if
          
            if(command == "quit"){
               cout << "Game Ends!" << endl;
               return;
            }

            if(command == "assets"){
               assets();
            }//assets if

            if(command == "save"){
               string filename;
               cin >> filename;
               save(filename);
            }// save if

            if(command == "bankrupt"){
               cout << "Cannot declare bankrupcy at this time!" << endl;
            }// bankrupt if

            if(command == "mortgage"){
               string property;
               cin >> property;
               mortgage(property); 
            }//mortgage if

            if(command == "unmortgage"){
               string property;
               cin >> property;
               unmortgage(property);
            }//unmortgage if

            if(command == "improve"){
               string property;
               cin >> property;
               string action;
               cin >> action;
               if(action == "buy"){
                  improvebuy(property);
                  td->printImprove(cout,game->search(property),"buy");
                  td->printBoard(cout);
               }else{
                  improvesell(property);
                  td->printImprove(cout,game->search(property),"sell");
                  td->printBoard(cout);
               }
            }//improve if

            if(command == "trade"){
               string target;
               cin >> target;

               string give;
               cin>>give;
               stringstream ss(give);
               int amount;
               if(ss >> amount){
                  string property;
                  cin >> property;
                  trade1(target, amount, property);
               }else{//give is a building
                  string exchange;
                  cin>>exchange;
                  stringstream ss(exchange);
                  int amount;
                  if(ss >> amount){
                     trade3(target, give, amount); 
                  }else{
                     trade2(target, give, exchange); 
                  }

               }
            }// trade if

         }//while
      if(i == totalPlayer-1){
         i = -1;
         continue;
      }

      }//for

   }//while
}






















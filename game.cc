#include "game.h"
#include "building.h"
#include "controller.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
void Game::setTotalP(int total){
	totalPlayer=total;
}
Game::Game(Controller *c){
	playerInx=0;
        totalRCup=0;//cannot excess 4
        this->c=c;
	actBuilding=0;

	board=new Building *[40];
	Building  *cif = new Gym(NULL,this,"CIF", 150);
	board[28] = cif;
	Building *pac = new Gym(NULL,this,"PAC", 150);
	board[12] = pac;

        Building *mkv=new Residence(NULL,this,"MKV",200);
	board[5] = mkv;
	Building *uwp=new Residence(NULL,this,"UWP",200);
	board[15]=uwp;
	Building *v1=new Residence(NULL,this,"V1",200);
	board[25]=v1;
	Building *rev=new Residence(NULL,this,"REV",200);
	board[35]=rev;

	Building *al=new Academic(NULL,this,"AL","Arts1",40,50,2,10,30,90,160,250);
	board[1]=al;
	Building *ml=new Academic(NULL,this,"ML","Arts1",60,50,4,20,60,180,320,450);
	board[3]=ml;

	Building *ech=new Academic(NULL,this,"ECH","Arts2",100,50,6,30,90,270,400,550);
	board[6]=ech;
	Building *pas=new Academic(NULL,this,"PAS","Arts2",100,50,6,30,90,270,400,550);
	board[8]=pas;
	Building *hh=new Academic(NULL,this,"HH","Arts2",120,50,8,40,100,300,450,600);
	board[9]=hh;

	Building *rch=new Academic(NULL,this,"RCH","Eng",140,100,10,50,150,450,625,750);
	board[11]=rch;
	Building *dwe=new Academic(NULL,this,"DWE","Eng",140,100,10,50,150,450,625,750);
	board[13]=dwe;
	Building *cph=new Academic(NULL,this,"CPH","Eng",160,100,12,60,180,500,700,900);
	board[14]=cph;

	Building *lhi=new Academic(NULL,this,"LHI","Health",180,100,14,70,200,550,750,950);
	board[16]=lhi;
	Building *bwh=new Academic(NULL,this,"BWH","Health",180,100,14,70,200,550,750,950);
	board[18]=bwh;
	Building *opt=new Academic(NULL,this,"OPT","Health",200,100,16,80,220,600,800,1000);
	board[19]=opt;

	Building *ev1=new Academic(NULL,this,"EV1","Env",220,150,18,90,250,700,870,1050);
	board[21]=ev1;
	Building *ev2=new Academic(NULL,this,"EV2","Env",220,150,18,90,250,700,870,1050);
	board[23]=ev2;
	Building *ev3=new Academic(NULL,this,"EV3","Env",240,150,20,100,300,750,920,1100);
	board[24]=ev3;

	Building *phys=new Academic(NULL,this,"PHYS","Sci1",260,150,22,110,330,800,975,1150);
	board[26]=phys;
	Building *b1=new Academic(NULL,this,"B1","Sci1",260,150,22,110,330,800,975,1150);
	board[27]=b1;
	Building *b2=new Academic(NULL,this,"B2","Sci1",280,150,24,120,360,850,1025,1200);
	board[29]=b2;

	Building *eit=new Academic(NULL,this,"EIT","Sci2",300,200,26,130,390,900,1100,1275);
	board[31]=eit;
	Building *esc=new Academic(NULL,this,"ESC","Sci2",300,200,26,130,390,900,1100,1275);
	board[32]=esc;
	Building *c2=new Academic(NULL,this,"C2","Sci2",320,200,28,150,450,1000,1200,1400);
	board[34]=c2;

	Building *mc=new Academic(NULL,this,"MC","Math",350,200,35,175,500,1100,1300,1500);
	board[37]=mc;
	Building *dc=new Academic(NULL,this,"DC","Math",400,200,50,200,600,1400,1700,2000);
	board[39]=dc;

	Building *slc1=new SLC(this,"SLC");
	board[2]=slc1;
	Building *slc2=new SLC(this,"SLC");
	board[17]=slc2;
	Building *slc3=new SLC(this,"SLC");
	board[33]=slc3;

	Building *tuition=new MoneyCollect(this,300,"TUITION"); //SPECIALLY CARE 10% BALANCE
	board[4]=tuition;
	Building *coopF=new MoneyCollect(this,150,"COOP FEE");
	board[38]=coopF;
	Building *osap=new MoneyCollect(this,-200,"OSAP");
	board[0]=osap;

	Building *needlesH1=new NeedlesHall(this,"NEEDLES HALL");
	board[7]=needlesH1;
	Building *needlesH2=new NeedlesHall(this,"NEEDLES HALL");
	board[22]=needlesH2;
	Building *needlesH3=new NeedlesHall(this,"NEEDLES HALL");
	board[36]=needlesH3;

	Building *timsL=new TimsLine(this,"DC Tims Line");
	board[10]=timsL;

	Building *gooseN=new GooseNesting(this, "Goose Nesting");
	board[20]=gooseN;

	Building *gotoT=new GoToTims(this,"GO TO TIMS");
	board[30]=gotoT;

	blocks =new map<string, int *>;
	int *arts1=new int[2];
	int *arts2=new int[3];
	int *eng=new int[3];
	int *health=new int[3];
	int *env=new int[3];
	int *sci1=new int[3];
	int *sci2=new int[3];
	int *math=new int[2];
	int *gym=new int[2];
	int *res=new int[4];

	arts1[0] = 1;
	arts1[1] = 3;
	arts2[0] = 6;
	arts2[1] = 8;
	arts2[2] = 9;
	eng[0] = 11;
	eng[1] = 13;
	eng[2] = 14;
	health[0] = 16;
	health[1] = 18;
	health[2] = 19;
	env[0] = 21;
	env[1] = 23;
	env[2] = 24;
	sci1[0] = 26;
	sci1[1] = 27;
	sci1[2] = 29;
	sci2[0] = 31;
	sci2[1] = 32;
	sci2[2] = 34;
	math[0] = 37;
	math[1] = 39;
	gym[0] = 12;
	gym[1] = 28;
	res[0] = 5;
	res[1] = 15;
	res[2] = 25;
	res[3] = 35;

	(*blocks)["Arts1"]=arts1;
	(*blocks)["Arts2"]=arts2;
	(*blocks)["Eng"]=eng;
	(*blocks)["Health"]=health;
	(*blocks)["Env"]=env;
	(*blocks)["Sci1"]=sci1;
	(*blocks)["Sci2"]=sci2;
	(*blocks)["Math"]=math;
	(*blocks)["Gym"]=gym;
	(*blocks)["Res"]=res;

}

Game::~Game(){
	for(int i = 0; i < 40; i++){
		delete board[i];
	}
	delete [] board;

	for(int i = 0; i < totalPlayer; i++){
		delete players[i];
	}
	delete [] players;
	for(map<string,int*>::iterator it=(*blocks).begin();it!=(*blocks).end();it++){
		delete [] it->second;
	}
	delete blocks;
}

void Game::notifyP(int move){
	actPlayer->notifiedG(move);

}


void Game::notifyC(){
	c->buy(); 
	
}

void Game::notifiedC(int move){
	notifyP(move);
	
}


void Game::notifiedP(int curposition, int move){
    actBuilding=curposition;
    if(!actPlayer->getSent()) cout << actPlayer->getName() << " arrives at " << board[actBuilding]->getName() << endl;
	int blockbuilding = 0;
	string blockname = board[actBuilding]->getBlockName();
	Player *owner = board[actBuilding]->getOwner();

	if(actPlayer->getPassed()){
		cout<<"You have passed over OSAP"<<endl;
		actPlayer->modifyBalance(200);
		actPlayer->setPassed(false);
	}

	//total building in the block
	int totalbb = 0;
	if(board[actBuilding]->getBlockName()=="Arts1"||board[actBuilding]->getBlockName()=="Math"||board[actBuilding]->getBlockName()=="Gym"){
		totalbb=2;
	}else if(board[actBuilding]->getBlockName()=="Res"){
		totalbb=4;
	}else if(board[actBuilding]->getBlockName()!="Other"){
		totalbb=3;
	}	
	
	for(int i = 0; i < totalbb; i++){
		if(board[(*blocks)[board[actBuilding]->getBlockName()][i]]->getOwner() == owner){
			blockbuilding++;
		}
	}

	if(owner != NULL && owner != actPlayer){

		board[actBuilding]->notifiedG(blockbuilding, move); //pay rent/tuition
	}else if(owner == NULL){
		Ownable *o=dynamic_cast<Ownable *>(board[actBuilding]);
		if(o!=NULL) {notifyC();//give player the option to buy
		}
		else{
			if(actBuilding == 30){
				//Go to Tims
				c->modifyBoard(actPlayer->getSymbol());
				cout<<"You've sent to DC Tims Line."<<endl;
				actBuilding = 10;
				cout<<"Max 3 rounds to stay at DC Tims Line."<<endl;
				notifyP(-100);
				

			}else if(actBuilding == 10){
				if(actPlayer->getSent()){
					cout<<actPlayer->getStay()<<" rounds stayed at DC Tims Line."<<endl;

					if(actPlayer->getRimCup()==0){
						cout<<"You don't have any Rim Cups to get out of the line."<<endl;
						cout<<"To get out of here, pay $50(pay) or roll doubles(roll)"<<endl;
						string s;
						cin>>s;
						if(s=="pay"){
							actPlayer->modifyBalance(-50);
							actPlayer->setSent(false);
							actPlayer->setStay(0);
							cout<<"You are ready to go!"<<endl;
						}else if(s=="roll"){
							srand(time(0));
							int die1=rand()%5+1;
							int die2=rand()%5+1;
							cout<<"You rolled "<<die1<<" and "<<die2<<endl;
							if(die1==die2){
								actPlayer->setSent(false);
								actPlayer->setStay(0);
								cout<<"Lucky! You are ready to go!"<<endl;
							}else{
								if(actPlayer->getStay()==2){
									cout<<"You have already stayed for 2 rounds"<<endl;
									cout<<"Have to pay $50 to leave."<<endl;
									actPlayer->modifyBalance(-50);
									actPlayer->setSent(false);
									actPlayer->setStay(0);
									cout<<"You are ready to go!"<<endl;
								}else cout<<"Ahh! Try again next time."<<endl;

								actPlayer->setStay(actPlayer->getStay()+1);
							}
						}
					}else{
						cout<<"You have Rim Cup(s) to get out of the line!"<<endl;
						cout<<"To get out of here, use a rim cup(rim) or pay $50(pay) or roll doubles(roll)"<<endl;
						string s;
						cin>>s;
						if(s=="pay"){
							actPlayer->modifyBalance(-50);
							actPlayer->setSent(false);
							actPlayer->setStay(0);
							cout<<"You are ready to go!"<<endl;
						}else if(s=="roll"){
							srand(time(0));
							int die1=rand()%5+1;
							int die2=rand()%5+1;
							cout<<"You rolled "<<die1<<" and "<<die2<<endl;
							if(die1==die2){
								actPlayer->setSent(false);
								actPlayer->setStay(0);
								cout<<"Lucky! You are ready to go!"<<endl;
							}else{
								if(actPlayer->getStay()==2){
									cout<<"You have already stayed for 2 rounds"<<endl;
									cout<<"You have to leave here, use a rim cup(rim) or pay $50(pay)"<<endl;
									cin>>s;
									if(s=="pay"){
										actPlayer->modifyBalance(-50);
										actPlayer->setSent(false);
										actPlayer->setStay(0);
										cout<<"You are ready to go!"<<endl;
									}else if(s=="rim"){
										actPlayer->modifyRC(-1);
										cout<<"Rolled up a Rim Cup."<<endl;
										actPlayer->setSent(false);
										actPlayer->setStay(0);
										totalRCup--;
										cout<<"You are ready to go!"<<endl;
									}
								}else cout<<"Ahh! Try again next time."<<endl;

								actPlayer->setStay(actPlayer->getStay()+1);
							}
						}else if(s=="rim") {
							actPlayer->modifyRC(-1);
							cout<<"Rolled up a Rim Cup."<<endl;
							actPlayer->setSent(false);
							actPlayer->setStay(0);
							totalRCup--;
							cout<<"You are ready to go!"<<endl;

						}
					}
			
				}
			}else if(actBuilding == 20){
				//Goose Nesting
				cout << "You are attacted by geese!" << endl;
			}else if(actBuilding == 4){
				//tuition
				cout<<"You must pay tuition, pay $300(enter \"1\") or 10 percent of your balance(enter \"2\")"<<endl;
				int choice;
				cin>>choice;
				if(choice==1) {
					bankrupt(actPlayer, actPlayer->modifyBalance(-300));
								
				
				}else if(choice==2) {bankrupt(actPlayer, actPlayer->modifyBalance(-0.1*actPlayer->getBalance()));
			
				}
					 
			}else{
				MoneyCollect *m=dynamic_cast<MoneyCollect *>(board[actBuilding]);
				if(m!=NULL) board[actBuilding]->notifiedG(blockbuilding, move);
				else{
					SLC *s=dynamic_cast<SLC *>(board[actBuilding]);
					if(s!=NULL){
						int event=s->eventGenerate();
						if(event==-4){
							actBuilding=30;
						}else if(event==4){
							c->notifyT(players[playerInx-1]->getSymbol(),-curposition);
							cout<<"You are advanced to Collect OSAP"<<endl;
						    actBuilding=0;
						    notifyP(-curposition);
						}else if(event==0){
							if(totalRCup<4){
								cout<<"Congraduation, You got a Rim Cup at SLC!"<<endl;
								actPlayer->modifyRC(1);
								totalRCup++;
							}else{
									cout<<"Too much Rim Cups existed, this one is destoryed."<<endl;
								}
						}else{
							cout<<"You are moved "<<event<< " steps from SLC"<<endl;
							if((playerInx-1)==-1) c->notifyT(players[totalPlayer-1]->getSymbol(),event);
							else c->notifyT(players[playerInx-1]->getSymbol(),event);
							notifyP(event);
						}
					}else{
						NeedlesHall *n=dynamic_cast<NeedlesHall *>(board[actBuilding]);
						if(n!=NULL){
							int event=n->eventGenerate();
							if(event==0){
								cout<<"Generated a Rim Cup at Needles Hall."<<endl;
								if(totalRCup<4){ 
									cout<<"Congraduation, You got a Rim Cup at Needles Hall!"<<endl;
									actPlayer->modifyRC(1);
									totalRCup++;
								}else{
									cout<<"Too much Rim Cups existed, this one is destoryed."<<endl;
								}
							}else{
								cout << "Community chest card generated!" << endl;
								bankrupt(actPlayer, actPlayer->modifyBalance(event));
										
								
							}
						}
					}
				}
			}
	
		}
	}
}	


void Game::notifiedCAct(string action){
		if(action == "buy"){
			buy();
		}else{
			auction(actBuilding, "self", -1);
						

		}
}

void Game::notifiedB(int charge){
	bankrupt(actPlayer, actPlayer->modifyBalance(-charge));
		Ownable *o=dynamic_cast<Ownable *>(board[actBuilding]);
	if(o!=NULL) bankrupt(board[actBuilding]->getOwner(), board[actBuilding]->getOwner()->modifyBalance(charge));

}

void Game::buy(){
	Ownable *o=dynamic_cast<Ownable *>(board[actBuilding]);
	if(o!=NULL){
	  actPlayer->addOwned(actBuilding);	
	} 
	bankrupt(actPlayer, actPlayer->modifyBalance(-(o->buy(actPlayer))));

	cout << "You have successfully purchased this building!" << endl;

	int totalbb = 0;
	if(board[actBuilding]->getBlockName()=="Arts1"||board[actBuilding]->getBlockName()=="Math"||board[actBuilding]->getBlockName()=="Gym"){
		totalbb=2;
	}else if(board[actBuilding]->getBlockName()=="Res"){
		totalbb=4;
	}else if(board[actBuilding]->getBlockName()!="Other"){
		totalbb=3;
	}	
	int blockbuilding = 0;
	for(int i = 0; i < totalbb; i++){
		if(board[(*blocks)[board[actBuilding]->getBlockName()][i]]->getOwner() == actPlayer){
			blockbuilding++;
		}
	}

	if(blockbuilding == totalbb){
		cout << "Buildings in " << board[actBuilding]->getBlockName() << " are now qualified to be improved." << endl;
	}

}


void Game::bankrupt(Player *p, bool flag){
	int numBuilding = p->getOwned().size();
	if(numBuilding == 0){
		c->bankrupt(p->getSymbol(), flag, false);
	}else{
		c->bankrupt(p->getSymbol(), flag, true);
	}
				

}

void Game::improvebuy(string property){
	//total building in the block
	int totalbb = 0;
	int b = search(property);
	if(board[b]->getBlockName()=="Arts1"||board[b]->getBlockName()=="Math"||board[b]->getBlockName()=="Gym"){
		totalbb=2;
	}else if(board[b]->getBlockName()=="Res"){
		totalbb=4;
	}else if(board[b]->getBlockName()!="Other"){
		totalbb=3;
	}	
	int blockbuilding = 0;
	for(int i = 0; i < totalbb; i++){
		if(board[(*blocks)[board[b]->getBlockName()][i]]->getOwner() == actPlayer){
			blockbuilding++;
		}
	}

	if(blockbuilding == totalbb){
		Academic *o=dynamic_cast<Academic *>(board[b]);
		if(o!=NULL){
		 	bankrupt(actPlayer, actPlayer->modifyBalance(-(o->improve("buy"))));
		 	
		}
		cout << "Improvement on " << property << "has complete!" << endl;
	}else{
		cout << "The building is not quialified to be improved!" << endl;
	}

	
}

void Game::improvesell(string property){
	Academic *o=dynamic_cast<Academic *>(board[search(property)]);
	if(o!=NULL) {
		if(o->getLevel() > 0){
			bankrupt(actPlayer, actPlayer->modifyBalance(o->improve("sell")));
			
		}else{
			cout << "There is no improvement can be sold!" << endl;
		}
	}
}

void Game::next(){
	actPlayer=players[playerInx];
	playerInx++;
	if(playerInx==totalPlayer) playerInx=0;
	for(int i=0; i<deadP.size();i++){
		if(playerInx==deadP[i]) playerInx++;
	}
	
	if(actPlayer->getSent() == true){
		actPlayer->setStay(actPlayer->getStay() + 1);
	}
}

void Game::out(int pInx){
	deadP.push_back(pInx);
	sort(deadP.begin(), deadP.end(), greater<int>());
}

void Game::trade1(std::string target, int amount, std::string property){
	Player *targetPlayer;
	for(int i = 0; i < totalPlayer; i++){
		if(players[i]->getName() == target){
			targetPlayer = players[i];
			break;
		}
	}
	for(int i=0; i<40; i++){
      	if(board[i]->getName()==property){
   			Academic *o=dynamic_cast<Academic *>(board[i]);
   			if(o!=NULL && o->getOwner() == targetPlayer && o->getLevel() == 0){
   				cout << actPlayer->getName() << " is willing to give " << target <<" $" << amount << " in exchange for the " << property << " building" << endl;
				cout << target << ", do you agree to trade? Please enter yes/no." << endl;
   				string action;
				cin >> action;
				if(action == "yes"){
					bankrupt(actPlayer, actPlayer->modifyBalance(-(o->modifyOwner(actPlayer, amount))));
					
   					bankrupt(targetPlayer, targetPlayer->modifyBalance(amount));
   					
   					cout << "Trade complete, you can continue with your round." << endl;
				}else{
					cout << target << " has rejected the trade, you can continue with your round." << endl;
				}			
   			}else{
   				cout << "Invalid action!" << endl;
   			}
   			break;
      	}	
	}

}

void Game::trade3(std::string target, std::string give, int amount){
	Player *targetPlayer;
	for(int i = 0; i < totalPlayer; i++){
		if(players[i]->getName() == target){
			targetPlayer = players[i];
			break;
		}
	}
	for(int i=0; i<40; i++){
      	if(board[i]->getName()==give){
   			Academic *o=dynamic_cast<Academic *>(board[i]);
   			if(o!=NULL && o->getOwner() == actPlayer && o->getLevel() == 0){
   				cout << actPlayer->getName() << " is willing to give " << target <<" " << give << " in exchange for $" << amount << endl;
				cout << target << ", do you agree to trade? Please enter yes/no." << endl;
   				string action;
				cin >> action;
				if(action == "yes"){
					bankrupt(targetPlayer, targetPlayer->modifyBalance(-(o->modifyOwner(actPlayer, amount))));
								
   					bankrupt(actPlayer, actPlayer->modifyBalance(amount));
   								
   					cout << "Trade complete, you can continue with your round." << endl;
				}else{
					cout << target << " has rejected the trade, you can continue with your round." << endl;
				}			
   			}else{
   				cout << "Invalid action!" << endl;
   			}
   			break;
      	}	
	}

}



void Game::trade2(std::string target, std::string give, std::string exchange){
	Player *targetPlayer;
	for(int i = 0; i < totalPlayer; i++){
		if(players[i]->getName() == target){
			targetPlayer = players[i];
			break;
		}
	}
	for(int i=0; i<40; i++){
      	if(board[i]->getName()==exchange){
   			Academic *o=dynamic_cast<Academic *>(board[i]);
   			Academic *o2=dynamic_cast<Academic *>(board[search(give)]);
   			if(o!=NULL && o->getOwner() == targetPlayer && o2->getOwner() == actPlayer && o->getLevel() == 0 && o2->getLevel() == 0){
   				cout << actPlayer->getName() << " is willing to give " << target <<" " << give << " in exchange for " << exchange << endl;
				cout << target << ", do you agree to trade? Please enter yes/no." << endl;
   				string action;
				cin >> action;
				if(action == "yes"){
					
					o2->modifyOwner(targetPlayer, 0);
   					o->modifyOwner(actPlayer, 0);
   					cout << "Trade complete, you can continue with your round." << endl;
				}else{
					cout << target << " has rejected the trade, you can continue with your round." << endl;
				}			
   			}else{
   				cout << "Invalid action!" << endl;
   			}
   			break;
      	}	
	}

}


void Game::assets(){
	actPlayer->assetNum();
    cout << "Owned Buildings:";
	for(int i = 0 ; i < actPlayer->getOwned().size(); i++){
		cout << " ";
		cout << board[actPlayer->getOwned()[i]]->getName();
	}
	cout << endl;
	cout << "Mortgaged Buildings:";
	for(int i = 0 ; i < actPlayer->getMort().size(); i++){
		cout << " ";
		cout << board[actPlayer->getMort()[i]]->getName();
	}
	cout << endl;

}

void Game::setPlayer(Player *p, bool sent, int turns){
	p->setSent(sent);
	p->setStay(turns);
}

void Game::save(std::string filename){
	ofstream fs;
	fs.open(filename.c_str());
	fs<<totalPlayer<<endl;
	int i=playerInx;
	for(int count=0; count<totalPlayer-deadP.size();count++){
		for(int j=0; j<deadP.size();j++){
			if(i==deadP[j]) {
				i++;
				if(i==totalPlayer) i=0;
			}
		}
		fs<<players[i]->getName()<<" ";
		fs<<players[i]->getSymbol()<<" ";
		fs<<players[i]->getRimCup()<<" ";
		fs<<players[i]->getBalance()<<" ";
		fs<<players[i]->getPos();
		if(players[i]->getPos()==10){
			if(players[i]->getSent()){
				fs<<" "<<1<<" ";
				fs<<players[i]->getStay();
			}else{
				fs<<" "<<0;
			}
		}
		fs<<endl;
		i++;
		if(i==totalPlayer) i=0;
	}
	for(int i=0; i<40; i++){
		Ownable *o=dynamic_cast<Ownable *>(board[i]);
		if(o!=NULL){
		fs<<board[i]->getName()<<" ";
		if(board[i]->getOwner()==NULL) fs<<"BANK ";
		else fs<<(board[i]->getOwner())->getName()<<" ";
		Academic *t=dynamic_cast<Academic *>(board[i]);
		if(t!=NULL){
			if(t->getMort()) fs<<-1<<endl;
			else fs<<t->getLevel()<<endl;
		}else{
			fs<<0<<endl;
		}
	}
	}
	fs.close();
	cout<<"Game saved!"<<endl;
}


void Game::auctionWrap(char p){
	
	int inx;
	Player *pl = NULL;
	for(int j = 0; j < totalPlayer; j++){
		if(players[j]->getSymbol() == p){
			pl = players[j];
			inx = j;
			break;
		}
	}
	if(pl->getOwned().size() != 0){
		cout << p << "'s assets are now under auction!" << endl;
		for(int i = 0 ; i < pl->getOwned().size(); i++){
			cout << board[pl->getOwned()[i]]->getName() << " is now on auction!" << endl;
			auction(pl->getOwned()[i], "wrap", inx);
		}
	}

}





void Game::auction(int building, string mode, int inx){
	int curamount;	
	int i;
	int alivenum;
	int woni;
	int total;
	int aliveindex[totalPlayer-deadP.size()];
	if(mode == "self"){
		curamount = 0;	
		i = playerInx-1;
		alivenum = totalPlayer-deadP.size();
		if(i == -1){
			i = alivenum-1;
		}
		
		for(int j = 0; j < totalPlayer; j++){
			aliveindex[j] = 1;
		}
		woni = 10;
		total = totalPlayer-deadP.size();
	}else{
		curamount = 0;
		i = 0;
		alivenum = totalPlayer-1-deadP.size();
		if(i == -1){
			i = alivenum-1;
		}
		for(int j = 0; j < totalPlayer-deadP.size(); j++){
			if(j == inx){
				aliveindex[j] = 0;
			}else{
				aliveindex[j] = 1;
			}
		}
		woni = 10;	
		total = totalPlayer-1-deadP.size();	
	}
	for(i; i < total; i++){
		if(aliveindex[i] == 0) {
			if(i == total - 1) i = -1;
			continue;
		}
		if(alivenum == 1){
			for(int k = 0; k < total; k++){
				if(aliveindex[k] == 1){
					woni = k;
					break;
				}
			}
			cout << players[woni]->getName() << " has won the auction on " << board[building]->getName() << endl;
			Ownable *o=dynamic_cast<Ownable *>(board[building]);
			if(o!=NULL) {
				bankrupt(players[i], players[i]->modifyBalance(-(o->modifyOwner(players[i], curamount))));
				players[i]->addOwned(i);				
			}
			if(players[i]->getBalance() >= 0){
				cout << players[i]->getName() << " has successfully purchased this building." << endl;
				cout << "Auction ends!" << endl;
			}

			break;
			
		}
		cout << players[i]->getName() << ", please enter your bid amount (e.g. 200) or enter \"fold\" to withdraw from the auction." << endl;
		string read;
		cin >> read;
		stringstream ss(read);
		int amount;
		if(ss >> amount){
			if(amount > curamount){
				curamount = amount;
				cout << players[i]->getName() << " has raised the bid to $" << amount << endl;
			}else{
				cout << "You must raise the bid!" << endl;
				i--;

			}
		}else{
			cout << players[i]->getName() << " has withdrown from the auction." << endl;
			alivenum --;
			aliveindex[i] = 0;
		}
		if(i == total - 1) i = -1;


	}
}


void Game::mortgage(string name){
   for(int i=0; i<40; i++){
      if(board[i]->getName()==name){
         Ownable *o=dynamic_cast<Ownable *>(board[i]);//validity check
         if(o!=NULL){
            int pCost=o->mortgage();
            actPlayer->mortgage(i,pCost);
         }
         break;
      }
   }
}


void Game::unmortgage(string name){
   for(int i=0; i<40; i++){
      if(board[i]->getName()==name){
         Ownable *o=dynamic_cast<Ownable *>(board[i]);//validity check
         if(o!=NULL){
            int cost=o->unmortgage();
            actPlayer->unmortgage(i,cost);
         }else cout<<"Cannot unmortgage this building!"<<endl;
         break;
      }
   }
}


void Game::setBuilding(string buildingName, string player, int impro){
   for(int i=0; i<40; i++){
      if(board[i]->getName()==buildingName){
         if(player!="BANK"&&impro!=-1){
            for(int j=0; j<totalPlayer; j++){
               if(player==players[j]->getName()){
               		Ownable *o=dynamic_cast<Ownable *>(board[i]);
                	if(o!=NULL){
                		o->modifyOwner(players[j],0);
                		players[j]->addOwned(i);
                	}
                }
            }
         }else if(impro==-1){
             for(int j=0; j<totalPlayer; j++){
               if(player==players[j]->getName()){
               		Ownable *o=dynamic_cast<Ownable *>(board[i]);
                	if(o!=NULL){
                	 o->modifyOwner(players[j],0);
                	 players[j]->addMort(i);
                	}
                }
            }
         }else{
             Academic *t=dynamic_cast<Academic *>(board[i]);
             if(t!=NULL) t->setImpro(impro);
         }
      }      
   }
   
}

int Game::search(string property){
	for(int i=0; i<40; i++){
      if(board[i]->getName()==property){
      	return i;
      }
  }
}

bool Game::checkSent(char symbol){
	for(int i=0;i<totalPlayer;i++){
		if(players[i]->getSymbol()==symbol) return players[i]->getSent();
	}
	return false;
}








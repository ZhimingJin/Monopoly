#include "player.h"
#include "game.h"
#include <iostream>

using namespace std;

Player::Player(int pos,string name,char symbol,int balance,int rimCup, Game *game)
:curPosition(pos), name(name),symbol(symbol),balance(balance),rimCup(rimCup),game(game){

	sentToDC=false;
	stayTurn=0;
	passedOSAP=false;
};
Player::Player(){};
Player::~Player(){};

int Player::ownedRes(){
	int owned = 0;
	for(int i = 0; i < 40; i++){
		if(ownedBuilding[i] == 5 || ownedBuilding[i] == 15 || ownedBuilding[i] == 25 || ownedBuilding[i] == 35){
			owned++;
		}
	}
	return owned;
}

void Player::notifyG(int move){
	game->notifiedP(curPosition, move);
	//
}

void Player::notifiedG(int move){
	if(move==-100){
		curPosition=10;
		sentToDC=true;
		notifyG(move);
	}else{
		curPosition += move;
		if(curPosition<=39){
			notifyG(move);
		}else{
			curPosition=curPosition-40;
			passedOSAP=true;
			notifyG(move);
        	}
	}
}

bool Player::modifyBalance(int value){
	balance += value;
	if(balance < 0){
		return true;
	}else{
		if(value<0) cout<<name<<" paid $"<<-value<<endl;
		else if(value>0) cout<<name<< " gained $"<<value<<endl;
		return false;
	}
}

string Player::getName(){
	return name;
}

int Player::getBalance(){
	return balance;
}


char Player::getSymbol(){
	return symbol;
}

void Player::addOwned(int building){
   ownedBuilding.push_back(building);
}
void Player::addMort(int building){
   mortgageBuilding.push_back(building);
}
void Player::removeOwned(int building){
   for(int i=0; i<ownedBuilding.size();i++){
      if(ownedBuilding[i]==building){
         ownedBuilding.erase(ownedBuilding.begin()+i);
         break;
      }
   }      
}
void Player::removeMort(int building){
   for(int i=0; i<mortgageBuilding.size();i++){
      if(mortgageBuilding[i]==building){
         mortgageBuilding.erase(mortgageBuilding.begin()+i);
         break;
      }
   }
}

void Player::mortgage(int building,int cost){
   removeOwned(building);
   addMort(building);
   balance=+cost/2.0;
   cout<<"You have successfully mortgaged this building for $"<<cost/2.0<<"!"<<endl;
}
   
void Player::unmortgage(int building, int cost){
   removeMort(building);
   addOwned(building);
   balance=-cost;
   cout<<"You have successfully unmortgaged this building for $"<<cost<<"!"<<endl;
}

void Player::assetNum(){
   cout<<name<<" "<<"symbol: "<<symbol<<endl;
   cout<<"Accout Balance: "<<balance<<endl;
   cout << "Number of Rims Cups: " << rimCup << endl;
}

vector<int> Player::getOwned(){
   return ownedBuilding;
}
vector<int> Player::getMort(){
   return mortgageBuilding;
}

void Player::modifyRC(int action){
   rimCup=+action;
}

bool Player::getSent(){
	return sentToDC;
}

int Player::getStay(){
	return stayTurn;
}
	
void Player::setSent(bool sent){
	sentToDC=sent;;
}
void Player::setStay(int stay){
	stayTurn=stay;
}
int Player::getPos(){
	return curPosition;
}
int Player::getRimCup(){
	return rimCup;
}
bool Player::getPassed(){
	return passedOSAP;
}
void Player::setPassed(bool pass){
	passedOSAP=pass;
}

#include "ownable.h"
#include <iostream>
using namespace std;

Ownable::Ownable(Player *p, Game *g, string name, string blockName, int cost): 
  Building(p, g, name, blockName),purchaseCost(cost), isMorted(false){}

Ownable::~Ownable(){}

int Ownable::buy(Player *p){
   owner=p;
   return purchaseCost;
}

int Ownable::modifyOwner(Player *p, int value){
  owner = p;
  return value;
}

int Ownable::mortgage(){
   if(!isMorted){//validity check
      isMorted=true;
      return purchaseCost;
   }else{
     cout<<"Already mortgaged!"<<endl;
     return 0;
  }
}

int Ownable::unmortgage(){
   if(isMorted){//validity check
      isMorted=false;
      return purchaseCost/2.0+purchaseCost*0.1;
   }else{
     cout<<"You have not mortgaged this building yet!"<<endl;
     return 0;
    }
}
bool Ownable::getMort(){
  return isMorted;
}

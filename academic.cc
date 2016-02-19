#include "academic.h"
#include "game.h"
using namespace std;

Academic::Academic(Player *p, Game *g, string name, string blockName, int pCost, int iCost, int iCharge0,
   int iCharge1,int iCharge2,int iCharge3,int iCharge4,int iCharge5):
   Ownable(p,g,name,blockName, pCost), iCost(iCost), iLevel(0){
      iCharge[0]=iCharge0;
      iCharge[1]=iCharge1;
      iCharge[2]=iCharge2;
      iCharge[3]=iCharge3;
      iCharge[4]=iCharge4;
      iCharge[5]=iCharge5;
   }

Academic::~Academic(){}

int Academic::charge(int move, int blockBuilding){
   if(!isMorted) {
      return iCharge[iLevel];
   }else return 0;
}

void Academic::notifiedG(int blockBuilding, int move){
   notify(charge(move,blockBuilding));
}


void Academic::notify(int value){
   game->notifiedB(value);
}

int Academic::improve(string action){
   if(action=="buy"){ 
      iLevel++;
      return iCost;
   }else{
      iLevel--;
      return iCost/2.0;
   }
}
void Academic::setImpro(int value){
   iLevel=value;
}

int Academic::getLevel(){
   return iLevel;
}


#include "residence.h"
#include "game.h"
using namespace std;

Residence::Residence(Player *p, Game *g, std::string name, int cost):Ownable(p,g,name,"Res",cost){}

Residence::~Residence(){}

int Residence::charge(int move, int blockBuilding){
   if(!isMorted){
      if(blockBuilding==1) return 25;
      else if(blockBuilding==2) return 50;
      else if(blockBuilding==3) return 100;
      else if(blockBuilding==4) return 200;
    }else return 0;
}

void Residence::notify(int value){
   game->notifiedB(value);
}

void Residence::notifiedG(int blockBuilding, int move){
   notify(charge(move,blockBuilding));
}


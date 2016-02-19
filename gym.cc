#include "gym.h"
#include "game.h"
using namespace std;

Gym::Gym(Player *p, Game *g, std::string name, int cost):Ownable(p,g,name,"Gym",cost){}

Gym::~Gym(){}

void Gym::notifiedG(int blockBuilding, int move){
   notify(charge(move,blockBuilding));
}

int Gym::charge(int move, int blockBuilding){
   if(!isMorted){
      if(blockBuilding==1) return 4*move;
      if(blockBuilding==2) return 10*move;
   }else return 0;
}
void Gym::notify(int value){
   game->notifiedB(value);
}



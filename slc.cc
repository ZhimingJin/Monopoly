#include "slc.h"
#include "game.h"
#include <ctime>
#include <cstdlib>
using namespace std;
SLC::SLC(Game *g,string name):
   Building(NULL,g,name,"Other"){
   srand(time(0));
}

SLC::~SLC(){}

int SLC::eventGenerate(){
   random=rand()%2400+1;//99% normal effect(1-2376), 1% rim cup(2377-2400)
   if(random<=297) return -3;
   else if(random<=693) return -2;
   else if(random<=1089) return -1;
   else if(random<=1386) return 1;
   else if(random<=1782) return 2;
   else if(random<=2178) return 3;
   else if(random<=2277) return -4;//go to tims line
   else if(random<=2376) return 4;//advance to collect OSAP
   else if(random<=2400) return 0;//rim cup
}


void SLC::notify(int value){
   game->notifiedB(value);
}
   
void SLC::notifiedG(int blockBuilding, int move){
   notify(eventGenerate());
}

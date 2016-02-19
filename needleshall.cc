#include "needleshall.h"
#include <ctime>
#include <cstdlib>
#include "game.h"
using namespace std;
NeedlesHall::NeedlesHall(Game *g,string name)
:Building(NULL,g,name,"Other"){
   srand(time(0));
}

NeedlesHall::~NeedlesHall(){}

int NeedlesHall::eventGenerate(){
   random=rand()%600+1;//99% normal effect(1-594), 1% rim cup(595-600)
   if(random<=33) return -200;
   else if(random<=99) return -100;
   else if(random<=198) return -50;
   else if(random<=396) return 25;
   else if(random<=495) return 50;
   else if(random<=561) return 100;
   else if(random<=594) return 200;
   else if(random<=600) return 0;//rim cup
}

void NeedlesHall::notify(int value){
   game->notifiedB(value);
}
   
void NeedlesHall::notifiedG(int blockBuilding, int move){
   notify(eventGenerate());
}

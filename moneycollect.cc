#include "moneycollect.h"
#include "game.h"
using namespace std;

MoneyCollect::MoneyCollect(Game *g, int value, string name): Building(NULL,g,name,"Other"), value(value){}

MoneyCollect::~MoneyCollect(){}

void MoneyCollect::notify(int value){
   game->notifiedB(value);
}
void MoneyCollect::notifiedG(int blockBuilding, int move){
   notify(getValue());
}

int MoneyCollect::getValue(){
   return value;
}

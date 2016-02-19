#include "building.h"
#include "game.h"
using namespace std;

Building::Building(Player *p, Game *g, string name, string blockName): 
	owner(p),game(g),name(name), blockName(blockName){}
Building::Building(){}
Building::~Building(){
   delete game;
   delete owner;
}

Player *Building::getOwner(){
   return owner;
}

string Building::getBlockName(){
  return blockName;
}

string Building::getName(){
   return name;
}

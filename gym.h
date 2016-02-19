#ifndef __GYM_H__
#define __GYM_H__
#include "ownable.h"
#include <string>

class Gym: public Ownable{
   public:
   Gym(Player *p, Game *g, std::string name, int cost);
   ~Gym();
   int charge(int move, int blockBuilding);
   void notify(int value);
   void notifiedG(int blockBuilding, int move);
};

#endif

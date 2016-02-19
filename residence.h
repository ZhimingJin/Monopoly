#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include "ownable.h"


class Residence: public Ownable{
   public:
   Residence(Player *p, Game *g, std::string name, int cost);
   ~Residence();
   int charge(int move, int blockBuilding);
   void notify(int value);
   void notifiedG(int blockBuilding, int move);
};

#endif


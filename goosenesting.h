#ifndef __GOOSENESTING_H__
#define __GOOSENESTING_H__
#include "building.h"
#include <string>
class GooseNesting: public Building{
   public:
   GooseNesting(Game *g, std::string name);
   ~GooseNesting();
   void notify(int value);
   void notifiedG(int blockBuilding, int move);
   
};

#endif

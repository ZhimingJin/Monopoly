#ifndef __GOTOTIMS_H__
#define __GOTOTIMS_H__
#include "building.h"
#include <string>
class GoToTims: public Building{
   public:
   GoToTims(Game *g, std::string name);
   ~GoToTims();
   void notify(int value);
   void notifiedG(int blockBuilding, int move);
   
};

#endif

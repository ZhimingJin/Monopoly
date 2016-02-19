#ifndef __SLC_H__
#define __SLC_H__
#include "building.h"
#include <string>
class SLC: public Building{
   int random;
public:
        SLC(Game *g, std::string name);
        ~SLC();
	int eventGenerate();
	void notify(int value);
	void notifiedG(int blockBuilding, int move);
};

#endif


#ifndef __NEEDLESHALL_H__
#define __NEEDLESHALL_H__
#include "building.h"

class NeedlesHall: public Building{
   int random;
public:
    NeedlesHall(Game *g, std::string name);
 	~NeedlesHall();
	int eventGenerate();
	void notify(int value);
	void notifiedG(int blockBuilding, int move);
};

#endif

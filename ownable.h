#ifndef __OWNABLE_H__
#define __OWNABLE_H__
#include "player.h"
#include "building.h"
#include <string>

class Ownable: public Building{
protected:
	int purchaseCost;
        bool isMorted;
public:
	Ownable(Player *p, Game *g, std::string name, std::string blockName, int cost);
	virtual ~Ownable();
	virtual int charge(int move, int blockBuilding)=0;
	int modifyOwner(Player *p, int value);
        int buy(Player *p);
        int mortgage();//return purchase cost
        int unmortgage();//return half cost + 10%
        bool getMort();
};

#endif

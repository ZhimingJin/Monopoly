#ifndef __MONEYCOLLECT_H__
#define __MONEYCOLLECT_H__
#include "building.h"
#include <string>
class MoneyCollect: public Building{
	int value;
public:
	int getValue();
        MoneyCollect(Game *g, int value, std::string name);
        ~MoneyCollect();
        void notify(int value);
        void notifiedG(int blockBuilding, int move);
};

#endif

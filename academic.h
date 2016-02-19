#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include "ownable.h"


class Academic: public Ownable{
	int iCost;
        int iCharge[6];
	int iLevel;
public:
	
        Academic(Player *p, Game *g, std::string name,std::string blockName, int pCost, int iCost, int iCharge0,
                int iCharge1, int iCharge2, int iCharge3, int iCharge4, int iCharge5);
        ~Academic();
        int improve(std::string action);
        int charge(int move, int blockBuilding);
        void notify(int value);
        void notifiedG(int blockBuilding, int move);
        void setImpro(int value);
        int getLevel();

};

#endif

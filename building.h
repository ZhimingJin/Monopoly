#ifndef __BUILDING_H__
#define __BUILDING_H__
#include <string>


class Game;
class Player;

class Building{
protected:
	std::string name;
        std::string blockName;
	Game *game;
	Player *owner;
public:
	Building(Player *p, Game *g, std::string name, std::string blcokName);
	Building();
	virtual ~Building();
    Player *getOwner();
    std::string getBlockName();
    std::string getName();
	virtual void notify(int value)=0;
    virtual void notifiedG(int blockBuilding, int move)=0;

};


#endif

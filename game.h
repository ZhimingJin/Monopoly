#ifndef __GAME_H__
#define __GAME_H__
#include "player.h"
#include "gym.h"
#include "residence.h"
#include "moneycollect.h"
#include "ownable.h"
#include "needleshall.h"
#include "goosenesting.h"
#include "academic.h"
#include "gototims.h"
#include "slc.h"
#include "timsline.h"
#include <map>
#include <string>

class Controller;
class Building;

class Game{
    int playerInx;
	Building **board;
	int totalPlayer;
	int actBuilding;
	int totalRCup;
	Controller *c;
	Player *actPlayer;
	std::map<std::string, int *> *blocks;
	std::vector<int> deadP;
public:
	Player **players;
public:
	Game(Controller *c);
	~Game();
	void setTotalP(int total);
	void notifyP(int move); //call Player: pass on the dice result
	void bankrupt(Player *p, bool flag); //call Controller to notify whether the player is bankrupt
	void notifyC(); //call Controller's buy(): the building is satistified to buy
	void notifiedC(int move); //called by Controller: recieve player's dice result
	void notifiedCAct(std::string action); //called by Controller: recieve user's action decision
	void notifiedB(int charge); //called by Building: recieve the required balance modification amount
	void notifiedP(int curposition, int move); //called by Player: recieve player's dice result and current position	
	void buy(); //(notify Building) calls Building's buy	
	void mortgage(std::string name);//given name of the building 
	void unmortgage(std::string name);//given name of the building
	void improvebuy(std::string property); //(notified Controller) called by Controller (notify Building) calls Building's improve
	void improvesell(std::string property); //(notified Controller) called by Controller
	void next();
	void out(int pInx);
	int search(std::string property);
	void setBuilding(std::string buildingName, std::string player, int impro);
	void trade1(std::string target, int amount, std::string property);
	void trade2(std::string target, std::string give, std::string exchange);
	void trade3(std::string target, std::string give, int amout);
	void assets();
	bool checkSent(char symbol);
	void setPlayer(Player *p, bool sent, int turns);//specific use for setting player in a loading mode when player is at DC Tims Line	
    void save(std::string filename);
	void auctionWrap(char p);
	void auction(int building, std::string mode, int inx);

	

};

#endif

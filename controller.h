#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <iostream>
#include <string>
#include <map>
#include <sstream>

class Game;
class TextDisplay;

class Controller{
	Game *game;
	TextDisplay *td;
	std::map<std::string,char> *players;
        char *playOrder;
        int doubletime;
        int totalPlayer;
        int index;
        int alivep;
public:
	Controller();
	~Controller();
	void play(std::string file, std::string mode);
	void notifyG(int move);
	void notifyGAct(std::string action);
	void bankrupt(char p, bool anymoney, bool anybuilding); //called by Game to be notifed whether the player is bankrupt
	void notifyT(char symbol, int move);
	void trade1(std::string target, int amount, std::string property); //call game's trade1
	void trade2(std::string target, std::string give, std::string exchange); //call game's trade2
	void trade3(std::string target, std::string give, int amout); //call game's trade3
	void auctionWrap(char p); // call Game's auctionWrap
	void buy(); //notifiedG: called by Game when the building is satistified to buy
	void mortgage(std::string property); //call Game's mortgage
	void unmortgage(std::string property); //call Game's unmortgage
	int roll();
	int testroll();
	void next();
	void improvebuy(std::string property); //(notifiedG) call game's improvebuy
	void improvesell(std::string property); //(notifiedG) call game's improvesell
	void assets();
	void save(std::string filename); 
	void load(std::ifstream &in);
	void modifyBoard(char c);
	int getAliveP();
};

#endif

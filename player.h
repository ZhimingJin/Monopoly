#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <vector>

class Game;

class Player{
	int curPosition;
	std::string name;
	char symbol;
	int balance;
	std::vector<int> ownedBuilding;
	std::vector<int> mortgageBuilding;
	Game *game;
	int rimCup;
	bool passedOSAP;

	bool sentToDC;//true is the player is sent to DC Tims Line and is currently at DC;
	int stayTurn;//number of turns stayed;
public:
	Player(int pos,std::string name, char symbol,int balance,int rimCup, Game *game);
	Player();
	~Player();
	int ownedRes();
	void notifyG(int move);
	void notifiedG(int move);
	bool modifyBalance(int value);

    void addOwned(int building);
    void removeOwned(int building);
    void addMort(int building);
    void removeMort(int building);
    void mortgage(int building, int cost); //must be owned, purchase cost of the building
    void unmortgage(int building, int cost);
	void modifyRC(int action);//action is either 1 or -1

    void assetNum();
	std::vector<int> getOwned();
  	std::vector<int> getMort();
	int getBalance();
	char getSymbol();
	std::string getName();
	bool getSent();
	int getStay();
	int getPos();
	int getRimCup();
	bool getPassed();
	
	void setSent(bool sent);
	void setStay(int stay);
	void setPassed(bool);
        
        
};

#endif

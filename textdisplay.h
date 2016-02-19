#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <string>
#include <iostream>
#include <map>
#include <string>

class Controller;

class TextDisplay{
	std::string **board;//board[block][row(as in block)][column]
	Controller *c;
        int blockLen;//total len=blockLen*11-10
        int blockWid;//total wid=blockWid*11-10
        std::map<char, int> playerPos;


    bool put(char oldvalue,char newvalue, int currentP, int block, int col);
public:
	TextDisplay(Controller *c, char *players, int totalP);
        ~TextDisplay();
	void notified(char c, int currentP);
	void printBoard(std::ostream &out);//call after move
    void printImprove(std::ostream &out,int building,std::string action);//call after improvement
    void removePlayer(char c);
};

#endif

#include "gototims.h"
using namespace std;
GoToTims::GoToTims(Game *g, string name):
	Building(NULL,g,name,"Other"){}
GoToTims::~GoToTims(){}
void GoToTims::notify(int value){}
void GoToTims::notifiedG(int blockBuilding, int move){}

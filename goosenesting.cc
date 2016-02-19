#include "goosenesting.h"
using namespace std;
GooseNesting::GooseNesting(Game *g,string name):Building(NULL,g,name,"Other"){}
GooseNesting::~GooseNesting(){}
void GooseNesting::notify(int value){}
void GooseNesting::notifiedG(int blockBuilding, int move){}

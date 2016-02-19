#ifndef __TIMSLINE_H__
#define __TIMSLINE_H__
#include "building.h"
#include <string>
class TimsLine: public Building{
public:
        TimsLine(Game *g, std::string name);
        ~TimsLine();
        void notify(int value);
        void notifiedG(int blockBuilding, int move);
};

#endif

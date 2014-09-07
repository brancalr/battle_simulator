#include "fighter.h"
#include <string>
using std::string;

#ifndef BLUEMEN_H_INCLUDED
#define BLUEMEN_H_INCLUDED

namespace BrancaleFighters
{
    class BlueMen : public Fighter
    {
    public:
        BlueMen(string player): Fighter(3, 12, "BlueMan", player){}
        BlueMen(const int& shield, const int& health);
        int attack();
        int defense();
    };
}

#endif // BLUEMEN_H_INCLUDED

#include "fighter.h"
#include <string>
using std::string;

#ifndef GOBLIN_H_INCLUDED
#define GOBLIN_H_INCLUDED

namespace BrancaleFighters
{
    class Goblin : public Fighter
    {
    public:
        Goblin(string player): Fighter(3, 8, "Goblin", player){}
        Goblin(const int& shield, const int& health);
        int attack();
        int defense();
    };
}



#endif // GOBLIN_H_INCLUDED

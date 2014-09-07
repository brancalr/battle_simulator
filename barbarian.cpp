#include "barbarian.h"
#include <cstdlib>
#include <ctime>
#include <string>
using std::string;

namespace BrancaleFighters
{
    Barbarian::Barbarian(const int& shield, const int& health, const string& title, const string& player)
                :Fighter(0, 12, "Barbarian", player){}

    int Barbarian::attack()
    {
        srand(time(NULL));
        int weaponStrike = (rand()%2);
        attackRoll = ((rand()%6)+1)+((rand()%6)+1) + weaponStrike;
        return attackRoll;
    }
    int Barbarian::defense()
    {
        srand(time(NULL));
        defenseRoll = ((rand()%6)+1)+((rand()%6)+1);
        return defenseRoll;
    }

}

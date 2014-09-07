#include "goblin.h"
#include <cstdlib>
#include <ctime>
#include <string>
using std::string;

namespace BrancaleFighters
{
    int Goblin::attack()
    {
        srand(time(NULL));
        int weaponStrike = (rand()%2);
        return ((rand()%6)+1)+((rand()%6)+1) + weaponStrike;

    }
    int Goblin::defense()
    {
        srand(time(NULL));
        return ((rand()%6)+1);

    }

}

#include "chucknorris.h"
#include "barbarian.h"
#include <cstdlib>
#include <ctime>

using namespace BrancaleFighters;

int ChuckNorris::attack()
{
    srand(time(NULL));
    int weaponStrike = (rand()%2);
    attackRoll = (((rand()%6)+1)+((rand()&6)+1) + weaponStrike);
    return attackRoll;
}
int ChuckNorris::defense()
{
    srand(time(NULL));
    defenseRoll = (((rand()%6)+1)+((rand()%6)+1));
    return defenseRoll;
}

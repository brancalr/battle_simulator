#include "bluemen.h"
#include <cstdlib>
#include <ctime>
#include <string>
using std::string;

namespace BrancaleFighters
{
    int BlueMen::attack()
    {
        srand(time(NULL));
        int venom = (rand()%1);
        attackRoll = ((rand()%10)+1)+((rand()%10)+1) + venom;
        return attackRoll;
    }
    int BlueMen::defense()
    {
        srand(time(NULL));
        defenseRoll = (((rand()%6)+1)*3);
        return defenseRoll;
    }
}

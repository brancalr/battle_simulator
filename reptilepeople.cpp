#include "reptilepeople.h"
#include <cstdlib>
#include <ctime>
#include <string>
using std::string;

namespace BrancaleFighters
{
    int ReptilePeople::attack()
    {
        srand(time(NULL));
        int venom = (rand()%1);
        attackRoll = ((rand()%6)+1)+((rand()%6)+1)+((rand()%6)+1) + venom;
        return attackRoll;
    }
    int ReptilePeople::defense()
    {
        srand(time(NULL));
        defenseRoll = ((rand()%6)+1);
        return defenseRoll;
    }
}

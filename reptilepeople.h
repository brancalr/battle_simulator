#include "fighter.h"
#include <string>
using std::string;

#ifndef REPTILEPEOPLE_H_INCLUDED
#define REPTILEPEOPLE_H_INCLUDED

namespace BrancaleFighters
{
    class ReptilePeople : public Fighter
    {
    public:
        ReptilePeople(string player): Fighter(7, 18, "ReptilePerson", player){}
        ReptilePeople(const int& shield, const int& health);
        int attack();
        int defense();
    };
}


#endif // REPTILEPEOPLE_H_INCLUDED

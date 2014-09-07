#include "fighter.h"
#include <string>
using std::string;

#ifndef BARBARIAN_H_INCLUDED
#define BARBARIAN_H_INCLUDED

namespace BrancaleFighters
{
    class Barbarian : public Fighter
    {
    public:
        Barbarian(string player): Fighter(0, 12, "Barbarian", player){}
        Barbarian(const int& shield, const int& health, const string& title, const string& player);
        int attack();
        int defense();
    };
}
#endif // BARBARIAN_H_INCLUDED

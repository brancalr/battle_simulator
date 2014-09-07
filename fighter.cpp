#include "fighter.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;
using std::ostream;

namespace BrancaleFighters
{
    Fighter::Fighter(const int& shield, const int& health, const string& title, const string& player)
                :armor(shield), strength(health), name(title), owner(player)
    {
        //blank
    }
    int Fighter::defense()
    {
        return 0;
    }
    int Fighter::damageCalc(int attackRoll, int defenseRoll)
    {
        int damage;
        damage = (attackRoll-defenseRoll)-armor;
        return damage;
    }
    int Fighter::setStrength(int damage)
    {
        if(damage <= 0)
        {
            return strength;
        }
        else
        {
            strength -= damage;
            return strength;
        }
    }
    int Fighter::getStrength()
    {
        return strength;
    }
    string Fighter::getName()
    {
        return name;
    }
    string Fighter::getOwner()
    {
        return owner;
    }
    int Fighter::healthPotion()
    {
        srand(time(NULL));
        if(strength == 1)
        {
            setStrength(strength+=(rand()%5)+1);
        }
        return strength;
    }
    ostream& operator <<(ostream& out, const Fighter& value)
    {
        return out;
    }
}

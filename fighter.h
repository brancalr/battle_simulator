#include <string>
#include <iostream>

using std::string;
using std::ostream;

#ifndef FIGHTER_H_INCLUDED
#define FIGHTER_H_INCLUDED

namespace BrancaleFighters
{
    class Fighter
    {
    public:
        Fighter(const int& shield, const int& health, const string& title, const string& player);
        virtual int attack()=0;
        virtual int defense();
        virtual int damageCalc(int attack, int defense);
        int healthPotion();
        int setStrength(int damage);
        int getStrength();
        string getName();
        string getOwner();
        friend ostream& operator <<(ostream& out, const Fighter& value);
    protected:
        int armor, strength;
        string name, owner;
        int attackRoll, defenseRoll;
    };
}


#endif // FIGHTER_H_INCLUDED

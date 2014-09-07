#include "barbarian.h"
#include <string>

using std::string;

#ifndef CHUCKNORRIS_H_INCLUDED
#define CHUCKNORRIS_H_INCLUDED

using namespace BrancaleFighters;

class ChuckNorris : public Barbarian
{
public:
    ChuckNorris(string player): Barbarian(10, 20, "Chuck Norris", player){}
    ChuckNorris(const int &shield, const int &health);
    int attack();
    int defense();
};



#endif // CHUCKNORRIS_H_INCLUDED

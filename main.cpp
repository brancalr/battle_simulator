#include "fighter.h"
#include "goblin.h"
#include "barbarian.h"
#include "reptilepeople.h"
#include "bluemen.h"
#include "chucknorris.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::vector;
using std::stack;

void menu();
//menu that allows user to select fighters and then invokes battle sequence
Fighter& battle(BrancaleFighters::Fighter *player1, BrancaleFighters::Fighter *player2);
//takes input of two fighter objects and outputs one winner based on attacks and defenses
int main()
{
    using namespace BrancaleFighters;

    menu();

    return 0;
}

void menu()
{
    using namespace BrancaleFighters;

    int choice1, choice2;
    vector<Fighter*> p1list;
    vector<Fighter*> p2list;
    stack<Fighter*> losers;
    Fighter *p1, *p2;//declare two pointer variables of type Fighter

    cout << "Player 1, select 3 fighters for your team!\n";
    while(p1list.size() < 3)//loop runs until player 1 has selected 3 fighters
    {
    cout << "1. Goblin\n";
    cout << "2. Barbarian\n";
    cout << "3. BlueMan\n";
    cout << "4. ReptilePerson\n";
    cout << "5. ChuckNorris\n";
    cout << "6. Exit\n";
    cin >> choice1;
    while(cin.fail() || choice1 < 1 || choice1 > 5)
        {
            cout << "Invalid Entry\n";
            cin.clear();
            cin.ignore(255, '\n');
            cin >> choice1;
        }
        switch(choice1)
        {
        case 1:{
            Goblin orc("Player 1");//creates object of each derived class, in this case Goblin
            p1 = new Goblin("Player 1");//Fighter pointer variable is assigned to dynamic variable of Goblin object
            p1list.push_back(p1);//adds the goblin fighter object to the end of the vector
            cout << "Player 1 is a Goblin!\n";
            break;
        }
        case 2:{
            Barbarian hulk("Player 1");
            p1 = new Barbarian("Player 1");
            p1list.push_back(p1);
            cout << "Player 1 is a Barbarian!\n";
            break;
        }
        case 3:{
            BlueMen blue("Player 1");
            p1 = new BlueMen("Player 1");
            p1list.push_back(p1);
            cout << "Player 1 is a BlueMan!\n";
            break;
        }
        case 4:{
            ReptilePeople lizard("Player 1");
            p1 = new ReptilePeople("Player 1");
            p1list.push_back(p1);
            cout << "Player 1 is a ReptilePerson!\n";
            break;
        }
        case 5:{
            ChuckNorris chuck("Player 1");
            p1 = new ChuckNorris("Player 1");
            p1list.push_back(p1);
            cout << "Player 1 is Chuck Norris!\n";
            break;
        }
        case 6:{
            cout << "Good Bye";
            exit(1);
            break;
        }
        }
    }

    cout << "\nPlayer 2, select 3 fighters for your team!\n";
    while(p2list.size() < 3)//loop runs until player 2 has selected 3 fighters
    {
    cout << "1. Goblin\n";
    cout << "2. Barbarian\n";
    cout << "3. BlueMan\n";
    cout << "4. ReptilePerson\n";
    cout << "5. ChuckNorris\n";
    cout << "6. Exit\n";
    cin >> choice2;
    while(cin.fail() || choice2 < 1 || choice2 > 5)
        {
            cout << "Invalid Entry\n";
            cin.clear();
            cin.ignore(255, '\n');
            cin >> choice2;
        }
        switch(choice2)
        {
        case 1:{
            Goblin orc("Player 2");
            p2 = new Goblin("Player 2");
            p2list.push_back(p2);
            cout << "Player 2 is a Goblin!\n";
            break;
        }
        case 2:{
            Barbarian hulk("Player 2");
            p2 = new Barbarian("Player 2");
            p2list.push_back(p2);
            cout << "Player 2 is a Barbarian!\n";
            break;
        }
        case 3:{
            BlueMen blue("Player 2");
            p2 = new BlueMen("Player 2");
            p2list.push_back(p2);
            cout << "Player 2 is a BlueMan!\n";
            break;
        }
        case 4:{
            ReptilePeople lizard("Player 2");
            p2 = new ReptilePeople("Player 2");
            p2list.push_back(p2);
            cout << "Player 2 is a ReptilePerson!\n";
            break;
        }
        case 5:{
            ChuckNorris chuck("Player 2");
            p2 = new ChuckNorris("Player 2");
            p2list.push_back(p2);
            cout << "Player 2 is Chuck Norris!\n";
            break;
        }
        case 6:{
            cout << "Good Bye";
            exit(1);
            break;
        }
        }
    }
    while(p1list.size() > 0 && p2list.size() > 0)//loop runs until either player's list is 0
    {
        battle(p1list.front(), p2list.front());//battle invocation with fighters at the front of each vector
        if(p1list.front()->getStrength() <= 0)//if player 1's fighter's health is 0 or less
        {
            p2list.push_back(p2list.front());//adds player 2 fighter to back of team list
            p2list.erase(p2list.begin());//removes the fighter from front since it's now in back
            losers.push(p1list.front());//adds losing fighter to the stack
            p1list.erase(p1list.begin());//removes losing fighter from player's list
        }
        else
        {
            p1list.push_back(p1list.front());
            p1list.erase(p1list.begin());
            losers.push(p2list.front());
            p2list.erase(p2list.begin());
        }
    }
    if(p1list.size() == 1)//one fighter remaining in vector signifies it has won
    {
        cout << "\nPlayer 1 is the winner!\n";
        cout << "The winner of the tournament is " << p1list.front()->getName() << "!\n";
        cout << "The fighter in second place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";//most recent loser added to stack is 2nd place
        losers.pop();//removes top fighter from stack
        cout << "The fighter in third place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";//second most recent loser is 3 rd place
    }                                                                                                                     //displays the player whose team this fighter is on
    if(p2list.size() == 1)
    {
        cout << "\nPlayer 2 is the winner!\n";
        cout << "The winner of the tournament is " << p2list.front()->getName() << "!\n";
        cout << "The fighter in second place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";
        losers.pop();
        cout << "The fighter in third place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";
    }
    if(p1list.size() >= 2)//2 or 3 fighters remaining in same team vector will now battle each other
    {
        while(p1list.size()>1)//loop continues until only one fighter remains
        {
            battle(p1list.front(), p1list.back());//fighters in front and back battle
            if(p1list.front()->getStrength() <= 0)//if fighter in front loses
            {
                losers.push(p1list.front());//loser added to stack
                p1list.erase(p1list.begin());//loser removed from vector
            }
        }
        cout << "\nPlayer 1 is the winner!\n";
        cout << "The winner of the tournament is " << p1list.front()->getName() << "!\n";
        cout << "The fighter in second place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";
        losers.pop();
        cout << "The fighter in third place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";
    }
    if(p2list.size() >= 2)
    {
        while(p2list.size()>1)
        {
            battle(p2list.front(), p2list.back());
            if(p2list.front()->getStrength() <= 0)
            {
                losers.push(p2list.front());
                p2list.erase(p2list.begin());
            }
        }
        cout << "\nPlayer 2 is the winner!\n";
        cout << "The winner of the tournament is " << p2list.front()->getName() << "!\n";
        cout << "The fighter in second place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";
        losers.pop();
        cout << "The fighter in third place is " << losers.top()->getName() << " (" << losers.top()->getOwner() << ")!\n";
    }
    delete p1;
    delete p2;
}
Fighter& battle(BrancaleFighters::Fighter *player1, BrancaleFighters::Fighter *player2)
{
        int dmg1, dmg2;

        do{
        dmg1 = player1->damageCalc(player2->attack(), player1->defense());
        player1->setStrength(dmg1);
        player1->healthPotion();
        dmg2 = player2->damageCalc(player1->attack(), player2->defense());
        player2->setStrength(dmg2);
        player2->healthPotion();
        if(player1->getStrength()<=0)
        {
            return *player2;
        }
        player2->setStrength(player2->damageCalc(player1->attack(), player2->defense()));
        if(player2->getStrength()<=0)
        {
            return *player1;
        }
            }while(player1->getStrength()> 0 || player2->getStrength()> 0);
}


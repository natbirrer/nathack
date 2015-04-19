#include <iostream>
#include <string>
using namespace std;

// Base class for all characters to inherit.
class Character {
    double health;
    string race;

    public:
    
    void setHealth(double h) { health = h; }
    double getHealth() { return health; }
    void setRace(string r) { race = r; }
    string getRace() { return race; }
}

// Main character class.
class MainCharacter {
    string trade;

    public:

    void setTrade(string t) { trade = t; }
    string getTrade() { return trade; }
}

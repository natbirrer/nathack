#include <iostream>
#include <string>
using namespace std;

// Base class for all characters to inherit.
class Character {
    double health;

    public:

    int x;
    int y;
    void setHealth(double h) { health = h; }
    double getHealth() { return health; }
};

// Main character class.
class Player: public Character {
};

#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>
using namespace std;

// Base class for all characters to inherit.
class Character {

public:
    void setPosition(int new_x, int new_y);
    void setDisplay(char displayChar);
    void setHealth(double h) { health = h; }
    double getHealth() { return health; }

private:
    int x;
    int y;
    double health;
    char symbol;

};

// Main character class.
class Player: public Character {
};

#endif

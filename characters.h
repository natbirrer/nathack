#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>
#include "globals.h"
#include <ncurses.h>
using namespace std;

// Base class for all characters to inherit.
class Character {

public:
    Character();
    Character(int start_x, int start_y);
    void draw();
    void setPosition(int new_x, int new_y);
    void setDisplay(char displayChar);
    void setHealth(double h) { health = h; }
    double getHealth() { return health; }
    int getx() { return x; }
    int gety() { return y; }

protected:
    int x;
    int y;
    double health;
    char symbol;

};

// Main character class.
class Player: public Character {
};

#endif

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <ncurses.h>
#include "globals.h"
using namespace std;

// constants (maybe reorganize later/make not global?)
//const int MAP_WIDTH = 80;
//const int MAP_HEIGHT = 20;

// Map fetching and drawing function
void drawMap(string number);

#endif

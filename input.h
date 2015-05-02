#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include "characters.h"
#include "environment.h"
using namespace std;

int process(char event, Player *player, char map[][MAP_WIDTH+1]);
bool isPassable(int mapx, int mapy, char map[][MAP_WIDTH+1]);

#endif

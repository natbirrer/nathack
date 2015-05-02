#include <iostream>
#include <string>
#include "input.h"
using namespace std;

// Define all input characters.
//input inputs[] {
    //{'j', "movement"},
    //{'k', "movement"}
//};

int process(char input, Player *player, char map[][MAP_WIDTH+1]) {

    int dx;
    int dy;

    switch(input) {
        case 'h':
            dx = -1;
            dy = 0;
            break;
        case 'l':
            dx = 1;
            dy = 0;
            break;
        case 'j':
            dx = 0;
            dy = 1;
            break;
        case 'k':
            dx = 0;
            dy = -1;
            break;
        case 'b':
            dx = -1;
            dy = 1;
            break;
        case 'n':
            dx = 1;
            dy = 1;
            break;
        case 'y':
            dx = -1;
            dy = -1;
            break;
        case 'u':
            dx = 1;
            dy = -1;
            break;
        case 'q':
            return 1;
    }
    if(isPassable(player->x+dx, player->y+dy, map)) {
        player->x += dx;
        player->y += dy;
    }
    return 0;
}

bool isPassable(int mapx, int mapy, char map[][MAP_WIDTH+1]) {
    if(mapx < 0 || mapx >= 80 || mapy < 0 || mapy >= 20) return false;
    int tileType = map[mapy][mapx];
    if(tileType == '.') return true;
    else if(tileType == '/') return true;
    else if(tileType == 'o') return true;
    return false;
}

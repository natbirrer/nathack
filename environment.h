#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <string>
#include <fstream>
#include <ncurses.h>
using namespace std;

// constants (maybe reorganize later/make not global?)
const int MAP_WIDTH = 80;
const int MAP_HEIGHT = 20;

// Map fetching and drawing function
void drawMap(string number) {
    // Fetch
    string mapname = "maps/map" + number + ".txt";
    char map[MAP_HEIGHT+1][MAP_WIDTH+1];
    int row = 0;
    ifstream mapstream(mapname);
    while(mapstream.getline(map[row], MAP_WIDTH+1)) {
        ++row;
    }
    
    // Define color pairs for terrain
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    // Draw
    for(int y=0; y<MAP_HEIGHT; y++) {
        for(int x=0; x<MAP_WIDTH; x++) {

            char c = map[y][x];
            switch(c) {
                case '.':
                case 'T':
                    mvaddch(y,x,c | COLOR_PAIR(2));
                    break;
                case 'o':
                    mvaddch(y,x,'.');
                    break;
                case '#':
                    mvaddch(y,x,c);
                    break;
                case '+':
                case '/':
                    mvaddch(y,x,c | COLOR_PAIR(3));
                    break;
            }
        }
    }
}

#endif

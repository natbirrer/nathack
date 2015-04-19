#include <iostream>
#include <string>
#include <fstream>
#include <ncurses.h>
using namespace std;

// Map fetching and drawing function
void drawMap(string number) {
    // Fetch
    string mapname = "maps/map" + number + ".txt";
    char map[21][81];
    int row = 0;
    ifstream mapstream(mapname);
    while(mapstream.getline(map[row], 81)) {
        ++row;
    }
    
    // Draw
    for(int y=0; y<20; y++) {
        for(int x=0; x<80; x++) {
            mvaddch(y, x, map[y][x]);
        }
    }
}

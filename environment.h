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
    
    // Define color pairs for terrain
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    // Draw
    for(int y=0; y<20; y++) {
        for(int x=0; x<80; x++) {

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

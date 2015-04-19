#include <iostream>
#include <cstdlib>
#include "characters.h"
#include "environment.h"
#include <ncurses.h>
using namespace std;

// functions (maybe move to a header at some point)
bool isPassable(int mapx, int mapy, char map[][81]);

// curses boilerplate
bool curses_started = false;

void endCurses() {
    if (curses_started && !isendwin()) endwin();
}

void startCurses() {
    if (curses_started) {
        refresh();
    }
    else {
        initscr();
        cbreak();
        noecho();
        intrflush(stdscr, false);
        keypad(stdscr, true);
        atexit(endCurses);
        curses_started = true;
    }
}

int main(){
    startCurses();
    start_color();
    curs_set(0); // Hide cursor
    
    // Initialize colors
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    // Initialize player and (temporary) start position
    Player player;
    player.x = 3;
    player.y = 10;

    // Read map from file (maybe change this at some point..)
    string mapname = "maps/map1.txt";
    char map[21][81];
    int row = 0;
    ifstream mapstream(mapname);
    while(mapstream.getline(map[row], 81)) {
        ++row;
    }

    // Main game loop
    while(true) {
        drawMap("1");
        
        mvaddch(player.y, player.x, '@' | COLOR_PAIR(1));

        char input = getch();

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
                return 0;
        }
        if(isPassable(player.x+dx, player.y+dy, map)) {
            player.x += dx;
            player.y += dy;
        }
    }
    endCurses();
}

bool isPassable(int mapx, int mapy, char map[][81]) {
    if(mapx < 0 || mapx >= 80 || mapy < 0 || mapy >= 20) return false;
    int tileType = map[mapy][mapx];
    if(tileType == '.') return true;
    else if(tileType == '/') return true;
    else if(tileType == 'o') return true;
    return false;
}

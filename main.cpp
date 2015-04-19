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
    curs_set(0);
    
    // Initialize colors
    init_pair(1, COLOR_GREEN, COLOR_WHITE);

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

        switch(input) {
            case 'h':
                if(isPassable(player.x-1, player.y, map)) player.x--;
                break;
            case 'l':
                if(isPassable(player.x+1, player.y, map)) player.x++;
                break;
            case 'j':
                if(isPassable(player.x, player.y+1, map)) player.y++;
                break;
            case 'k':
                if(isPassable(player.x, player.y-1, map)) player.y--;
                break;
            case 'q':
                return 0;
        }
    }
    endCurses();
}

bool isPassable(int mapx, int mapy, char map[][81]) {
    if(mapx < 0 || mapx >= 80 || mapy < 0 || mapy >= 20) return false;
    int tileType = map[mapy][mapx];
    if(tileType == '.') return true;
    return false;
}

#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "characters.h"
#include "environment.h"
#include "input.h"
using namespace std;

// constants (maybe reorganize later/make not global?)
//const int MAP_WIDTH = 80;
//const int MAP_HEIGHT = 20;

// functions (maybe move to a header at some point)
//bool isPassable(int mapx, int mapy, char map[][MAP_WIDTH+1]);

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
    char map[MAP_HEIGHT+1][MAP_WIDTH+1];
    int row = 0;
    ifstream mapstream(mapname);
    while(mapstream.getline(map[row], MAP_WIDTH+1)) {
        ++row;
    }

    // Main game loop
    while(true) {
        drawMap("1");
        
        mvaddch(player.y, player.x, '@' | COLOR_PAIR(1));

        char input = getch();
        // replace all following code with a function call:
        if (process(input, &player, map)) return 0;

    }
    endCurses();
}


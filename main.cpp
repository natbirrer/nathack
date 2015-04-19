#include <iostream>
#include <cstdlib>
#include "characters.h"
#include "environment.h"
#include <ncurses.h>
using namespace std;

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
    //int playerx = 3, playery = 10;
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
        
        //mvaddch(playery, playerx, '@');
        mvaddch(player.y, player.x, '@');

        char input = getch();

        switch(input) {
            case 'h':
                //playerx--;
                player.x--;
                break;
            case 'l':
                //playerx++;
                player.x++;
                break;
            case 'j':
                //playery++;
                player.y++;
                break;
            case 'k':
                //playery--;
                player.y--;
                break;
            case 'q':
                return 0;
        }
    }
    endCurses();
}

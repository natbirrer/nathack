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
    int playerx = 20, playery = 20;

    while(true) {
        drawMap("1");
        getch();
        break;
        
        mvaddch(playery, playerx+1, '@');

        char input = getch();

        switch(input) {
            case 'h':
                playerx--;
                break;
            case 'l':
                playerx++;
                break;
            case 'j':
                playery++;
                break;
            case 'k':
                playery--;
                break;
        }
    }
    endCurses();
}

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
    getch();
    endCurses();
}

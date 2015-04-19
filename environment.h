#include <iostream>
#include <string>
#include <fstream>
#include <ncurses.h>
using namespace std;

//class Wall {
//};
//class VerticalWall: Wall {
//    public:
//    void draw() { cout << '|'; }
//};
//class HorizontalWall: Wall {
//    public:
//    void draw() { cout << '-'; }
//};
//
//class Floor {
//    public:
//    void draw() { cout << '.'; }
//};
//
//class Door {
//};


void drawMap(string number) {
    string mapname = "maps/map" + number + ".txt";
    char map[21][81];
    int row = 0;
    ifstream mapstream(mapname);
    while(mapstream.getline(map[row], 81)) {
        ++row;
    }
    for(int y=0; y<20; y++) {
        for(int x=0; x<80; x++) {
            mvaddch(y, x, map[y][x]);
        }
    }
}

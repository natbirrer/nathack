#include <iostream>
#include <string>
using namespace std;

class Wall {
};
class VerticalWall: Wall {
    public:
    void draw() { cout << '|'; }
};
class HorizontalWall: Wall {
    public:
    void draw() { cout << '-'; }
};

class Floor {
    public:
    void draw() { cout << '.'; }
};

class Door {
};

void drawRoom() {
    Floor f;
    for(int i=0; i<29; i++) {
        for(int j=0; j<80; j++) {
            f.draw();
        }
    }
}

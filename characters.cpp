// Character class implementations
#include "characters.h"

Character::Character() {
    this->x = 0;
    this->y = 0;
    this->symbol = '&';
    this->health = 10;
}
Character::Character(int start_x, int start_y) {
    this->x = start_x;
    this->y = start_y;
    this->symbol = '&';
    this->health = 10;
}
void Character::draw() {
    mvaddch(this->y, this->x, '@');// | COLOR_PAIR(1));
}
void Character::setPosition(int new_x, int new_y) {
    this->x = new_x;
    this->y = new_y;
}
void Character::setDisplay(char displayChar) {
    this->symbol = displayChar;
}

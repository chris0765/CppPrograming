#include "INIT.h"
#include <ncurses.h>

void init(){
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(8, COLOR_WHITE, COLOR_WHITE); //MAP_BLANK
    init_pair(1, COLOR_WHITE, 8); //MAP_WALL
    init_pair(2, COLOR_WHITE, 16); //MAP_IMMUNE_WALL
    init_pair(3, COLOR_WHITE, 11); //SNAKE_HEAD
    init_pair(4, COLOR_WHITE, COLOR_YELLOW); //SNAKE_BODY
    init_pair(5, COLOR_WHITE, COLOR_GREEN); //GROWTH_ITEM
    init_pair(6, COLOR_WHITE, COLOR_RED); //POISON_ITEM
    init_pair(7, COLOR_WHITE, COLOR_MAGENTA); //GATE
}
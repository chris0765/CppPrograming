#include "INIT.h"
#include <ncurses.h>

void init(){
    initscr();
    noecho(); // 키 입력 보이지 않음
    nodelay(stdscr, TRUE); // 키를 입력 대기한 상태로 다른 코드 실행 가능
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
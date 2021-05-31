#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>

using namespace std;

int main(){

    ifstream fin("map1.txt");
    int row = 0, col;
    int Map[100][100];
    string ins;
    for(int i=0; !fin.eof(); i++){
        fin>>ins;
        row++;
        for(int j=0; j<ins.size(); j++)
            Map[i][j] = int(ins[j]-'0');
    }
    col = ins.size();
    
    initscr();
    start_color();
    init_pair(8, COLOR_WHITE, COLOR_WHITE); //MAP_BLANK
    init_pair(1, COLOR_WHITE, 8); //MAP_WALL
    init_pair(2, COLOR_WHITE, 16); //MAP_IMMUNE_WALL
    init_pair(3, COLOR_WHITE, 11); //SNAKE_HEAD
    init_pair(4, COLOR_WHITE, COLOR_YELLOW); //SNAKE_BODY
    init_pair(5, COLOR_WHITE, COLOR_GREEN); //GROWTH_ITEM
    init_pair(6, COLOR_WHITE, COLOR_RED); //POISON_ITEM
    init_pair(7, COLOR_WHITE, COLOR_MAGENTA); //GATE

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(Map[i][j]==0){
                attron(COLOR_PAIR(8));
                mvprintw(i, j*2, "  ");
                attroff(COLOR_PAIR(8));
            }
            else{
                attron(COLOR_PAIR(Map[i][j]));
                mvprintw(i, j*2, "  ");
                attroff(COLOR_PAIR(Map[i][j]));
            }
        }
    }

    refresh();
    getch();
    endwin();

    return 0;
}
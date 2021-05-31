#include "GameWindow.h"
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

GameWindow::GameWindow(){}

void GameWindow::ReadyToPrintMap(vector<vector<int>> Map, vector<Pos> snake){
    printMap = Map;
    for(int i=1; i<snake.size(); i++)
        printMap[snake[i].getX()][snake[i].getY()] = 4;
    printMap[snake[0].getX()][snake[0].getY()] = 3;
}

void GameWindow::Print(){
    clear();
    for(int i=0; i<printMap.size(); i++){
        for(int j=0; j<printMap[i].size(); j++){
            if(printMap[i][j]==0){
                attron(COLOR_PAIR(8));
                mvprintw(i, j*2, "  ");
                attroff(COLOR_PAIR(8));
            }
            else{
                attron(COLOR_PAIR(printMap[i][j]));
                mvprintw(i, j*2, "  ");
                attroff(COLOR_PAIR(printMap[i][j]));
            }
        }
    }
    refresh();
    usleep(500000);
}

bool GameWindow::isFailed(){
    return Failed;
}
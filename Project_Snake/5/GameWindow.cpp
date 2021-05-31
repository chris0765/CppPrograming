#include "GameWindow.h"
#include <ncurses.h>
#include <unistd.h>

GameWindow::GameWindow(){}

void GameWindow::ReadyToPrintMap(vector<vector<int>> Map, vector<Pos> snake){
    printMap = Map; // 아이템과 게이트가 표시된 맵 데이터
    for(int i=1; i<snake.size(); i++)
        printMap[snake[i].getX()][snake[i].getY()] = 4; // Snake의 몸통 표시
    if(snake[0].getX() != -1 && snake[0].getY() != -1)
        printMap[snake[0].getX()][snake[0].getY()] = 3; // Snake의 머리 표시
}

// 출력
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
}
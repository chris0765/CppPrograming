#include "ScoreWindow.h"

ScoreWindow::ScoreWindow(int stLen, int sty): currLen(stLen), maxLen(stLen){
    ScoreBoard = newwin(9, 20, 1, (sty * 2) + 5);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
    wbkgd(ScoreBoard, COLOR_PAIR(10));
    wborder(ScoreBoard, '@', '@', '@', '@', '@', '@', '@', '@');
}

// 스코어보드 갱신
// 새 맵으로 넘어가면, 스코어보드 역시 초기화된다
void ScoreWindow::setValues(int length, int gt, int pt, int wt){
    currLen = length;
    if(length > maxLen)
        maxLen = length;
    
    growt = gt;
    poisont = pt;
    warpt = wt;
}

void ScoreWindow::Print(){
    wbkgd(ScoreBoard, COLOR_PAIR(10));
    wborder(ScoreBoard, '@', '@', '@', '@', '@', '@', '@', '@');
    wattron(ScoreBoard, COLOR_PAIR(10));
    mvwprintw(ScoreBoard, 2, 2, "Score Board");
    mvwprintw(ScoreBoard, 3, 2, "B: %d / %d", currLen, maxLen); // 현재 길이 / 최대 길이
    mvwprintw(ScoreBoard, 4, 2, "+: %d", growt); // Grow 아이템 획득 횟수
    mvwprintw(ScoreBoard, 5, 2, "-: %d", poisont); // Posion 아이템 획득 횟수
    mvwprintw(ScoreBoard, 6, 2, "G: %d", warpt); // Gate 진입 횟수
    wattroff(ScoreBoard, COLOR_PAIR(10));
    wrefresh(ScoreBoard);
}
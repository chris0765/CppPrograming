#include "MissionWindow.h"

MissionWindow::MissionWindow(int sty){
    MissionBoard = newwin(9, 20, 12, (sty * 2) + 5);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
    wbkgd(MissionBoard, COLOR_PAIR(10));
    wborder(MissionBoard, '@', '@', '@', '@', '@', '@', '@', '@');

    toB = 0;
    toG = 0;
    toP = 0;
    toW = 0;
}

// 레벨에 따른 범위 내에서 랜덤하게 미션 부여
void MissionWindow::setNew(int level){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randB(9+level, 14+level);
    uniform_int_distribution<int> randG(4+level, 8+level);
    uniform_int_distribution<int> randP(1+level, 3+level);
    uniform_int_distribution<int> randW(0+level, 1+level);

    toB = randB(gen);
    toG = randG(gen);
    toP = randP(gen);
    toW = randW(gen);

    clearB = false;
    clearG = false;
    clearP = false;
    clearW = false;
}

void MissionWindow::setValues(int length, int growt, int poisont, int warpt){
    if(length >= toB)
        clearB = true;
    if(growt >= toG)
        clearG = true;
    if(poisont >= toP)
        clearP = true;
    if(warpt >= toW)
        clearW = true;
}

bool MissionWindow::isClear(){
    if(clearB && clearG && clearP && clearW)
        return true;
    return false;
}

void MissionWindow::Print(){
    wbkgd(MissionBoard, COLOR_PAIR(10));
    wborder(MissionBoard, '@', '@', '@', '@', '@', '@', '@', '@'); // 테두리 설정
    wattron(MissionBoard, COLOR_PAIR(10));
    mvwprintw(MissionBoard, 2, 2, "Mission Board");
    mvwprintw(MissionBoard, 3, 2, "B: %d (%c)", toB, (clearB?'v':' ')); // 해당 미션 클리어 시 v자 표시
    mvwprintw(MissionBoard, 4, 2, "+: %d (%c)", toG, (clearG?'v':' '));
    mvwprintw(MissionBoard, 5, 2, "-: %d (%c)", toP, (clearP?'v':' '));
    mvwprintw(MissionBoard, 6, 2, "G: %d (%c)", toW, (clearW?'v':' '));
    wattroff(MissionBoard, COLOR_PAIR(10));
    wrefresh(MissionBoard);
    usleep(500000);
}

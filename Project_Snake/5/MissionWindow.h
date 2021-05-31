#ifndef _MISSIONWINDOW_H_
#define _MISSIONWINDOW_H_

#include <ncurses.h>
#include <unistd.h>
#include <random>

using namespace std;

class MissionWindow{
    int toB; // 목표 길이
    int toG; // 목표 Grow 획득
    int toP; // 목표 Poison 획득
    int toW; // 목표 Gate 통과
    bool clearB; // 클리어 여부 표시
    bool clearG;
    bool clearP;
    bool clearW;
    WINDOW *MissionBoard; // 미션을 표시할 윈도우
public:
    MissionWindow(int sty);
    ~MissionWindow(){}

    void setNew(int level); // 레벨에 따라 미션 부여
    void setValues(int length, int growt, int poisont, int warpt); // 미션보드 갱신
    bool isClear(); // 모든 미션 클리어 여부 확인
    void Print(); // 출력
};

#endif
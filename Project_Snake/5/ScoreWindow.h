#ifndef _SCOREWINDOW_H_
#define _SCOREWINDOW_H_

#include <ncurses.h>

// 스코어를 표시하는 객체
class ScoreWindow{
    int currLen; // 현재 Snake의 길이
    int maxLen; // 최대 Snake의 길이
    int growt; // Grow 아이템 획득 수
    int poisont; // Poison 아이템 획득 수
    int warpt; // Gate 진입 수
    WINDOW *ScoreBoard;
public:
    ScoreWindow(int stLen, int sty); // 시작 Snake 길이와 미션보드 출력 위치
    ~ScoreWindow(){}

    void setValues(int length, int growt, int poisont, int warpt); // 스코어보드 갱신
    void Print(); // 출력
};

#endif
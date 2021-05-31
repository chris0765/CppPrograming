#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include <vector>
#include "Pos.h"

using namespace std;

class GameWindow{
    vector<vector<int>> printMap; // 아이템, 게이트, Snake와 맵을 합쳐둔 데이터
public:
    GameWindow();
    ~GameWindow(){}

    void ReadyToPrintMap(vector<vector<int>> Map, vector<Pos> snake); // 데이터를 합치는 메서드
    void Print(); // 데이터를 출력
};

#endif
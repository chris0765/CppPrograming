#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include <vector>
#include "Pos.h"

using namespace std;

class GameWindow{
    vector<vector<int>> printMap;
    bool Failed = false;
public:
    GameWindow();
    void ReadyToPrintMap(vector<vector<int>> Map, vector<Pos> snake);
    void Print();
    bool isFailed();
};

#endif
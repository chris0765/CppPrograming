#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <ncurses.h>
#include <vector>
#include "Pos.h"
#include "Map.h"

using namespace std;

class Snake{
    vector<Pos> BODY;
    int len;
    char dir;
    int growscore;
    int warpedLen;
    bool isGrow;
    bool isPoison;
    bool isDie;
    bool isWarped;
public:
    Snake(vector<Pos> LoadedBody);
    ~Snake(){};

    Pos head();
    Pos nextHead();
    Pos tail();
    void setDir(char d);
    void shrink();
    bool Died();
    void collisonWith(vector<vector<int>> totalMap);
    void update(vector<vector<int>> totalMap, Pos warpedHead, char nextDir);
    vector<Pos> getBODY();
    int getGrowScore();
    int getWarpedLen();
    char getDirection();
    bool Warp();

};

#endif
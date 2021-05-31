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
    bool isGrow;
    bool isPoison;
    bool isDie;
public:
    Snake(vector<Pos> LoadedBody);
    ~Snake(){};

    Pos head();
    Pos tail();
    void setDir(char d);
    void shrink();
    bool Died();
    void collisonWith(vector<vector<int>> ItemMap);
    void update(vector<vector<int>> ItemMap);
    vector<Pos> getBODY();
};

#endif
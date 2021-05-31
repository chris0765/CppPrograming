#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <ncurses.h>
#include <vector>
#include "Pos.h"

using namespace std;

class Snake{
    vector<Pos> BODY;
    int len;
    char dir;
public:
    Snake(vector<Pos> LoadedBody);
    ~Snake(){};

    Pos head();
    Pos tail();
    void setDir(char d);
    void update();
    vector<Pos> getBODY();
};

#endif
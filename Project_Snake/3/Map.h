#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <fstream>
#include <string>
#include "Pos.h"

using namespace std;

class Map{
    vector<vector<int>> OnlyMap;
    Pos disnakeHead;
    vector<Pos> disnakeBody;
    int row;
    int col;
public:
    Map();
    void LoadMap(string filename);
    vector<Pos> getSnake();
    vector<vector<int>> getMap();
    vector<vector<int>> getItemMap();
    int getRow();
    int getCol();
};

#endif
#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <fstream>
#include <string>
#include "Pos.h"
#include "item_type.h"

using namespace std;

class Map{
    vector<vector<int>> OnlyMap;
    vector<vector<int>> totalMap;
    Pos disnakeHead;
    vector<Pos> disnakeBody;
    int row;
    int col;
public:
    Map();
    void LoadMap(string filename);
    void MakeMap(vector<item_type> Items, vector<Pos> Gates);
    vector<Pos> getSnake();
    vector<vector<int>> getMap();
    vector<vector<int>> getTotalMap();
    int getRow();
    int getCol();
};

#endif
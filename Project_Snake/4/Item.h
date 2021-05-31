#ifndef _ITEM_H_
#define _ITEN_H_

#include <vector>
#include <string>
#include <chrono>
#include <random>
#include "Pos.h"
#include "item_type.h"

using namespace std;

class Item{
    int row;
    int col;
    vector<item_type> items;
    vector<vector<int>> ItemMap;
public:
    Item(int R, int C);
    ~Item(){};

    void makeItem(vector<vector<int>> Map, vector<Pos> BODY, chrono::time_point<chrono::system_clock> gametime);
    void delItem(Pos head);
    vector<item_type> getItem();
};

#endif
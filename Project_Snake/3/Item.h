#ifndef _ITEM_H_
#define _ITEN_H_

#include <vector>
#include <string>
#include <chrono>
#include <random>
#include "Pos.h"

using namespace std;

struct item_type{
    Pos pos;
    int type; // 5 = Growtn_Item, 6 = Poison_Item
    chrono::time_point<chrono::system_clock> droptime;
};

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
    void mapWithItem(vector<vector<int>> OnlyMap);
    vector<vector<int>> getMap();
    vector<item_type> getItem();
};

#endif
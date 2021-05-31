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
    int row; // 아이템을 생성 가능한 세로 범위
    int col; // 아이템을 생성 가능한 가로 범위
    vector<item_type> items; // 아이템 데이터를 저장
public:
    Item(int R, int C);
    ~Item(){};

    void makeItem(vector<vector<int>> Map, vector<Pos> BODY, chrono::time_point<chrono::system_clock> gametime); // 아이템 생성
    void delItem(Pos head); // 아이템 삭제
    vector<item_type> getItem();
};

#endif
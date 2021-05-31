#ifndef _ITEM_TYPE_H_
#define _ITEM_TYPE_H_

#include <chrono>
#include "Pos.h"

using namespace std;

// 아이템의 좌표와 타입(Grow인지 Poison인지)를 저장하는 구조체

struct item_type{
    Pos pos;
    int type; // 5 = Growtn_Item, 6 = Poison_Item
    chrono::time_point<chrono::system_clock> droptime;
};

#endif
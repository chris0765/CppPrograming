#ifndef _ITEM_TYPE_H_
#define _ITEM_TYPE_H_

#include <chrono>
#include "Pos.h"

using namespace std;

struct item_type{
    Pos pos;
    int type; // 5 = Growtn_Item, 6 = Poison_Item
    chrono::time_point<chrono::system_clock> droptime;
};

#endif
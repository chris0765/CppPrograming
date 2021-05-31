#ifndef _GATE_H_
#define _GATE_H_

#include <chrono>
#include <vector>
#include <random>
#include "Pos.h"

using namespace std;

class Gate{
    vector<Pos> gates;
    chrono::time_point<chrono::system_clock> madetime;
    int row;
    int col;
public:
    Gate(int R, int C);
    ~Gate(){};

    bool makeGates(vector<vector<int>> map, int score, chrono::time_point<chrono::system_clock> nowtime, bool isWarped);
    Pos headPath(vector<vector<int>> map, Pos t, char d);
    char dirPath(vector<vector<int>> map, Pos t, char d);
    vector<Pos> getGates();
};

#endif
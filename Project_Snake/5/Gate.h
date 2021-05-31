#ifndef _GATE_H_
#define _GATE_H_

#include <chrono>
#include <vector>
#include <random>
#include "Pos.h"

using namespace std;

class Gate{
    vector<Pos> gates; // 게이트를 저장
    chrono::time_point<chrono::system_clock> madetime; // 게이트가 만들어진 시각 저장
    int row; // 게이트가 생성 가능한 세로 범위
    int col; // 게이트가 생성 가능한 가로 범위
public:
    Gate(int R, int C);
    ~Gate(){};

    bool makeGates(vector<vector<int>> map, int score, chrono::time_point<chrono::system_clock> nowtime, bool isWarped); // 게이트 생성 메서드
    Pos headPath(vector<vector<int>> map, Pos t, char d); // 게이트를 통과할 경우의 머리의 이동 좌표 리턴. 게이트를 통과하지 않는다면 현재의 머리 좌표 그대로 리턴
    char dirPath(vector<vector<int>> map, Pos t, char d); // 게이트를 통과할 경우의 머리의 이동 방향 리턴. 게이트를 통과하지 않는다면 현재의 진행 방향 그대로 리턴
    vector<Pos> getGates(); // 게이트 정보 리턴
};

#endif
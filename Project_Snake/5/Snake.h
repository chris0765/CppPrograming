#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <ncurses.h>
#include <vector>
#include "Pos.h"
#include "Map.h"

using namespace std;

class Snake{
    vector<Pos> BODY; // Snake 데이터
    char dir; // 진행 방향
    int growscore; // Gate를 열기 위한 Grow 아이템 획득 수
    int warpedLen; // 꼬리가 Gate를 전부 통과했는지를 알기 위한 변수(size == warpedLen이면 전부 게이트를 통과한 것)
    bool isGrow; // 이번 틱에 Grow 아이템을 획득했다면 
    bool isPoison; // 이번 틱에 Poison 아이템을 획득했다면
    bool isDie; // 사망 조건 충족 시 True
    bool isWarped; // 이번 틱에 Gate에 진입된 상태라면
    int warptime; // 게이트 진입 횟수
    int growtime; // Grow 아이템 획득 수
    int poisontime; // Poison 아이템 획득 수
public:
    Snake(vector<Pos> LoadedBody);
    ~Snake(){};

    Pos head(); // Snake 머리 좌표 리턴
    Pos nextHead(); // 다음 틱에 머리가 위치해있을 좌표 리턴
    void shrink(); // 가장 뒤의 꼬리 1개를 삭제
    bool Died(); // 사망 조건을 충족하였는지를 리턴
    void collisonWith(vector<vector<int>> totalMap); // 충돌 계산(아이템, 게이트, 벽, 몸통)
    void update(vector<vector<int>> totalMap, Pos warpedHead, char nextDir); // Snake 업데이트
    vector<Pos> getBODY();
    int getGrowScore();
    int getWarpedLen();
    int getLength();
    int warpCount();
    int growCount();
    int poisonCount();
    char getDirection();
    bool Warp();

};

#endif
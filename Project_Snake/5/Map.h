#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include <fstream>
#include <string>
#include "Pos.h"
#include "item_type.h"

using namespace std;

class Map{
    vector<vector<int>> OnlyMap; // 벽과 벽이 아닌 데이터만 저장(0, 1, 2)
    vector<vector<int>> totalMap; // 아이템, 게이트를 포함한 맵 데이터
    Pos disnakeHead; // 맵에서 Snake의 머리 좌표 추출
    vector<Pos> disnakeBody; // 맵에서 Snake의 몸통 좌표들 추출
    int row; // 맵의 세로 크기
    int col; // 맵의 가로 크기
public:
    Map();
    ~Map(){}

    void LoadMap(string filename); // 파일로부터 맵 불러옴
    void MakeMap(vector<item_type> Items, vector<Pos> Gates); // 아이템과 게이트를 포함한 맵 생성
    vector<Pos> getSnake(); // 맵에서 추출된 Snake 데이터 리턴
    vector<vector<int>> getMap(); // 벽만 저장된 맵 데이터 리턴
    vector<vector<int>> getTotalMap(); // 아이템과 게이트가 포함된 맵 데이터 리턴
    int getRow(); // 세로 길이 리턴
    int getCol(); // 가로 길이 리턴
};

#endif
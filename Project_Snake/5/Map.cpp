#include "Map.h"
#include <iostream>

Map::Map(){}

void Map::LoadMap(string filename){
    ifstream fin(filename);
    string ins;
    OnlyMap.clear();
    totalMap.clear();
    disnakeHead = {-1, -1};
    disnakeBody.clear();
    vector<int> tmpv; // 초기화
    row = 0;
    while(!fin.eof()){ // 파일 끝까지 입력받음
        fin>>ins;
        OnlyMap.push_back(tmpv);
        for(int i=0; i<ins.size(); i++){
            // 맵의 해당 위치의 데이터가 Snake라면, 따로 추출하고 0을 저장함
            if(ins[i] == '3'){
                disnakeHead = {row, i};
                OnlyMap[row].push_back(0);
            }
            else if(ins[i] == '4'){
                disnakeBody.push_back({row, i});
                OnlyMap[row].push_back(0);
            }
            else
                OnlyMap[row].push_back(int(ins[i]-'0'));
        }
        row++;
    }
    col = ins.size();
    totalMap = OnlyMap;
}

void Map::MakeMap(vector<item_type> Items, vector<Pos> Gates){
    totalMap = OnlyMap;
    // 아이템 데이터 추가
    for(int i=0; i<Items.size(); i++){
        totalMap[Items[i].pos.getX()][Items[i].pos.getY()] = Items[i].type;
    }
    // 게이트 데이터 추가
    for(int i=0; i<Gates.size(); i++){
        totalMap[Gates[i].getX()][Gates[i].getY()] = 7;
    }
}

vector<vector<int>> Map::getTotalMap(){
    return totalMap;
}

vector<Pos> Map::getSnake(){
    vector<Pos> CompleteSnake;
    CompleteSnake.push_back(disnakeHead);
    for(int i=0; i<disnakeBody.size(); i++){
        CompleteSnake.push_back(disnakeBody[i]);
    }
    return CompleteSnake;
}

vector<vector<int>> Map::getMap(){
    return OnlyMap;
}

int Map::getRow(){
    return row;
}

int Map::getCol(){
    return col;
}
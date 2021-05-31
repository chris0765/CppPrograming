#include "Map.h"

Map::Map(){};

void Map::LoadMap(string filename){
    ifstream fin(filename);
    string ins;
    vector<int> tmpv;
    row = 0;
    while(!fin.eof()){
        fin>>ins;
        OnlyMap.push_back(tmpv);
        for(int i=0; i<ins.size(); i++){
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
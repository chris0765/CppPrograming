#include "Snake.h"
#include <iostream>

Snake::Snake(vector<Pos> LoadedBody){
    dir = 'l';
    BODY = LoadedBody;
    isGrow = false;
    isPoison = false;
    isWarped = false;
    isDie = false;
    growscore = 0;
    warpedLen = 0;
}

Pos Snake::head(){
    return BODY.front();
}

Pos Snake::nextHead(){
    int key = getch();
    switch(key){
        case KEY_LEFT:
            dir = 'l';
            break;
        case KEY_RIGHT:
            dir = 'r';
            break;
        case KEY_UP:
            dir = 'u';
            break;
        case KEY_DOWN:
            dir = 'd';
            break;
    }
    if(dir=='l')
        return {BODY[0].getX(), BODY[0].getY()-1};
    else if(dir=='r')
        return {BODY[0].getX(), BODY[0].getY()+1};
    else if(dir=='u')
        return {BODY[0].getX()-1, BODY[0].getY()};
    else if(dir=='d')
        return {BODY[0].getX()+1, BODY[0].getY()};
    return BODY[0];
}

Pos Snake::tail(){
    return BODY.back();
}

void Snake::setDir(char d){
    dir = d;
}

bool Snake::Died(){
    return isDie;
}

bool Snake::Warp(){
    return isWarped;
}

void Snake::collisonWith(vector<vector<int>> totalMap){
    Pos tmp = head();
    if(totalMap[tmp.getX()][tmp.getY()] == 5)
        isGrow = true;
    else if(totalMap[tmp.getX()][tmp.getY()] == 6)
        isPoison = true;
    else if(totalMap[tmp.getX()][tmp.getY()] != 0)
        isDie = true;
    for(int i=1; i<BODY.size(); i++)
        if(BODY[0].getX() == BODY[i].getX() && BODY[0].getY() == BODY[i].getY()){
            isDie = true;
            break;
        }
}

void Snake::shrink(){
    BODY.erase(BODY.begin() + BODY.size() - 1);
}

vector<Pos> Snake::getBODY(){
    return BODY;
}

void Snake::update(vector<vector<int>> totalMap, Pos tHead, char nextDir){
    if(totalMap[nextHead().getX()][nextHead().getY()] == 7)
        isWarped = true;
    BODY.insert(BODY.begin(), tHead);
    dir = nextDir;
    collisonWith(totalMap);
    if(!isGrow){
        shrink();
    } 
    else{
        growscore++;
        isGrow = false;
    }
    if(isPoison){
        shrink();
        isPoison = false;
    }
    if(isWarped){
        warpedLen++;
        growscore = 0;
        if(warpedLen >= BODY.size()){
            isWarped = false;
            warpedLen = 0;
        }
    }
    if(BODY.size()<3)
        isDie = true;
}

int Snake::getGrowScore(){
    return growscore;
}

int Snake::getWarpedLen(){
    return warpedLen;
}

char Snake::getDirection(){
    return dir;
}
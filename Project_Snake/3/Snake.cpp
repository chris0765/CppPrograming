#include "Snake.h"

Snake::Snake(vector<Pos> LoadedBody){
    dir = 'l';
    len = 3;
    BODY = LoadedBody;
    isGrow = false;
}

Pos Snake::head(){
    return BODY.front();
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

void Snake::collisonWith(vector<vector<int>> ItemMap){
    Pos tmp = head();
    if(ItemMap[tmp.getX()][tmp.getY()] == 5)
        isGrow = true;
    else if(ItemMap[tmp.getX()][tmp.getY()] == 6)
        isPoison = true;
    else if(ItemMap[tmp.getX()][tmp.getY()] != 0)
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

void Snake::update(vector<vector<int>> ItemMap){
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
        BODY.insert(BODY.begin(), {BODY[0].getX(), BODY[0].getY()-1});
    else if(dir=='r')
        BODY.insert(BODY.begin(), {BODY[0].getX(), BODY[0].getY()+1});
    else if(dir=='u')
        BODY.insert(BODY.begin(), {BODY[0].getX()-1, BODY[0].getY()});
    else if(dir=='d')
        BODY.insert(BODY.begin(), {BODY[0].getX()+1, BODY[0].getY()});
    collisonWith(ItemMap);
    if(!isGrow){
        shrink();
    } 
    else{
        isGrow = false;
    }
    if(isPoison){
        shrink();
        isPoison = false;
    }
    if(BODY.size()<3)
        isDie = true;
}
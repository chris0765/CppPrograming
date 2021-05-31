#include "Snake.h"

Snake::Snake(vector<Pos> LoadedBody){
    dir = 'l';
    len = 3;
    BODY = LoadedBody;
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

vector<Pos> Snake::getBODY(){
    return BODY;
}

void Snake::update(){
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
    for(int i=BODY.size()-1; i>0; i--)
        BODY[i] = BODY[i-1];
    if(dir=='l')
        BODY[0] = {BODY[0].getX(), BODY[0].getY()-1};
    else if(dir=='r')
        BODY[0] = {BODY[0].getX(), BODY[0].getY()+1};
    else if(dir=='u')
        BODY[0] = {BODY[0].getX()-1, BODY[0].getY()};
    else if(dir=='d')
        BODY[0] = {BODY[0].getX()+1, BODY[0].getY()};
    
}
#include "Snake.h"

Snake::Snake(vector<Pos> LoadedBody){
    dir = 'l';
    BODY = LoadedBody;
    isGrow = false;
    isPoison = false;
    isWarped = false;
    isDie = false;
    growscore = 0;
    warpedLen = 0;
    warptime = 0;
    growtime = 0;
    poisontime = 0;
}

Pos Snake::head(){
    return BODY.front();
}

Pos Snake::nextHead(){
    int key = getch(); // 키보드 입력을 통해 받아옴 // nodelay 적용
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

bool Snake::Died(){
    return isDie;
}

bool Snake::Warp(){
    return isWarped;
}

void Snake::collisonWith(vector<vector<int>> totalMap){
    Pos tmp = head();
    if(totalMap[tmp.getX()][tmp.getY()] == 5) // Grow 아이템과 충돌시
        isGrow = true;
    else if(totalMap[tmp.getX()][tmp.getY()] == 6) // Poison 아이템과 충돌시
        isPoison = true;
    else if(totalMap[tmp.getX()][tmp.getY()] != 0) // 벽과 충동시
        isDie = true;
    for(int i=1; i<BODY.size(); i++) // 몸과 충돌시
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
    // 머리의 다음 좌표가 게이트일 경우에 게이트 이동을 True로 변경
    if(totalMap[nextHead().getX()][nextHead().getY()] == 7){
        isWarped = true;
        warpedLen = 0;
        warptime++;
    }
    // 머리 이동과 진행방향 갱신
    BODY.insert(BODY.begin(), tHead);
    dir = nextDir;
    collisonWith(totalMap); // 충돌 검사
    if(!isGrow){ // Grow 아이템을 먹지 않았다면 꼬리를 1칸 삭제. 다음 머리 위치를 배열 맨 앞에 삽입했기 때문에 꼭 필요한 과정
        shrink();
    } 
    else{
        growscore++;
        growtime++;
        isGrow = false;
    }
    if(isPoison){ // Poison 아이템을 획득시 꼬리를 1칸 추가로 감소시킴
        shrink();
        poisontime++;
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
    if(BODY.size()<3) // 길이가 3 미만이면 게임 오버
        isDie = true;
}

int Snake::getGrowScore(){
    return growscore;
}

int Snake::getWarpedLen(){
    return warpedLen;
}

int Snake::getLength(){
    return BODY.size();
}

int Snake::warpCount(){
    return warptime;
}

int Snake::growCount(){
    return growtime;
}

int Snake::poisonCount(){
    return poisontime;
}

char Snake::getDirection(){
    return dir;
}
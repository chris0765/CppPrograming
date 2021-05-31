#ifndef _POS_H_
#define _POS_H_

// 좌표를 저장하는 객체
class Pos{
    int x;
    int y;
public:
    Pos(int X, int Y);
    Pos();
    ~Pos(){}
    
    int getX();
    int getY();
};

#endif
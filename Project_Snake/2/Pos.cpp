#include "Pos.h"

Pos::Pos(int X, int Y): x(X), y(Y){}
Pos::Pos(): x(0), y(0){}
int Pos::getX(){
    return x;
}
int Pos::getY(){
    return y;
}
#include<iostream>

using std::cout;

#include "time1.h"

int main(){
    Time t;

    t.setTime(11, 0, 0);
    cout<<"\n\nC++ 수업 시간은 24시간 모드로 ";
    t.printTime24();
    cout<<"\n12시간 모드로는 ";
    t.printTime12();
    return 0;
}
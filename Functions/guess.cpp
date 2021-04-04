#include<iostream>
#include "random.h"

using namespace std;

int main()
{
    int target = RandomInteger(1, 100), guessnum;
    while(true)
    {
        cout<<"숫자를 입력하세요 : ";
        cin>>guessnum;
        if(guessnum == target)
        {
            cout<<"맞았습니다!"<<endl;
            break;
        }
        else if(guessnum<target)
            cout<<"그 수 보다는 큽니다."<<endl;
        else
            cout<<"그 수 보다는 작습니다."<<endl;
    }
    return 0;
}
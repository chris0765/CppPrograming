#include <iostream>

using namespace std;

int cnt;

void moveHanoi(char from, char temp, char to, int n)
{
    if(n==1)
    {
        ++cnt;
        cout<<cnt<<":말뚝"<<from<<"에서 말뚝 "<<to<<"로 원반"<<"1을 이동"<<endl;
    }
    else
    {
        moveHanoi(from, to, temp, n-1);
        ++cnt;
        cout<<cnt<<":말뚝"<<from<<"에서 말뚝 "<<to<<"로 원반"<<n<<"를 이동"<<endl;
        moveHanoi(temp, from, to, n-1);
    }
}

int main()
{
    int n;
    cin>>n;
    moveHanoi('A', 'B', 'C', n);
    return 0;
}
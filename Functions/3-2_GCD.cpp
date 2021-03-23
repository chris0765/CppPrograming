#include <iostream>

using namespace std;

int GCD(int x, int y)
{
    int r;
    while(true)
    {
        r = x%y;
        if(r==0) break;
        x = y;
        y = r;
    }
    return y;
}

int main()
{
    int x, y;
    cin>>x>>y;

    cout<<GCD(x, y)<<endl;
}
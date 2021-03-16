#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    if(a==b&&b==c)
        cout<<1<<endl;
    else if(a*a+b*b==c*c)
        cout<<2<<endl;
    else if(a==b||b==c)
        cout<<3<<endl;
    else if(a+b>c)
        cout<<4<<endl;
    else
        cout<<0<<endl;
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int ax, ay, bx, by, cx, cy, a, b, c;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if((ax-bx)*(by-cy)==(bx-cx)*(ay-by))
    {
        cout<<0<<endl;
        return 0;
    }
    a = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
    b = (bx-cx)*(bx-cx)+(by-cy)*(by-cy);
    c = (cx-ax)*(cx-ax)+(cy-ay)*(cy-ay);
    if((a<=b&&b<=c)||(b<=a&&a<=c))
    {
        if(a+b==c)
            cout<<1<<endl;
        else if(a+b<c)
            cout<<2<<endl;
        else
            cout<<3<<endl;
    }
    else if(a<=b&&c<=b)
    {
        if(a+c==b)
            cout<<1<<endl;
        else if(a+c<b)
            cout<<2<<endl;
        else
            cout<<3<<endl;
    }
    else
    {
        if(b+c==a)
            cout<<1<<endl;
        else if(b+c<a)
            cout<<2<<endl;
        else
            cout<<3<<endl;
    }
}
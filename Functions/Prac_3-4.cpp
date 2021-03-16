#include <iostream>

using namespace std;

int main()
{
    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, commonx, commony;
    cin>>ax1>>ay1>>ax2>>ay2;
    cin>>bx1>>by1>>bx2>>by2;
    if(ax1==ax2)
    {
        commonx = ax1;
        commony = by1;
        if(bx1<commonx&&commonx<bx2&&ay1<commony&&commony<ay2)
            cout<<1<<endl;
        else if(bx=1)
    }
    else
    {
        commonx = bx1;
        commony = ay1;
    }
}
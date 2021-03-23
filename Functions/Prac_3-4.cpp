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
        if(ay1>ay2){
            int tmp = ay1;
            ay1 = ay2;
            ay2 = tmp;
        }
        if(bx1>bx2){
            int tmp = bx1;
            bx1 = bx2;
            bx2 = tmp;
        }
        if(bx1<commonx&&commonx<bx2&&ay1<commony&&commony<ay2)
            cout<<1<<endl;
        else if(bx1==commonx||bx2==commonx||ay1==commony||ay2==commony)
            cout<<2<<endl;
        else
            cout<<0<<endl;
    }
    else
    {
        commonx = bx1;
        commony = ay1;
        if(ax1>ax2){
            int tmp = ax1;
            ax1 = ax2;
            ax2 = tmp;
        }
        if(by1>by2){
            int tmp = by1;
            by1 = by2;
            by2 = tmp;
        }
        if(ax1<commonx&&commonx<ax2&&by1<commony&&commony<by2)
            cout<<1<<endl;
        else if(ax1==commonx||ax2==commonx||by1==commony||by2==commony)
            cout<<2<<endl;
        else
            cout<<0<<endl;
    }
}
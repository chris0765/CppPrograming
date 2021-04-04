#include <iostream>

using namespace std;

int main()
{
    int ax, ay, bx, by, cx, cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    int twoTimesSignedArea = (bx-ax)*(cy-ay) - (cx-ax)*(by-ay);
    if(twoTimesSignedArea>0)
    {
        cout<<twoTimesSignedArea<<" "<<1<<endl;
    }
    else if(twoTimesSignedArea<0)
    {
        cout<<-twoTimesSignedArea<<" "<<-1<<endl;
    }
    else
    {
        cout<<"0 0"<<endl;
    }
    return 0;
}
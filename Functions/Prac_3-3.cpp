#include <iostream>

using namespace std;

int main()
{
    int x1, y1, x2, y2, x, y, xgap, ygap, dist_linear, dist_square;
    cin>>x1>>y1>>x2>>y2;
    cin>>x>>y;
    if(x1<=x&&x<=x2)
        xgap = 0;
    else if(x2<x)
        xgap = x-x2;
    else
        xgap = x1-x;
    if(y1<=y&&y<=y2)
        ygap = 0;
    else if(y2<y)
        ygap = y-y2;
    else
        ygap = y1-y;
    dist_linear = xgap*xgap + ygap*ygap;
    dist_square = xgap + ygap;
    cout<<dist_linear<<" "<<dist_square<<endl;
    return 0;
}
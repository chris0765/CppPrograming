#include <iostream>

using namespace std;

int main(){
    unsigned int n;
    cin>>n;
    int a = n / (256 *256 * 256), b = (n % (256 * 256 * 256)) / (256 * 256), c = (n % ( 256 * 256)) / 256, d = (n % 256);
    int t = a + b + c;
    while(t>255){t-=256;}
    if((255 - t)==d)
        cout<<1<<endl;
    else
        cout<<0<<endl;
    return 0;
}
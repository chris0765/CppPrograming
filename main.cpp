#include <iostream>

using namespace std;

int f1(){
    static int v=1;
    v = v+1;
    return v;
}
static int v = 10000;
int i;

int main(void)
{
    int a,b;
    a=b=100;
    cout<< (a==b) <<endl;
    return 0;
}
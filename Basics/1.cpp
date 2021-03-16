#include <iostream>

using namespace std;

int main(){
    int a, b, sum, diff, ab, times, div, mod, big, same;
    cin>>a>>b;
    sum = a+b;
    diff = a-b;
    ab = (a-b)>0?(a-b):(b-a);
    times = a*b;
    div = a/b;
    mod = a%b;
    big = (a>b)?a:b;
    same = (a==b)?1:0;
    cout<<sum<<" "<<diff<<" "<<ab<<" "<<times<<" "<<div<<" "<<mod<<" "<<big<<" "<<same<<endl;
}
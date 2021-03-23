#include <iostream>

using namespace std;

int main()
{
    int H, W, N;
    cin>>H>>W>>N;
    N--;
    if(N/H+1<10)
        cout<<N%H+1<<0<<N/H+1<<endl;
    else
        cout<<N%H+1<<N/H+1<<endl;
    return 0;
}
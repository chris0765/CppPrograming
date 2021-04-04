#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=2; i<n; i++)
        if(n%i==0)
        {
            cout<<0<<endl;
            return 0;
        }
    cout<<1<<endl;
    return 0;
}
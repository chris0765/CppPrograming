#include <iostream>

using namespace std;

int main()
{
    int cnt = 1, k;
    cin>>k;
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<cnt<<" ";
            cnt++;
        }
        cout<<endl;
    }
}
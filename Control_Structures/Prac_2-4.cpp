#include <iostream>

using namespace std;

int main()
{
    int n, cnt = 1;
    cin>>n;
    for(int i=0; i>=0; i+=cnt)
    {
        if(i==n/2)
            cnt = -1;
        for(int j=0; j<n; j++)
        {
            if((n/2)-i<=j&&j<=(n/2)+i)
                cout<<"+";
            else
                cout<<"*";
        }
        cout<<endl;
    }
}
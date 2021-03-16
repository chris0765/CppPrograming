#include <iostream>

using namespace std;

int main()
{
    int k, cnt = 1;
    cin>>k;
    for(int i=1; i>0; i+=cnt)
    {
        if(i==(k/2+1))
            cnt=-1;
        for(int j=1; j<i; j++)
            cout<<"-";
        for(int j=0; j<k-(2*(i-1)); j++)
        {
            if(j%2==0)
                cout<<"*";
            else
                cout<<"+";
        }
        for(int j=1; j<i; j++)
            cout<<"-";
        cout<<endl;
    }
}
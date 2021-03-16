#include <iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;
    for(int i=1; i<=k; i++){
        if(i==(k/2+1))
        {
            for(int j=0; j<k/2; j++)
            {
                cout<<"+";
            }
            cout<<"O";
            for(int j=0; j<k/2; j++)
            {
                cout<<"+";
            }
            cout<<endl;
            continue;
        }
        for(int j=0; j<k; j++){
            if(j==k-i)
                cout<<"*";
            else if(j==(k/2))
                cout<<"I";
            else
                cout<<".";
        }
        cout<<endl;
    }
}
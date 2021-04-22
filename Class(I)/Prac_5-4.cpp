#include<iostream>

using namespace std;

int main(){
    int r, s, t;
    int A[100][100];
    int B[100][100];
    int C[100][100]={0, };
    cin>>r>>s>>t;
    for(int i=0; i<r; i++)
        for(int j=0; j<s; j++)
            cin>>A[i][j];
    for(int i=0; i<s; i++)
        for(int j=0; j<t; j++)
            cin>>B[i][j];
    for(int i=0; i<r; i++){
        for(int j=0; j<t; j++){
            for(int k=0; k<s; k++)
                C[i][j]+=A[i][k]*B[k][j];
            cout<<C[i][j];
            if(j+1<t)
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
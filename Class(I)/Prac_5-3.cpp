#include<iostream>

using namespace std;

int main(){
    int n, m;
    int A[100][100];
    int B[100][100];
    int C[100][100];

    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>A[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>B[i][j];
            C[i][j]=A[i][j]+B[i][j];
        }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
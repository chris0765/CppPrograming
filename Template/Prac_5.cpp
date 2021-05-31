#include <iostream>

using namespace std;

int mab[49][49];

int main(){
    int n;
    cin>>n;
    int cnt = 1, nowx = 0, nowy = n/2;
    while(cnt<=n*n){
        mab[nowx][nowy] = cnt++;
        int nextx = nowx - 1;
        int nexty = nowy + 1;
        if(nextx<0){
            nextx = n-1;
        }
        if(nexty>=n){
            nexty = 0;
        }
        if(mab[nextx][nexty] != 0){
            nextx = nowx + 1;
            nexty = nowy;
            if(nextx>=n){
                nextx = 0;
            }
        }
        nowx = nextx; nowy = nexty;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mab[i][j]<<" ";
        }
        cout<<endl;
    }
}
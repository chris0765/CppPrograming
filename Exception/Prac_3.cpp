#include <iostream>

using namespace std;

int main(){
    int m, n;
    cin>>m>>n;
    int bm[31], bn[31];
    int weightm = 0, weightn = 0, dist = 0;
    int cnt = 0;
    while(m>0 || n>0){
        bm[cnt] = m%2;
        bn[cnt] = n%2;
        weightm += bm[cnt];
        weightn += bn[cnt];
        if(bm[cnt]!=bn[cnt]) dist++;
        cnt++;
        m/=2;
        n/=2;
    }
    cout<<weightm<<" "<<weightn<<" "<<dist<<endl;
    return 0;
}
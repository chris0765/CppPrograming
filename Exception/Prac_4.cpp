#include <iostream>

using namespace std;

int main(){
    int n, stock[1000], now = 0, have = 0;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>stock[i];
    for(int i=0; i<n; i++){
        int max = -1;
        for(int j=i+1; j<n; j++){
            if(stock[j]>stock[i]&&max<stock[j])
                max = stock[j];
        }
        if(max != -1)
            now += max - stock[i];
    }
    cout<<now<<endl;
    return 0;
}
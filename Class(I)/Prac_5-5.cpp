#include<iostream>

using namespace std;

int main(){
    int check[1000] = {0, };
    int n, tmp=0;
    cin>>n;
    while(n>0){
        tmp+=(n%10)*(n%10);
        n/=10;
    }
    n=tmp;
    while(n!=1&&check[n]==0){
        check[n]=1;
        tmp = 0;
        while(n>0){
            tmp+=(n%10)*(n%10);
            n/=10;
        }
        n=tmp;
    }
    if(n==1)
        cout<<"HAPPY"<<endl;
    else
        cout<<"UNHAPPY"<<endl;
    return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int nA, nB;
    int A[100];
    int B[100];
    int check[101]={0, };
    vector<int> interSec;
    vector<int> unionSec;
    vector<int> compleSec;

    cin>>nA;
    for(int i=0; i<nA; i++){
        cin>>A[i];
        check[A[i]]+=1;
    }
    cin>>nB;
    for(int i=0; i<nB; i++){
        cin>>B[i];
        check[B[i]]+=2;
    }
    for(int i=1; i<=100; i++){
        if(check[i]!=0)
            unionSec.push_back(i);
        if(check[i]==1)
            compleSec.push_back(i);
        else if(check[i]==3)
            interSec.push_back(i);
    }
    cout<<interSec.size();
    for(int i=0; i<interSec.size(); i++)
        cout<<" "<<interSec[i];
    cout<<endl<<unionSec.size();
    for(int i=0; i<unionSec.size(); i++)
        cout<<" "<<unionSec[i];
    cout<<endl<<compleSec.size();
    for(int i=0; i<compleSec.size(); i++)
        cout<<" "<<compleSec[i];
    cout<<endl;
    return 0;
}
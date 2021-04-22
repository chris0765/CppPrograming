#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> twice;
    queue<int> third;
    queue<int> fifth;
    int nownum = 1, k, nowcnt = 1;
    cin>>k;
    twice.push(nownum*2);
    third.push(nownum*3);
    fifth.push(nownum*5);
    for(int i=2; i<=k; i++){
        if(twice.front()<third.front()&&twice.front()<fifth.front()){
            nownum=twice.front();
            twice.pop();
            twice.push(nownum*2);
            third.push(nownum*3);
            fifth.push(nownum*5);
        }
        else if(third.front()<twice.front()&&third.front()<fifth.front()){
            nownum=third.front();
            third.pop();
            third.push(nownum*3);
            fifth.push(nownum*5);
        }
        else{
            nownum=fifth.front();
            fifth.pop();
            fifth.push(nownum*5);
        }
    }
    cout<<nownum<<endl;
    return 0;
}
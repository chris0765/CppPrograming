#include <iostream>
#include <string>

using namespace std;

int main(){
    string bookNum;
    cin>>bookNum;
    int barNum = 0;
    if(bookNum.size()!=13){
        cout<<0<<endl;
        return 0;
    }
    //제대로된 문자사용체크
    for(int i=0; i<bookNum.size(); i++){
        if(!((0<=int(bookNum[i]-'0')&&int(bookNum[i]-'0')<=9)||bookNum[i]=='-')){
            if(!(i==bookNum.size()-1 && bookNum[i] == 'X'))
            {
                cout<<0<<endl;
                return 0;
            }
        }
    }
    //- 개수 체크
    for(int i=0; i<bookNum.size(); i++){
        if(bookNum[i]=='-')
            barNum++;
    }
    if(barNum!=3){
        cout<<0<<endl;
        return 0;
    }
    //구간 4구간인지 체크
    if(bookNum[0]=='-' || bookNum[bookNum.size()-1]=='-'){
        cout<<0<<endl;
        return 0;
    }
    barNum = 0;
    int numCnt = 0;
    for(int i=0; i<bookNum.size(); i++){
        if(bookNum[i]=='-'){
            barNum++;
            if(barNum==1 && numCnt>5){
                cout<<0<<endl;
                return 0;
            }
            if(barNum==2 && numCnt>7){
                cout<<0<<endl;
                return 0;
            }
            if(barNum==3 && numCnt>6){
                cout<<0<<endl;
                return 0;
            }
            if(barNum==3 && i!=bookNum.size()-2){
                cout<<0<<endl;
                return 0;
            }
            if(bookNum[i+1]=='-'){
                cout<<0<<endl;
                return 0;
            }
            numCnt = 0;
        }
        else{
            numCnt++;
        }
    }
    int sum = 0, cnt = 10;
    for(int i=0; i<bookNum.size()-1; i++)
        if(bookNum[i]!='-')
            sum += int(bookNum[i]-'0')*(cnt--);
    int checksum = 0;
    while((sum+checksum)%11!=0){
        checksum++;
    }
    if(0<=checksum&&checksum<10&&int(bookNum[bookNum.size()-1]-'0')!=checksum){
        cout<<0<<endl;
        return 0;
    }
    if(checksum==10 && bookNum[bookNum.size()-1]!='X'){
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
    return 0;
}
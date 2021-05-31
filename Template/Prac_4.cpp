#include <iostream>
#include <string>

using namespace std;

int main(){
    string card;
    cin>>card;
    if(card[0]!='3' && card[0]!='4' && card[0]!='5' && card[0]!='6'){
        cout<<0<<endl;
        return 0;
    }
    if(card[0]=='3' && !(card.size() == 15 || card.size() == 14)){
        cout<<0<<endl;
        return 0;
    }
    if(card[0]=='6' && card.size() != 16){
        cout<<0<<endl;
        return 0;
    }
    if(card[0]=='5' && card.size() != 16){
        cout<<0<<endl;
        return 0;
    }
    if(card[0]=='4' && !(card.size() == 13 || card.size() == 16)){
        cout<<0<<endl;
        return 0;
    }
    int sum = 0, checksum = 0;
    for(int i=card.size()-2; i>=0; i--){
        int tmp = int(card[i]-'0');
        if((card.size()-2-i)%2==1){
            sum += tmp;
        }
        else{
            sum += (((tmp*2)>9)?((tmp*2)-9):(tmp*2));
        }
    }
    checksum = (sum%10==0?0:(10-(sum%10)));
    if(int(card[card.size()-1]-'0')!=checksum){
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
    return 0;
}
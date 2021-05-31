#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string barcode;
    cin>>barcode;
    if(barcode.substr(0, 3) != "101" || barcode.substr(45, 5) != "01010" || barcode.substr(92, 3) != "101"){
        cout<<"*****_*****"<<endl;
        return 0;
    }
    int cnt = 0, lr = 0, sum = 0;
    string code[2][10] = {{"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"}, {"1110010", "1100110", "1101100", "1000010", "1011100", "1001110", "1010000", "1000100", "1001000", "1110100"}};
    string readdir = barcode.substr(3, 7);
    reverse(readdir.begin(), readdir.end());
    for(int i=0; i<10; i++){
        if(code[1][i]==readdir){
            reverse(barcode.begin(), barcode.end());
            break;
        }
    }
    int num[12];
    for(int i=0; i<12; i++){
        num[i] = -1;
    }
    for(int i=0; i<barcode.size(); i+=7){
        if(i==0)
            i+=3;
        if(i==45){
            i+=5;
            lr = 1;
        }
        string sbstr = barcode.substr(i, 7);
        for(int j=0; j<10; j++)
            if(sbstr == code[lr][j])
                num[cnt] = j;
        if(num[cnt++]==-1){
            cout<<"******_******"<<endl;
            return 0;
        }
    }
    for(int i=0; i<12; i++){
        if(i==6){
            cout<<"-";
        }
        cout<<num[i];
    }
    for(int i=0; i<11; i++){
        if(i%2==0){
            sum += num[i] * 3;
        }
        else{
            sum += num[i];
        }
    }
    if(num[11] != (sum%10==0?0:(10-(sum%10)))){
        cout<<"*"<<(sum%10==0?0:(10-(sum%10)));
    }
    cout<<endl;
    return 0;
}
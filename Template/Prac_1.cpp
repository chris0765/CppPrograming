#include <iostream>
#include <string>

using namespace std;

int main(){
    unsigned int k, n;
    string sn;
    cin>>k;
    if(k==1){
        cin>>sn;
        unsigned int sum = 0, tmp = 0, cnt = 3;
        for(int i=0; i<sn.size(); i++){
            if(sn[i]!='.'){
                tmp *= 10;
                tmp += int(sn[i]-'0');
            }
            if(sn[i]=='.' || i==sn.size()-1){
                for(int j=0; j<cnt; j++){
                    tmp *= 256;
                }
                sum += tmp;
                cnt--;
                tmp = 0;
            }
        }
        cout<<sum<<endl;
    }
    else{
        cin>>n;
        int a = n / (256 * 256 * 256), b = (n % (256 * 256 * 256)) / (256 * 256), c = (n % (256 * 256)) / 256, d = n % 256;
        string sum = to_string(a) + '.' + to_string(b) + '.' + to_string(c) + '.' + to_string(d);
        cout<<sum<<endl;
    }
    return 0;
}
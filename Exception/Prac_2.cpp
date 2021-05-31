#include <iostream>

using namespace std;

int main(){
    int k, n;
    cin>>k>>n;
    int b_n[31] = {0, };
    if(k==0){
        int tmpn = n, cnt = 0;
        while(cnt<31){
            if(cnt == 0 || cnt == 1 || cnt == 3 || cnt == 7 || cnt == 15){
                cnt++;
            }
            else{
                b_n[cnt++] = tmpn%2;
                tmpn/=2;
            }
        }
        int sum = 0;
        for(int i=0; i<31; i++)
            if(i%2==0)
                sum+=b_n[i];
        b_n[0] = sum%2;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/2)%2==1)
                sum+=b_n[i];
        b_n[1] = sum%2;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/4)%2==1)
                sum+=b_n[i];
        b_n[3] = sum%2;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/8)%2==1)
                sum+=b_n[i];
        b_n[7] = sum%2;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/16)%2==1)
                sum+=b_n[i];
        b_n[15] = sum%2;
        sum = 0;cnt = 1;
        for(int i=0; i<31; i++){
            sum += b_n[i] * cnt;
            cnt *= 2;
        }
        cout<<sum<<endl;
    }
    else{
        int tmpn = n, cnt = 0;
        while(tmpn>0){
            b_n[cnt++] = tmpn%2;
            tmpn/=2;
        }
        int error = 0;
        int sum = 0;
        for(int i=0; i<31; i++)
            if(i%2==0)
                sum+=b_n[i];
        if(sum%2==1) error += 1;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/2)%2==1)
                sum+=b_n[i];
        if(sum%2==1) error += 2;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/4)%2==1)
                sum+=b_n[i];
        if(sum%2==1) error += 4;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/8)%2==1)
                sum+=b_n[i];
        if(sum%2==1) error += 8;
        sum = 0;
        for(int i=0; i<31; i++)
            if(((i+1)/16)%2==1)
                sum+=b_n[i];
        if(sum%2==1) error += 16;
        if(error != 0) b_n[error-1] = !b_n[error-1];
        sum = cnt = 0;
        int c = 1;
        while(cnt<31){
            if(cnt == 0 || cnt == 1 || cnt == 3 || cnt == 7 || cnt == 15){
                cnt++;
            }
            else{
                sum += b_n[cnt++] * c;
                c *= 2;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
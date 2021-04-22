#include<iostream>

using namespace std;

int main()
{
    int n, k;
    int vac[50];
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>vac[i];
    while(k--)
    {
        int vac_next[50];
        for(int i=0; i<n; i++)
        {
            int left, right;
            left = right = 0;
            if(i!=0)
                left = vac[i-1];
            if(i!=n-1)
                right = vac[i+1];
            int sum = left+right;
            if(sum<3)
                vac_next[i]=(vac[i]>0?vac[i]-1:0);
            else if(sum==3)
                vac_next[i]=vac[i];
            else if(sum<8)
                vac_next[i]=(vac[i]<9?vac[i]+1:9);
            else
                vac_next[i]=(vac[i]>0?vac[i]-1:0);
        }
        for(int i=0; i<n; i++)
            vac[i]=vac_next[i];
    }
    for(int i=0; i<n; i++)
        cout<<vac[i]<<" ";
    cout<<endl;
    return 0;
}
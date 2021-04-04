#include <iostream>

using namespace std;

int main()
{
    int a, b, n, w;
    cin>>a>>b>>n>>w;
    int numA=1, numB=n-numA, numOfAnswer = 0;
    int numx, numy;
    while(numA<n)
    {
        if(a*numA + b*numB == w)
        {
            if(numOfAnswer == 1)
            {
                cout<<-1<<endl;
                return 0;
            }
            numx = numA;
            numy = numB;
            numOfAnswer++;
        }
        numA++;
        numB--;
    }
    if(numOfAnswer==0)
        cout<<-1<<endl;
    else
        cout<<numx<<" "<<numy<<endl;
    return 0;
}
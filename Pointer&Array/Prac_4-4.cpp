#include <iostream>

using namespace std;

int main()
{
    int n, numOfEven = 0;
    unsigned int evenParity = 0;
    cin>>n;
    int copyN = n;
    while(copyN>0)
    {
        if(copyN%2==1)
            numOfEven++;
        copyN/=2;
    }
    if(numOfEven%2==0)
        evenParity = n;
    else
        evenParity = (1<<31) + n;
    cout<<evenParity<<endl;
    return 0;
}
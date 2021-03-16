#include <iostream>

using namespace std;

int Factorial(int n)
{
    int rtn = 1;
    for(int i=2; i<=n; i++)
        rtn *= i;
    return rtn;
}

int Combination(int n, int k)
{
    return Factorial(n)/(Factorial(k)*Factorial(n-k));
}

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<n<<" Combination "<<k<<" is "<<Combination(n, k)<<endl;
}
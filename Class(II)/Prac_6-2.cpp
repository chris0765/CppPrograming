#include <iostream>

using namespace std;

int main()
{
    int n, answer=0;
    int grid[100][100];
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>grid[i][j];
    for(int i=0; i<n; i++)
    {
        int sum=0, sumrev=0;
        for(int j=0; j<n; j++)
        {
            sum+=grid[j][(i+j)%n];
            sumrev+=grid[j][(i-j+n)%n];
        }
        if(answer<sum)
            answer=sum;
        if(answer<sumrev)
            answer=sumrev;
    }
    cout<<answer<<endl;
    return 0;
}
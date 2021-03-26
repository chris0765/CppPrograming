#include <iostream>

using namespace std;

int main()
{
    int len, sum=0;

    cout<<"input the array length : ";
    cin>>len;

    int arr[len];

    for(int i=0; i<len; i++)
    {
        cout<<"input the number : ";
        cin>>arr[i];
        sum+=arr[i];
    }

    double avg = sum / len;
    cout<<"avg : "<<avg<<endl;
    
    return 0;
}
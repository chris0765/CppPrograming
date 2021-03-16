#include <iostream>

using namespace std;

int main(){
    int sum = 0, num = 2;
    cout<<"Using for-loop sum : ";
    for(int i=2; i<=100; i+=2)
    {
        sum+=i;
    }
    cout<<sum<<endl;

    cout<<"Using while-loop sum : ";
    sum = 0;
    while(num<=100)
    {
        sum+=num;
        num+=2;
    }
    cout<<sum<<endl;

    cout<<"Using do-while-loop sum : ";
    sum = 0;
    num = 2;
    do
    {
        sum+=num;
        num+=2;
    } while (num<=100);
    cout<<sum<<endl;
}
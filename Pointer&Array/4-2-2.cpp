#include<iostream>
#include "random.h"

using namespace std;

void sorting(int array[])
{
    for(int i=100; i>0; i--)
        for(int j=1; j<i; j++)
            if(array[j-1]>array[j])
            {
                int tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;
            }
}

int main()
{
    int array[100];
    for(int i=0; i<100; i++)
        array[i] = RandomInteger(1, 10000);
    sorting(array);
    for(int i=0; i<100; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}
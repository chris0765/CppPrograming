#include<iostream>
#include "random.h"

using namespace std;

const int ARRAY_NUM = 100;

void sorting(int *array)
{
    for(int i=ARRAY_NUM; i>0; i--)
        for(int j=1; j<i; j++)
            if(array[j-1]>array[j])
                swap(array[j-1], array[j]);
}

int main()
{
    int array[ARRAY_NUM];
    for(int i=0; i<ARRAY_NUM; i++)
        array[i] = RandomInteger(1, 10000);
    sorting(array);
    for(int i=0; i<ARRAY_NUM; i++)
        cout<<array[i]<<" ";
    cout<<endl;
}
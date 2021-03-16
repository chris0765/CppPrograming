#include <iostream>

using namespace std;

int main()
{
    int year;
    bool isLeapYear;

    cout<<"What year? ";
    cin>>year;

    isLeapYear = ((year%4==0)&&(year%100!=0))||(year%400==0);
    if(isLeapYear)
        cout<<year<<" is a leap year.\n";
    else
        cout<<year<<" is not a leap year.\n";
}
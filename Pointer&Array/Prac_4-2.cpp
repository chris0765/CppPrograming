#include <iostream>

using namespace std;

int main()
{
    int n;
    int x[100], y[100];
    cin>>n;
    int twoTimesSignedArea = 0;
    for(int i=0; i<n; i++)
        cin>>x[i]>>y[i];
    for(int i=0; i<n; i++)
        twoTimesSignedArea += (x[i] + x[(i+1)%n]) * (y[(i+1)%n] - y[i]);
    if(twoTimesSignedArea>0)
        cout<<twoTimesSignedArea<<" "<<1<<endl;
    else
        cout<<-twoTimesSignedArea<<" "<<-1<<endl;
    return 0;
}
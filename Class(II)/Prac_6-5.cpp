#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int cards[10000];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>cards[i];
    }
    sort(cards, cards+n);
    int twice_front = cards[n-1]*cards[n-2];
    int third_front = cards[n-1]*cards[n-2]*cards[n-3];
    int twice_back = cards[0]*cards[1];
    int third_back = cards[0]*cards[1]*cards[n-1];
    int twice = (twice_front>twice_back?twice_front:twice_back);
    int third = (third_front>third_back?third_front:third_back);
    cout<<(twice>third?twice:third)<<endl;
    return 0;
}
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    while(--argc > 0)
        cout<<*++argv<<((argc>1)?" ":"");
    cout<<"\n";
    return 0;
}
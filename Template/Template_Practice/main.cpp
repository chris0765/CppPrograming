#include <iostream>

#include "Kvector.h"
#include "team.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Kvector<int> v1(3, 0);
    cout << "v1 : " << v1 << endl;
    cout << "v1.sum() : " << v1.sum() << endl;
    Kvector<int *> v2(5, nullptr);
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        v2[i] = &a[i];

    cout << "v2 : " << v2 << endl;
    for (int i = 0; i < 5; i++)
        cout << *(v2[i]) << ' ';
    cout << endl;

    Kvector<Team> league1(2, Team()), league2(2, Team());
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    league1[0] = Team("Twins", 10);
    league1[1] = Team("Bears", 5);
    league2[0] = Team("Twins", 80);
    league2[1] = Team("Bears", 81);

    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;

    cout << "league1 == league2 : " << (league1 == league2) << endl;

    league2[0] = Team("Bulls", 80);
    league2[1] = Team("Warriors", 81);

    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;

    cout << "league1.sum() : " << league1.sum() << endl;
    cout << "league2.sum() : " << league2.sum() << endl;

    return 0;
}

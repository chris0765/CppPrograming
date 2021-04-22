#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct STUDENT{
    char name[20];
    int id;
    float score;
};

bool cmp_name(struct STUDENT X, struct STUDENT Y){
    for(int i=0; i<(strlen(X.name)<strlen(Y.name)?strlen(X.name):strlen(Y.name)); i++){
        if(X.name[i]==Y.name[i])
            continue;
        return X.name[i]<Y.name[i];
    }
    return true;
}

bool cmp_score(struct STUDENT X, struct STUDENT Y){
    return X.score<Y.score;
}

int main()
{
    struct STUDENT st[50];
    for(int i=0; i<5; i++)
        cin>>st[i].name>>st[i].id>>st[i].score;
    cout<<endl;
    sort(st, st + 5, cmp_name);
    for(int i=0; i<5; i++){
        cout<<st[i].name<<" "<<st[i].id<<" "<<st[i].score<<endl;
    }
    cout<<endl;
    sort(st, st + 5, cmp_score);
    for(int i=0; i<5; i++){
        cout<<st[i].name<<" "<<st[i].id<<" "<<st[i].score<<endl;
    }
    return 0;
}
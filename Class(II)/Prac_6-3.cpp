#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;
char Room[100][100];

int RoomSize(int stx, int sty)
{
    queue<int> qx;
    queue<int> qy;
    int nowx, nowy, size=0;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    qx.push(stx);
    qy.push(sty);
    Room[stx][sty]='+';
    while(!qx.empty()&&!qy.empty())
    {
        size++;
        nowx=qx.front();qx.pop();
        nowy=qy.front();qy.pop();
        for(int i=0; i<4; i++)
        {
            int nextx = nowx+d[i][0];
            int nexty = nowy+d[i][1];
            if(Room[nextx][nexty]=='.'){
                qx.push(nextx);
                qy.push(nexty);
                Room[nextx][nexty]='+';
            }
        }
    }
    return size;
}

int main()
{
    vector<int> sizes;
    cin>>M>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>Room[i][j];
    for(int i=1; i<N-1; i++){
        for(int j=1; j<M-1; j++){
            if(Room[i][j]=='.'){
                sizes.push_back(RoomSize(i, j));
            }
        }
    }
    sort(sizes.begin(), sizes.end());
    reverse(sizes.begin(), sizes.end());
    cout<<sizes.size()<<endl;
    for(int i=0; i<sizes.size(); i++)
        cout<<sizes[i]<<" ";
    cout<<endl;
    return 0;
}
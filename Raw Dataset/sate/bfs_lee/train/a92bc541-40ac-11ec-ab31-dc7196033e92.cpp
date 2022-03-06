///#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
const int SIZE = 3e4+10,
          INF = 4e6;

using namespace std;

ifstream cin("sate.in");
ofstream cout("sate.out");

void readit();
int BFS();

int n, m, st, fin;
vector <pair<int,int>> v[SIZE];
deque <int> q;
int dist[SIZE];

int main()
{
    readit();
    BFS();
    cout<<dist[fin];
    return 0;
}

void readit()
{
    for(int i=0; i<SIZE; i++) dist[i]=INF;
    int y, x, val;
    cin>>n>>m>>st>>fin;
    for(int i=1; i<=m; i++)
        cin>>y>>x>>val,
        v[y].push_back({ val, x}),
        v[x].push_back({-val, y});
}

int BFS()
{
    int now;
    q.push_back(st);
    dist[st]=0;
    while(!q.empty())
    {
        now=q.front();
        q.pop_front();
        for(auto nxt : v[now])
            if(dist[nxt.second]==INF)
                dist[nxt.second]=dist[now]+nxt.first,
                q.push_back(nxt.second);
    }
}

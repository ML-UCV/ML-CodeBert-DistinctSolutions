#include<bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int n, m, x, y;
vector<pair<int, int>>v[30001];
int dis[30001];
bool viz[30001];
deque<int>d;
void Bfs(int nod)
{
    viz[nod]=1;
    d.push_back(nod);
    while(!d.empty())
    {
        nod=d.front();
        d.pop_front();
        for(int i=0; i<v[nod].size(); i++)
        {
            if(!viz[v[nod][i].fi])
            {
                d.push_back(v[nod][i].fi);
                viz[v[nod][i].fi]=1;
                dis[v[nod][i].fi]=dis[nod]+v[nod][i].sc;
            }
        }
    }
}
int main()
{
    f>>n>>m>>x>>y;
    for(int i=1; i<=m; i++)
    {
        int a, b, cost;
        f>>a>>b>>cost;
        v[a].push_back(make_pair(b, cost));
        v[b].push_back(make_pair(a, -cost));
    }
    Bfs(x);
    g<<dis[y];
    return 0;
}

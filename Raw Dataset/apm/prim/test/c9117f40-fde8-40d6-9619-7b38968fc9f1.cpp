#include <bits/stdc++.h>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >h;
vector<pair<int,int> >v[200005];
int n,n2,x,y,c,viz[200005];
struct solutie
{
    int x,y;
}sol[200005];
struct muchie
{
    int x,y,c;
}m[400005];
int prim(int nod)
{
    int i,cost=0,cc=0,j,nodc;
    viz[nod] = 1;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<v[nod].size();j++)
        {
            nodc = v[nod][j].second;
            cc = v[nod][j].first;
            if(!viz[nodc]) h.push({cc,{nod,nodc}});
        }
        while(viz[h.top().second.second]) h.pop();
        cost += h.top().first;
        viz[h.top().second.second] = 1;
        sol[i].x = h.top().second.first;
        sol[i].y = h.top().second.second;
        nod = h.top().second.second;
        h.pop();
    }
    return cost;
}
int main()
{
    int i;
    f>>n>>n2;
    for(i=1;i<=n2;i++)
    {
        f>>x>>y>>c;
        v[x].push_back({c,y});
        v[y].push_back({c,x});
    }
    g<<prim(1)<<'\n'<<n-1<<'\n';
    for(i=1;i<n;i++)
    {
        g<<sol[i].x<<" "<<sol[i].y<<'\n';
    }
    return 0;
}

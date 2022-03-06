#include <bits/stdc++.h>

using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector<pair<int,int> > v[30005];
queue<pair<int,int > > q;
int viz[30005],n,m,x,y,a,b,c;
int bfs(int x)
{
    int i,val,t,dist,nod;
    q.push({x,0});
    viz[x]=1;
    while(nod!=y)
    {
        nod=q.front().first;
        dist=q.front().second;
        for(i=0; i<v[nod].size(); i++)
        {
            val=v[nod][i].second;
            t=v[nod][i].first;
            if(viz[t]==0)
            {
                viz[t]=1;
                q.push({t,dist+val});
            }
        }
        q.pop();
    }
    if(nod==y) return dist;
    else return 0;
}
int main()
{
    int i;
    f>>n>>m>>x>>y;
    for(i=1; i<=m; i++)
    {
        f>>a>>b>>c;
        if(a<b)
        {
            v[a].push_back({b,c});
            v[b].push_back({a,-c});
        }
        else
        {
             v[a].push_back({b,-c});
            v[b].push_back({a,c});
        }
    }
    g<<bfs(x);
    return 0;
}

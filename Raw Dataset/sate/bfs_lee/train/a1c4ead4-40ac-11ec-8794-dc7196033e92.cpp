#include <bits/stdc++.h>
using namespace std;
int n,np,ns;
vector<vector<pair<int,int>>>g;
queue<int>q;
vector<int>d;
vector<bool>viz;
ifstream fin("sate.in");
ofstream fout("sate.out");
void read()
{
    int x,y,dis,m;
    fin>>n>>m>>np>>ns;
    g=vector<vector<pair<int,int>>>(n+1);
    d=vector<int>(n+1);
    viz=vector<bool>(n+1);
    for(int i=1; i<=m; i++)
    {
        fin>>x>>y>>dis;
        g[x].push_back({y,dis});
        g[y].push_back({x,dis});
    }
}
void bfs()
{
    int nod,v,dis;
    q.push(np);
    viz[np]=1;
    while(!q.empty())
    {
        nod=q.front();
        if(nod==ns)
            break;
        q.pop();
        for(auto e:g[nod])
        {
            v=e.first,dis=e.second;
            if(!viz[v])
            {
                if(v<nod)
                    d[v]=d[nod]-dis;
                else
                    d[v]=d[nod]+dis;
                q.push(v);
                viz[v]=1;
            }
        }
    }
}
int main()
{
    read();
    bfs();
    fout<<d[ns];
}

#include <bits/stdc++.h>

using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
int viz[30005],val[30005],n,m,x,y,i,x2,y2,dist;
vector <pair <int,int > > v[30005];
void dfs (int x,int dist)
{
    int i,nod;
    viz[x]=1;
    val[x]=dist;
    for (i=0;i<v[x].size();i++)
    {
        nod=v[x][i].first;
        if (viz[nod]==0)
        {
            if (x>nod)
            {
                dfs(nod,dist-v[x][i].second);
            }
            else
            {
                dfs(nod,dist+v[x][i].second);
            }
        }
    }
}
int main()
{
    f>>n>>m>>x>>y;
    if (x>y)swap(x,y);
    for (i=1;i<=m;i++)
    {
        f>>x2>>y2>>dist;
        v[x2].push_back({y2,dist});
        v[y2].push_back({x2,dist});
    }
    dfs(x,0);
    g<<abs(val[y]);
    return 0;
}

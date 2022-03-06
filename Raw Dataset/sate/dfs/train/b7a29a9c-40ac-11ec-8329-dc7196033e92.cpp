#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define nmax 1000000
#define MMAX 100000
#define inf 1e18
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
bool viz[30005];
int dist[30005];
vector<pair<int,int> > adj[30005];
int n,m,x,y;
void dfs(int node,int d)
{
    viz[node]=1;
    dist[node]=d;
    for(auto x:adj[node])
    {
        if(viz[x.first]==0)
        {
            if(node<x.first)
            {
                dfs(x.first,d+x.second);
            }
            else
            {
                dfs(x.first,d-x.second);
            }
        }
    }
}
int main()
{
f>>n>>m>>x>>y;
if(x>y) swap(x,y);
for(int i=1;i<=m;i++)
{
    int a,b,c;
    f>>a>>b>>c;
    adj[a].pb({b,c});
    adj[b].pb({a,c});
}
dfs(x,0);
g<<abs(dist[y]);






}

#include <bits/stdc++.h>

using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
const int NMAX = 30005;
vector< pair<int,int> > v[NMAX];
int viz[NMAX],x,y;
void dfs(int now, int s)
{
    viz[now] = s;
    if (!viz[y])
    for (auto it: v[now])
    {
        int next = it.first, dist = it.second;
        if (!viz[next])
            dfs(next,s+dist);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    in.tie(0);
    out.tie(0);
    int n,m;
    in >> n >> m >> x >> y;
    for (int i = 1; i<=m; i++)
    {
        int a,b,val;
        in >> a >> b >> val;
        v[a].push_back({b,val});
        v[b].push_back({a,-val});
    }
    dfs(x,1);
    out << viz[y]-1;
}

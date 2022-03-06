#include <fstream>
#include <vector>
using namespace std;
#define nmax 30005


vector<pair<int,int>>Q[nmax];

ifstream f("sate.in");
ofstream g("sate.out");

int n,m,x,y,dist[nmax];
bool passed=0;

void read()
{
    f>>n>>m>>x>>y;
    for (int i=1; i<=m; ++i)
    {
        int r1,r2,r3;
        f>>r1>>r2>>r3;
        Q[r1].push_back({r2,r3});
        Q[r2].push_back({r1,-r3});
    }

}

void dfs(int nod)
{
    if (nod==y)
        passed=true;
    if (passed)
        return;
    for (auto w:Q[nod])
    {
        if (!dist[w.first])
        {
            dist[w.first]=dist[nod]+w.second;
            dfs(w.first);
        }
    }
}

void solve()
{
    dist[x]=1;
    dfs(x);
    g<<dist[y]-1;
}

int main()
{
    read();
    solve();
    return 0;
}

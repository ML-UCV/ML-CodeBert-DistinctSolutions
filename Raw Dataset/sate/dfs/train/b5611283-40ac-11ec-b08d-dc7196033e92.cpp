#include <cstdio>
#include <vector>
#define nod first
#define dist second
using namespace std;
typedef pair <int, int> ii;
const int NMAX = 30000;
vector <ii> G[NMAX + 5];
int d[NMAX + 5], viz[NMAX + 5];
void dfs(int u)
{
    int v, j;
    viz[u] = 1;
    for(j = 0 ; j < G[u].size() ; j ++)
    {
        v = G[u][j].nod;
        if(!viz[v])
        {
            d[v] = d[u] + G[u][j].dist;
            dfs(v);
        }
    }
}
int main()
{
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);
    int n, m, i, x, y, z, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(i = 1 ; i <= m ; i ++)
    {
        scanf("%d%d%d", &x, &y, &z);
        G[x].push_back({y, z});
        G[y].push_back({x, -z});
    }
    dfs(s);
    printf("%d\n", d[t] - d[s]);
    return 0;
}

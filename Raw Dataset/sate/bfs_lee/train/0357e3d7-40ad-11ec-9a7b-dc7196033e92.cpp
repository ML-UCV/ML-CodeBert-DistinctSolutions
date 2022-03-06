#include <bits/stdc++.h>
#define pb push_back
using namespace std;
ifstream fi("sate.in");
ofstream fo("sate.out");

const int NMAX = 30005;

int n, m, x, y;
vector < pair<int, int> > G[NMAX];
queue <int> Q;
int dist[NMAX];

void bfs()
{
    Q.push(x);
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();

        for (auto v: G[curr])
            if (!dist[v.first])
            {
                dist[v.first] = dist[curr] + v.second;
                Q.push(v.first);
            }
    }
}

int main()
{
    fi >> n >> m >> x >> y;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        fi >> u >> v >> c;
        G[u].pb({v, c});
        G[v].pb({u, -c});
    }

    bfs();

    fo << dist[y];

    return 0;
}

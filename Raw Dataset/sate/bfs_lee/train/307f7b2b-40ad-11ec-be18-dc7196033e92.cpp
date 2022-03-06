#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int NMAX = 30000 + 5;

vector <pair <int, int> > g[NMAX];
queue <int> q;

int n, m, x, y;
int dist[NMAX];
bool vis[NMAX];

void read()
{
    int j, k, l;
    fin >> n >> m >> x >> y;
    for (int i = 1; i <= m; ++i)
    {
        fin >> j >> k >> l;
        g[j].push_back(make_pair(k, l));
        g[k].push_back(make_pair(j, -l));
    }
}

void bfs()
{
    int k, kn;
    dist[x] = 1;
    q.push(x);
    while (!q.empty())
    {
        k = q.front();
        q.pop();
        for (int i = 0; i < g[k].size(); ++i)
        {
            kn = g[k][i].first;
            if (!dist[kn])
            {
                dist[kn] = dist[k] + g[k][i].second;
                q.push(kn);
            }
        }
    }
}

int main()
{
    read();
    bfs();
    fout << dist[y] - 1;
    return 0;
}

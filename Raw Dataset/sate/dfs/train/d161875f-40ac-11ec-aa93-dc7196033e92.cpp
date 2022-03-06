#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

ifstream fin("sate.in");
ofstream fout("sate.out");

const int NMAX = 30001;
vector < pair<int, int> > g[NMAX];
int dist[NMAX];

void dfs(int node) {
    for (unsigned int i = 0; i < g[node].size(); ++i) {
        pair<int, int> n = g[node][i];
        if (!dist[n.x]) {
           dist[n.x] = dist[node] + n.y;
           dfs(n.x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, st, en;
    fin >> N >> M >> st >> en;
    while (M--) {
        int x, y, d;
        fin >> x >> y >> d;
        g[x].push_back({y, d});
        g[y].push_back({x, -d});
    }
    dfs(st);
    fout << dist[en];
}



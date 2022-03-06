#include <bits/stdc++.h>
#define STOP fout.close(); exit(0);
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
///************************
const int NMAX = 3e4 + 3;
int n, m, x, y, dis[NMAX];//dis[i]-distance from x to i;
#define fi first
#define se second
vector<pair<int, int>> edges[NMAX];

void read() {
    fin >> n >> m >> x >> y;
    for (int a, b, c, i = 0; i < m; i++) {
        fin >> a >> b >> c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }
}

void dfs(int node) {
    for (auto it : edges[node]) {
        if (dis[it.fi] == -1) {
            if (node < it.fi)
                dis[it.fi] = dis[node] + it.se;
            else
                dis[it.fi] = dis[node] - it.se;
            dfs(it.fi);
        }
    }
}

int main() {
    read();
    fill(dis + 1, dis + n + 1, -1);
    dis[x] = 0;
    dfs(x);
    fout << dis[y] << endl;
    STOP
}

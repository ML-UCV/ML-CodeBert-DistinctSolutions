#include <bits/stdc++.h>
#define NMAX 30001
#define ff first
#define ss second
using namespace std;
typedef long long ll;

string file="sate";

ifstream fin(file+".in");
ofstream fout(file+".out");

int n, m, x, y;
int viz[NMAX], dist[NMAX];

vector<pair<int, int> > a[NMAX];
queue<int> Q;

void bfs(int x) {
    Q.push(x);
    viz[x] = 1;
    dist[x] = 0;
    for (; !Q.empty(); Q.pop()) {
        int nod = Q.front();
        for (int i = 0; i < a[nod].size(); i++) {
            if (!viz[a[nod][i].ff]) {
                Q.push(a[nod][i].ff);
                dist[a[nod][i].ff] = dist[nod] + a[nod][i].ss;
                viz[a[nod][i].ff] = 1;
            }
        }
    }
}

int main() {
    int i, j, d;
    fin >> n >> m >> x >> y;
    for (int q = 1; q <= m; q++) {
        fin >> i >> j >> d;
        if (i < j) {
            a[i].push_back({j, d});
            a[j].push_back({i, -d});
        } else {
            a[i].push_back({j, -d});
            a[j].push_back({i, d});
        }
    }
    bfs(x);
    fout << dist[y];
    return 0;
}

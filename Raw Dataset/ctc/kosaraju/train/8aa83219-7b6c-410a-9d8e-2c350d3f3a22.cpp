#include <bits/stdc++.h>
using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int n, m;
vector<vector<int>> ad, adT;

vector<int> topo;
vector<bool> vis;
vector<vector<int>> sccs;

void dfs1(int node) {
    vis[node] = true;
    for (int nghb : ad[node])
        if (!vis[nghb])
            dfs1(nghb);
    topo.push_back(node);
}

void dfs2(int node) {
    vis[node] = true;
    sccs.back().push_back(node);
    for (int nghb : adT[node])
        if (!vis[nghb])
            dfs2(nghb);
}

int main() {
    fin >> n >> m;
    ad.resize(n + 1);
    adT.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y; fin >> x >> y;
        ad[x].push_back(y);
        adT[y].push_back(x);
    }

    vis.resize(n + 1);
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs1(i);

    fill(vis.begin() + 1, vis.end(), false);
    for (int i = n - 1; i >= 0; i--)
        if (!vis[topo[i]]) {
            sccs.emplace_back();
            dfs2(topo[i]);
        }

    fout << sccs.size() << '\n';
    for (auto& scc : sccs) {
        for (int node : scc)
            fout << node << ' ';
        fout << '\n';
    }

    fout.close();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

ifstream in("apm.in");
ofstream out("apm.out");

int const NMAX = 2e5;
int const MMAX = 4e5;

struct Edge {
    int from;
    int to;
    int cost;

    bool operator<(Edge other) const {
        return (cost < other.cost);
    }
};

int n, m;
Edge edges[1 + MMAX];
int boss[1 + NMAX];
int sz[1 + NMAX];

int sol;
vector<int> treeEdges;

int getBoss(int i) {
    if (boss[i] != i) {
        boss[i] = getBoss(boss[i]);
    }
    return boss[i];
}

void doUnion(int bossFrom, int bossTo) {
    if (sz[bossFrom] <= sz[bossTo]) {
        boss[bossFrom] = bossTo;
        sz[bossTo] += sz[bossFrom];
    } else {
        boss[bossTo] = bossFrom;
        sz[bossFrom] += sz[bossTo];
    }
}

int main() {
    in >> n >> m;
    for (int i = 1; i <= m; i++) {
        in >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    sort(edges + 1, edges + m + 1);
    for (int i = 1; i <= n; i++) {
        boss[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int bossFrom = getBoss(edges[i].from);
        int bossTo = getBoss(edges[i].to);
        if (bossFrom != bossTo) {
            sol += edges[i].cost;
            treeEdges.push_back(i);
            doUnion(bossFrom, bossTo);
        }
    }
    out << sol << "\n" << treeEdges.size() << "\n";
    for (int i = 0; i < treeEdges.size(); i++) {
        out << edges[treeEdges[i]].from << " " << edges[treeEdges[i]].to << "\n";
    }
    return 0;
}

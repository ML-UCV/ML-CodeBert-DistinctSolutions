#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

int n, m, nr_comp, viz[100005];
vector<int> G[100005], G2[100005], comp[100005];
stack<int> S;

void dfs(int vf) {
    viz[vf] = -1;
    for (auto &v:G[vf])
        if (viz[v] == 0)
            dfs(v);
    S.push(vf);
}

void incaUnDFS(int vf, int nrc) {
    viz[vf] = 1;
    for (auto &v:G2[vf])
        if (viz[v] < 0)
            incaUnDFS(v, nrc);
    comp[nrc].push_back(vf);
}

void citire() {
    int x, y;

    f >> n >> m;
    for (int i = 0; i < m; ++i) {
        f >> x >> y;
        G[x].push_back(y);
        G2[y].push_back(x);
    }
}

void afisare() {
    g << nr_comp << "\n";
    for (int i = 1; i <= nr_comp; ++i) {
        for (auto &v:comp[i])
            g << v << " ";
        g << "\n";
    }
}


int main() {
    citire();
    for (int i = 1; i <= n; ++i)
        if (viz[i] == 0)
            dfs(i);
    while (!S.empty()) {
        int vf = S.top();
        S.pop();
        if (viz[vf] > 0)
            continue;
        nr_comp++;
        incaUnDFS(vf, nr_comp);
    }
    afisare();
    return 0;
}

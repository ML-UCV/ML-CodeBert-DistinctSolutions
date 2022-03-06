#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int maxi = 200001;
vector<int> a[maxi], compo;
vector<vector<int>> componente;
stack<int> stiva;
int disc[maxi], low[maxi], vizitat[maxi];

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int index = 0;

void dfs(int u) {
    disc[u] = low[u] = ++index;
    stiva.push(u);
    vizitat[u] = 1;
    for (int v : a[u]) {
        if (disc[v] == -1) {
            dfs(v);
            if (low[u] > low[v])
                low[u] = low[v];
        } else if (vizitat[v] && disc[v] < low[u])
            low[u] = disc[v];
    }
    int w = 0;
    if (low[u] == disc[u]) {
        compo.clear();
        while (stiva.top() != u)
        {
            w = stiva.top();

            compo.push_back(w);
            vizitat[w] = 0;
            stiva.pop();
        }
        w = stiva.top();

        compo.push_back(w);
        vizitat[w] = 0;
        stiva.pop();
        componente.push_back(compo);
    }
}

void ctc(int n) {
    int i;
    for (i = 1; i <= n; ++i) {
        disc[i] = low[i] = -1;
    }
    for (i = 1; i <= n; ++i) {
        if (disc[i] == -1) {
            dfs(i);
        }
    }
    fout << componente.size() << "\n";
    for(auto lst : componente) {
        for(auto nod : lst)
            fout << nod << " ";
        fout << "\n";
    }

}

int main() {
    int n, m, x, y;
    fin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        fin >> x >> y;
        a[x].push_back(y);
    }
    ctc(n);
    return 0;
}

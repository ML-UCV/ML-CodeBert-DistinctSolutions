#include <bits/stdc++.h>

using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

vector<vector<int>> adiacenta(100001);
int ids[100001], low[100001];
bool onStack[100001];
stack<int> stck;
int n, m, id = 0;
vector<vector<int>> rez;

void dfs(int node) {
    stck.push(node);
    onStack[node] = true;
    ids[node] = low[node] = id++;

    for(int x : adiacenta[node]) {
        if(ids[x] == -1) {
            dfs(x);
            low[node] = min(low[node], low[x]);
        }
        else if(onStack[x])
            low[node] = min(low[node], ids[x]);
    }

    vector<int> v_aux;
    int aux;

    if(ids[node] == low[node]) {

        while(stck.top() != node) {

            aux = stck.top();
            stck.pop();

            onStack[aux] = false;
            v_aux.push_back(aux);

        }

        aux = stck.top();
        v_aux.push_back(aux);
        stck.pop();

        rez.push_back(v_aux);
        onStack[aux] = false;
    }
}

void findSccs() {
    for(int i = 1; i <= n; i++) {
        ids[i] = -1;
    }

    for(int i = 1; i <= n; i++)
        if(ids[i] == -1)
            dfs(i);
}


int main() {
    int x, y;
    f >> n >> m;

    adiacenta.resize(n);

    for(int i = 0; i < n; i++)
        onStack[i] = false;

    for(int i = 0; i < m; i++) {
        f >> x >> y;
        adiacenta[x].push_back(y);
    }

    findSccs();
    g << rez.size() << '\n';

    for(auto &i : rez) {
        for (auto j : i)
            g << j << " ";
        g << '\n';
    }

    f.close();
    g.close();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

ifstream fin("party.in");
ofstream fout("party.out");

class TwoSat {
  private:
    int n;
    vector<vector<int>> adG, adT;

    inline int non(int x) {
        return (x > n ? x - n : x + n);
    }

    void addEdge(int x, int y) {
        adG[x].push_back(y);
        adT[y].push_back(x);
    }

    void dfsG(int node, vector<bool>& vis, vector<int>& topo) {
        vis[node] = true;
        for (int nghb : adG[node])
            if (!vis[nghb])
                dfsG(nghb, vis, topo);
        topo.push_back(node);
    }

    void dfsT(int node, vector<bool>& vis, vector<bool>& ans, bool& ok) {
        vis[node] = false;
        if (ans[node])
            ok = false;
        ans[non(node)] = true;
        for (int nghb : adT[node])
            if (vis[nghb])
                dfsT(nghb, vis, ans, ok);
    }

  public:
    TwoSat(int n) :
        n(n), adG(2 * n + 1), adT(2 * n + 1) { }

    void addProp(int x, int y) {
        if (x < 0) x = n - x;
        if (y < 0) y = n - y;
        addEdge(non(x), y);
        addEdge(non(y), x);
    }

    vector<bool> solve() {
        vector<bool> vis(2 * n + 1);
        vector<int> topo;
        for (int i = 1; i <= 2 * n; i++)
            if (!vis[i])
                dfsG(i, vis, topo);
        reverse(topo.begin(), topo.end());

        bool ok = true;
        vector<bool> ans(2 * n + 1);
        for (int node : topo)
            if (vis[node] && vis[non(node)])
                dfsT(node, vis, ans, ok);

        if (!ok)
            return vector<bool>();
        ans.resize(n + 1);
        return ans;
    }
};

int main() {
    int n, m; fin >> n >> m;
    TwoSat graph(n);
    for (int i = 0; i < m; i++) {
        int x, y, t; fin >> x >> y >> t;
        if (t == 0)
            graph.addProp(+x, +y);
        else if (t == 1)
            graph.addProp(+x, -y);
        else if (t == 2)
            graph.addProp(-x, +y);
        else
            graph.addProp(-x, -y);
    }

    auto ans = graph.solve();
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += ans[i];
    fout << cnt << '\n';
    for (int i = 1; i <= n; i++)
        if (ans[i])
            fout << i << '\n';

    fout.close();
    return 0;
}

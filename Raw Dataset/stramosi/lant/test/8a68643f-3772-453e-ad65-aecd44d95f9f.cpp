#include <bits/stdc++.h>
using namespace std;

namespace Tree
{
    vector <vector <int>> adia;
    vector <int> h, poz_in_dfs_order, dfs_order, g, link, father;

    void calc_g(int node)
    {
        g[node] = 1;
        for (int i = 0; i < (int)adia[node].size(); i++) {
            calc_g(adia[node][i]);
            g[node] += g[adia[node][i]];
            if (g[adia[node][i]] > g[adia[node][0]])
                swap(adia[node][i], adia[node][0]);
        }
    }

    void make_dfs(int node, int lnk, int fth)
    {
        father[node] = fth;
        h[node] = 1 + h[fth];
        link[node] = lnk;
        poz_in_dfs_order[node] = dfs_order.size();
        dfs_order.push_back(node);

        for (auto i : adia[node])
            make_dfs(i, (i == adia[node][0] ? lnk : i), node);
    }

    void init(int n)
    {
        adia.resize(n + 1);
        h = poz_in_dfs_order = dfs_order = g = link = father = vector <int> (n + 1);
    }

    int query(int node, int dist)
    {
        while (true) {
            if (!node)
                return 0;
            if (h[node] - h[link[node]] >= dist)
                return dfs_order[poz_in_dfs_order[node] - dist];
            dist -= h[node] - h[link[node]] + 1;
            node = father[link[node]];
        }
    }
}

int main()
{
    ifstream in("stramosi.in");
    ofstream out("stramosi.out");

    int n, m;
    in >> n >> m;

    Tree::init(n);

    for (int i = 1; i <= n; i++) {
        int father;
        in >> father;
        Tree::adia[father].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (!Tree::g[i]) {
            Tree::calc_g(i);
            Tree::make_dfs(i, i, 0);
        }
    }

    while (m--) {
        int node, ord;
        in >> node >> ord;
        out << Tree::query(node, ord) << '\n';
    }

    return 0;
}

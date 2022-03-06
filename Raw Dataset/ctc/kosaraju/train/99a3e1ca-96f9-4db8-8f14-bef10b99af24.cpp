#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <cstring>




using namespace std;



void top_sort(int node, vector<bool> &vis, vector<vector<int>> &g, vector<int> &sorted) {

    vis[node] = 1;

    for(auto it : g[node])

        if(!vis[it])

            top_sort(it, vis, g, sorted);

    sorted.push_back(node);

}



int dfs(int node, vector<bool> &vis, vector<vector<int>> &g, vector<int> &component) {

    vis[node] = 1;

    component.push_back(node);

    for(auto it : g[node])

        if(!vis[it])

            dfs(it, vis, g, component);

}



int main() {

    ifstream in("ctc.in");

    ofstream out("ctc.out");



    int n, m;

    in >> n >> m;

    vector<vector<int>> g(n + 1);

    vector<vector<int>> gT(n + 1);

    for(int i = 1; i <= m; i ++) {

        int x, y;

        in >> x >> y;

        g[x].push_back(y);

        gT[y].push_back(x);

    }



    vector<bool> vis(n + 1, 0);

    vector<int> top_sorted;

    for(int i = 1; i <= n; i ++)

        if(!vis[i])

            top_sort(i, vis, g, top_sorted);

    reverse(top_sorted.begin(), top_sorted.end());



    for(int i = 1; i <= n; i ++)

        vis[i] = 0;

    vector<vector<int>> ans;

    vector<int> aux;

    for(auto i : top_sorted) {

        if(!vis[i]) {

            aux.clear();

            dfs(i, vis, gT, aux);

            reverse(aux.begin(), aux.end());

            ans.push_back(aux);

        }

    }

    out << ans.size() << "\n";

    for(auto it : ans) {

        for(auto it2 : it)

            out << it2 << " ";

        out << "\n";

    }



    return 0;

}

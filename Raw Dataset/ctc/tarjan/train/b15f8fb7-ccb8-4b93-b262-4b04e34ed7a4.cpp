#include <bits/stdc++.h>






using namespace std;

template<class Graph, class CB>
void SCC(Graph& graph, CB cb) {
  int n = graph.size(), timer = 0;
  vector<int> val(n, 0), stk, cont;
  function<int(int)> dfs = [&](int node) {
    int low; low = val[node] = ++timer;
    int sz = stk.size(); stk.push_back(node);
    for (auto vec : graph[node])
        if (val[vec] != -1)
          low = min(low, val[vec] ?: dfs(vec));
    if (low == val[node]) {
      cont = {stk.begin() + sz, stk.end()};
      for (auto x : cont) val[x] = -1;
      cb(cont); stk.resize(sz);
    } else val[node] = low;
    return low;
  };
  for (int i = 0; i < n; ++i)
    if (val[i] != -1)
      dfs(i);
}

int main() {
  ifstream cin("ctc.in");
  ofstream cout("ctc.out");
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    graph[--a].push_back(--b);
  }
  vector<vector<int>> comps;
  SCC(graph, [&](vector<int> comp) {
    comps.push_back(comp);
  });
  cout << comps.size() << '\n';
  for (auto comp : comps) {
    for (auto x : comp)
      cout << x + 1 << " ";
    cout << '\n';
  }
  return 0;
}

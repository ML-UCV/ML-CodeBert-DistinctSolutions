#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin("stramosi.in");
  ofstream cout("stramosi.out");

  int n, q; cin >> n >> q;
  vector<int> parent(n), depth(n), jump(n);
  for (int i = 0; i < n; ++i) {
    int par; cin >> par; --par;
    parent[i] = par;
    if (par == -1) {
      depth[i] = 0;
      jump[i] = i;
    } else {
      depth[i] = 1 + depth[par];
      jump[i] = (depth[par] - depth[jump[par]] ==
          depth[jump[par]] - depth[jump[jump[par]]]
          ? jump[jump[par]] : par);
    }
  }
  for (int i = 0; i < q; ++i) {
    int node, k; cin >> node >> k; --node;
    int target = depth[node] - k;
    if (target < 0) {
      cout << 0 << '\n';
    } else {
      while (depth[node] > target) {
        if (depth[jump[node]] >= target)
          node = jump[node];
        else node = parent[node];
      }
      cout << node + 1 << '\n';
    }
  }
  return 0;
}

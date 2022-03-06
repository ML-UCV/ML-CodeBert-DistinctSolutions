#include <cstdio>
#include <vector>
#include <algorithm>


const int MAX_N = 1000;



int n;

std::vector<int> g[1 + 2 * MAX_N];

std::vector<int> trans[1 + 2 * MAX_N];

std::vector<int> topo;

std::vector<int> sol;

bool viz[1 + 2 * MAX_N];

bool val[1 + 2 * MAX_N];

bool possible = true;



int conj(int x) {

  if (x <= n)

    return x + n;

  return x - n;

}



void make_edge(int u, int v) {

  g[u].push_back(v);

  trans[v].push_back(u);

}



void topoSort(int u) {

  viz[u] = true;

  for (auto v : g[u]) {

    if (!viz[v])

      topoSort(v);

  }

  topo.push_back(u);

}



void markNodes(int u) {

  viz[u] = true;

  if (val[u]) {

    possible = false;

    return;

  }

  val[u] = false;

  val[conj(u)] = true;

  for (auto v : trans[u]) {

    if (!viz[v])

      markNodes(v);

  }

}



int main() {

  freopen("party.in", "r", stdin);

  freopen("party.out", "w", stdout);



  int m;

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; i++) {

    int x, y, restriction;

    scanf("%d%d%d", &x, &y, &restriction);

    switch (restriction) {

      case 0:

        make_edge(conj(x), y);

        make_edge(conj(y), x);

        break;

      case 1:

        make_edge(conj(x), conj(y));

        make_edge(y, x);

        break;

      case 2:

        make_edge(conj(y), conj(x));

        make_edge(x, y);

        break;

      case 3:

        make_edge(x, conj(y));

        make_edge(y, conj(x));

        break;

    }

  }

  for (int i = 1; i <= 2 * n; i++) {

    if (!viz[i])

      topoSort(i);

  }

  std::reverse(topo.begin(), topo.end());

  for (int i = 1; i <= 2 * n; i++)

    viz[i] = false;

  for (auto node : topo) {

    if (!viz[node] && !viz[conj(node)])

      markNodes(node);

    if (!possible) {

      printf("-1\n");

      return 0;

    }

  }

  for (int i = 1; i <= n; i++) {

    if (val[i])

      sol.push_back(i);

  }

  printf("%d\n", sol.size());

  for (auto node : sol)

    printf("%d\n", node);

  printf("\n");

  return 0;

}

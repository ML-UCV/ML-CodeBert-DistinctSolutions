#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;



const int MAX_N = 100000;



vector<int> g[5 + MAX_N];

vector<int> rev[5 + MAX_N];

bool vis[5 + MAX_N];

vector<int> topo;

int scc;

vector<int> comp[5 + MAX_N];



void dfs_topo(int node) {

  vis[node] = true;

  for (auto u : g[node]) {

    if (!vis[u]) {

      dfs_topo(u);

    }

  }

  topo.push_back(node);

}



void make_scc(int node) {

  vis[node] = true;

  comp[scc].push_back(node);

  for (auto u : rev[node]) {

    if (!vis[u])

      make_scc(u);

  }

}



int main() {

  freopen("ctc.in", "r", stdin);

  freopen("ctc.out", "w", stdout);



  int n, m;

  scanf("%d%d", &n, &m);

  for (int i = 1; i <= m; i++) {

    int u, v;

    scanf("%d%d", &u, &v);

    g[u].push_back(v);

    rev[v].push_back(u);

  }



  for (int i = 1; i <= n; i++) {

    if (!vis[i])

      dfs_topo(i);

  }

  reverse(topo.begin(), topo.end());

  for (int i = 1; i <= n; i++)

    vis[i] = false;



  for (auto node : topo) {

    if (!vis[node]) {

      scc++;

      make_scc(node);

    }

  }



  printf("%d\n", scc);

  for (int i = 1; i <= scc; i++) {

    for (auto node : comp[i])

      printf("%d ", node);

    printf("\n");

  }



  return 0;

}

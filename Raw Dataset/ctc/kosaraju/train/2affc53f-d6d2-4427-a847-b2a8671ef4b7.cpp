#include <bits/stdc++.h>



using namespace std;



typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

vector < int > stk;
vector < bool > used;
vector < vector < int > > gr, grInv;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

void dfsInv(int node) {
  used[node] = true;
  for (int &x : grInv[node]) {
    if (used[x]) continue;
    dfsInv(x);
  }
  stk.emplace_back(node);
}

void dfs(int node, vector < int > &accum) {
  used[node] = true;
  accum.emplace_back(node);
  for (int &x : gr[node]) {
    if (used[x]) continue;
    dfs(x, accum);
  }
}


int main() {






  int n, m;
  fin >> n >> m;

  gr.resize(n + 1);
  grInv.resize(n + 1);

  for (int i = 0; i < m; ++ i) {
    int a, b;
    fin >> a >> b;
    gr[a].emplace_back(b);
    grInv[b].emplace_back(a);
  }

  stk.reserve(n + 1);
  used.resize(n + 1, false);

  for (int i = 1; i <= n; ++ i) {
    if (used[i]) continue;
    dfsInv(i);
  }

  vector < vector < int > > sol;
  fill(used.begin(), used.end(), false);

  while (not stk.empty()) {
    int curr = stk.back();
    stk.pop_back();

    if (used[curr]) continue;

    vector < int > aux;
    dfs(curr, aux);
    sol.emplace_back(aux);
  }

  fout << (int)(sol).size() << '\n';
  for (auto &comp : sol) {
    for (int &x : comp) {
      fout << x << ' ';
    }
    fout << '\n';
  }
}

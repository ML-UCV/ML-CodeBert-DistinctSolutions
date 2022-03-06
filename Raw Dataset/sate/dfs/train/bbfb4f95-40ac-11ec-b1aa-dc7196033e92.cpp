// By Stefan Radu

#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x).size()

typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

ifstream fin("sate.in");
ofstream fout("sate.out");

int x, y;

int dfs(int node, vector < vector < pii > > &gr, vector < bool > &used, int curD) {

  used[node] = true;
  if (node == y) return curD;

  for (auto pa : gr[node]) {
    if (used[pa.first]) continue;

    int ret = dfs(pa.first, gr, used, curD + pa.second);
    if (ret >= 0) return ret;
  }

  return -1;
}

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  // ios::sync_with_stdio(false);
  // cin.tie(0);cout.tie(0);

  int n, m;
  fin >> n >> m >> x >> y;

  vector < vector < pii > > gr(n + 1);
  for (int i = 1; i <= m; ++ i) {
    int a, b, c;
    fin >> a >> b >> c;
    gr[a].push_back({b, c}); 
    gr[b].push_back({a, -c}); 
  }

  vector < bool > used(n + 1);
  fout << dfs(x, gr, used, 0) << '\n';
}

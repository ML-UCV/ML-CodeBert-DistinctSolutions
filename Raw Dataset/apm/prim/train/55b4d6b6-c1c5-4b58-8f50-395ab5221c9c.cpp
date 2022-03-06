#include <stdio.h>
#include <bits/stdc++.h>



using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;

ifstream fin ("apm.in");
ofstream fout ("apm.out");

int main(void) {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, M, a, b, c;
  fin >> N >> M;
  vector<vector<pii> > g(N);
  vector<pii> edges(M);
  for(int i = 0; i < (int)(M); i++) {
    fin >> a >> b >> c;
    --a;
    --b;
    edges[i] = {a,b};
    g[a].push_back({c, i});
    g[b].push_back({c, i});
  }

  vector<char> vis(N);
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  int tc = 0;
  vector<int> tree;
  bool start = true;

  pq.push({0, 0});
  while(!pq.empty()) {
    auto P = pq.top(); pq.pop();
    auto e = edges[P.second];
    if (vis[e.first] && vis[e.second]) {
      continue;
    }
    if (start) {
      start = false;
    } else {
      tc += P.first;
      tree.push_back(P.second);
    }
    int x = vis[e.first] ? e.second : e.first;
    vis[x] = 1;
    for(auto const &Q: g[x]) {
      auto ne = edges[Q.second];
      int y = x ^ ne.first ^ ne.second;
      if (!vis[y]) {
        pq.push(Q);
      }
    }
  }

  fout << tc << "\n";
  fout << tree.size() << "\n";
  for(auto i: tree) {
    auto e = edges[i];
    fout << e.first + 1 << " " << e.second + 1 << "\n";
  }

  return 0;
}

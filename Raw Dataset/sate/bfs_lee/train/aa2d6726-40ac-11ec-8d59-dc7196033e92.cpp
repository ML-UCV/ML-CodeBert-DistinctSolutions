#include <bits/stdc++.h>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

const int maxN = (int)1e5;

int n, m, x, y;

vector<pair<int, int>> g[maxN + 5];

int dist[maxN + 5];

bool visited[maxN + 5];

int main() {
  in >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    in >> u >> v >> c;
    g[u].push_back(make_pair(v, c));
    g[v].push_back(make_pair(u, -c));
  }
  if (x > y) {
    swap(x, y);
  }
  visited[x] = true;
  queue<int> q;
  q.push(x);
  while ((int)q.size() > 0) {
    int u = q.front();
    q.pop();
    for (pair<int, int> p : g[u]) {
      int v = p.first, c = p.second;
      if (!visited[v]) {
        visited[v] = true;
        dist[v] = dist[u] + c;
        q.push(v);
      }
    }
  }
  out << dist[y] << "\n";
  return 0;
}

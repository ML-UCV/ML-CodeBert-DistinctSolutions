#include <cstdio>
#include <queue>
#include <vector>

std::vector<std::pair<int, int>> neighbours[2 + 30000];
int dist[2 + 30000];
bool reach[2 + 30000];

void bfs(int k, int Y) {
  std::queue<std::pair<int, int>> q;
  q.push({k, 1});
  dist[k] = 1;
  while (!q.empty() && !reach[Y]) {
    int e = q.front().first;
    int d = q.front().second;
    for (std::pair<int, int> p : neighbours[e])
      if (!reach[p.first]) {
        reach[p.first] = true;
        q.push({p.first, d + p.second});
        dist[p.first] = d + p.second;
      }
    q.pop();
  }
}
int main() {
  freopen("sate.in", "r", stdin);
  freopen("sate.out", "w", stdout);
  int n, m, X, Y;
  scanf("%d%d%d%d", &n, &m, &X, &Y);
  for (int i = 1; i <= m; i++) {
    int x, y, d;
    scanf("%d%d%d", &x, &y, &d);
    neighbours[x].push_back({y, d});
    neighbours[y].push_back({x, -d});
  }
  bfs(X, Y);
  printf("%d", dist[Y] - 1);
  return 0;
}

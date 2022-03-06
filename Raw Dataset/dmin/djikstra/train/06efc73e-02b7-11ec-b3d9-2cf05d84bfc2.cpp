#include <bits/stdc++.h>
using namespace std;






int n, m;
vector<pair<int, double> >graph[1505];
double dist[1505];
int dp[1505];

void read() {
  scanf("%d %d ", &n, &m);

  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d %d %d ", &x, &y, &z);
    double logz = log(z);
    graph[x].push_back({y, logz});
    graph[y].push_back({x, logz});
  }
}

void dijkstra() {
  fill(dist, dist + n + 1, 0x3f3f3f3f);

  dist[1] = 1;

  priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > q;

  q.push({0, 1});

  while (!q.empty()) {
    int node = q.top().second;
    q.pop();

    for (auto it: graph[node]) {
      if (dist[node] + it.second < dist[it.first]) {
        dist[it.first] = dist[node] + it.second;
        q.push({it.second, it.first});
      }
    }
  }
}

void solve() {
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (auto it: graph[i]) {
      int j = it.first;
      if(abs(dist[i] - (dist[j] + it.second)) < 0.000000001)
        dp[i] = (dp[i] + dp[j]) % 104659;
    }
  }
}

void print() {
  for (int i = 2; i <= n; i++)
    printf("%d ", dp[i]);
}

int main() {
  freopen("dmin.in", "r", stdin);
  freopen("dmin.out", "w", stdout);

  read();
  dijkstra();
  solve();
  print();

  return 0;
}

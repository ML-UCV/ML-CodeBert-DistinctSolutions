#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX = 100505;
int N, M;
vector<int> G[NMAX], GT[NMAX];

void read() {
 scanf("%d%d", &N, &M);
 int x, y;
 for (int i = 1; i <= M; i++) {
  scanf("%d%d", &x, &y);
  G[x].push_back(y);
  GT[y].push_back(x);
 }
}

void dfsNormalGraph(int node, vector<bool>& visited, vector<int>& sortedByExitTime) {
 visited[node] = true;
 for (auto& neighbour : G[node]) {
  if (!visited[neighbour]) {
   dfsNormalGraph(neighbour, visited, sortedByExitTime);
  }
 }

 sortedByExitTime.push_back(node);
}

void dfsTransposeGraph(int node, vector<bool>& visited, vector<int>& currentComponent) {
 visited[node] = true;
 currentComponent.push_back(node);
 for (auto& neighbour : GT[node]) {
  if (!visited[neighbour]) {
   dfsTransposeGraph(neighbour, visited, currentComponent);
  }
 }
}

void solve() {
 vector<int> sortedByExitTime;
 vector<bool> visited(N + 1, false);
 for (int node = 1; node <= N; node++) {
  if (!visited[node]) {
   dfsNormalGraph(node, visited, sortedByExitTime);
  }
 }
 reverse(sortedByExitTime.begin(), sortedByExitTime.end());

 visited.assign(N + 1, false);
 vector<vector<int>> result;
 for (auto node : sortedByExitTime) {
  if (!visited[node]) {
   vector<int> currentComponent;
   dfsTransposeGraph(node, visited, currentComponent);
   result.push_back(currentComponent);
  }
 }

 printf("%d\n", (int) result.size());
 for (auto& component : result) {
  for (auto& node : component) {
   printf("%d ", node);
  }
  printf("\n");
 }
}

int main() {
 freopen("ctc.in", "r", stdin);
 freopen("ctc.out", "w", stdout);

 read();
 solve();
 return 0;
}

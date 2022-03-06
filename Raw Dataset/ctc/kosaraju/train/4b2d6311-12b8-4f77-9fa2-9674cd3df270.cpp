#include<cstdio>
#include<vector>




using namespace std;

const int MAX_N = 1e5 + 1;

vector<int> graph[MAX_N], graph_t[MAX_N];

bool visited[MAX_N];
vector<int> exit_traversal_index;

void dfs1(int node) {
 visited[node] = true;
  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      dfs1(neighbor);
    }
  }

  exit_traversal_index.push_back(node);
}

vector<int> component[MAX_N];
int comp_index[MAX_N];

void dfs2(int node, int component_index) {
  comp_index[node] = component_index;
  component[component_index].push_back(node);

  for (int neighbor : graph_t[node]) {
    if (!comp_index[neighbor]) {
      dfs2(neighbor, component_index);
    }
  }
}

int main() {
  freopen("ctc.in","r", stdin);
  freopen("ctc.out", "w", stdout);

  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    graph[x].push_back(y);
    graph_t[y].push_back(x);
  }

  for (int node = 1; node <= n; node++) {
    if (!visited[node]) {
      dfs1(node);
    }
  }

  int no_of_components = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!comp_index[exit_traversal_index[i]]) {
      dfs2(exit_traversal_index[i], ++no_of_components);
    }
  }

  printf("%d\n", no_of_components);
  for (int i = 1; i <= no_of_components; i++) {
    for (int node : component[i]) {
      printf("%d ", node);
    }
    printf("\n");
  }

  return 0;
}

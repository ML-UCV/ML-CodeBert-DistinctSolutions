#include <cstdio>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;
vector<vector<int>> Graph, GraphTranspose, components;
stack<int> s;
bitset<100000> used;

void DFS(int k)
{
  used[k] = true;
  for (auto v : Graph[k])
    if (!used[v])
      DFS(v);
  s.push(k);
}

void DFST(int k)
{
  used[k] = true;
  components[(int)components.size() - 1].emplace_back(k);
  for (auto v : GraphTranspose[k])
    if (!used[v])
      DFST(v);
}

int main()
{
  freopen("ctc.in", "r", stdin);
  freopen("ctc.out", "w", stdout);

  int N, M;
  scanf("%d%d", &N, &M);

  Graph.resize(N);
  GraphTranspose.resize(N);

  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    Graph[a].emplace_back(b);
    GraphTranspose[b].emplace_back(a);
  }

  for (int i = 0; i < N; ++i)
    if (!used[i])
      DFS(i);

  used = 0;
  while(!s.empty()) {
    int k = s.top(); s.pop();
    if (used[k])
      continue;
    components.emplace_back(vector<int>());
    DFST(k);
  }

  printf("%d\n", (int)components.size());
  for (auto c : components) {
    for (auto n : c)
      printf("%d ", n + 1);
    printf("\n");
  }

  return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

namespace tsat {



int N;
vector<vector<int> > G, GT;
vector<int> val;
vector<int> st, viz;
int no_sol;
inline int neg(int n) {
  if (n <= N) return n + N;
  else return n - N;
}
inline void sau(int a, int b) {

  G[neg(a)].push_back(b); G[neg(b)].push_back(a);
  GT[b].push_back(neg(a)); GT[a].push_back(neg(b));
}
inline void dfs(int nod) {
  viz[nod] = 1;
  for (int i = 0; i < G[nod].size(); ++i) {
    int nod2 = G[nod][i];
    if (!viz[nod2]) dfs(nod2);
  }
  st.push_back(nod);
}
inline void dfs_t(int nod) {
  viz[nod] = 1;
  if (val[nod]) no_sol = 1;
  val[nod] = 0; val[neg(nod)] = 1;
  for (int i = 0; i < GT[nod].size(); ++i) {
    int nod2 = GT[nod][i];
    if (!viz[nod2]) dfs_t(nod2);
  }
}
int two_sat() {
  viz.assign(2*N+1, 0);
  for (int i = 1; i <= 2 * N; ++i)
    if (!viz[i]) dfs(i);
  viz.assign(2*N+1, 0);
  for (int i = st.size() - 1; i >= 0; --i) {
    if (!viz[st[i]] && !viz[neg(st[i])]) dfs_t(st[i]);
  }
  return no_sol == 0;
}
void clear() {
  N = 0;
  G.clear(); GT.clear(); val.clear(); st.clear(); viz.clear(); no_sol = 0;
}
void adapt();
}

namespace in {
int N, M;
int rel[1024][3];
}

using namespace in;
int main() {
  freopen("party.in", "r", stdin);
  freopen("party.out", "w", stdout);
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; ++i) scanf("%d %d %d", &rel[i][0], &rel[i][1], &rel[i][2]);
  tsat::adapt();
  tsat::two_sat();
  int total = 0;
  for (int i = 1; i <= N; ++i) if (tsat::val[i]) ++total;
  printf("%d\n", total);
  for (int i = 1; i <= N; ++i) if (tsat::val[i])
    printf("%d\n", i);
  return 0;
}

void tsat::adapt() {
  clear();
  N = in::N;
  G.resize(2 * N + 1); GT.resize(2 * N + 1);
  val.resize(2 * N + 1);
  for (int i = 1; i <= in::M; ++i) {
    switch(rel[i][2]) {
      case 0:
      sau(rel[i][0], rel[i][1]);
      break;
      case 1:
      sau(rel[i][0], neg(rel[i][1]));
      break;
      case 2:
      sau(neg(rel[i][0]), rel[i][1]);
      break;
      case 3:
      sau(neg(rel[i][0]), neg(rel[i][1]));
      break;
    }
  }
}

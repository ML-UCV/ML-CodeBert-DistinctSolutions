#include <fstream>
#include <vector>


const int nmax = 1e5 + 5;



std::vector<int>in[nmax], out[nmax], ans[nmax], st;

int viz[nmax], k;



void dfs(int node, int type) {

 viz[node] = type;

 if (type == 1) {

  for (auto x : in[node]) if (viz[x] == 0) dfs(x, type);

  st.push_back(node);

 }

 else {

  ans[k].push_back(node);

  for (auto x : out[node]) if (viz[x] == 1) dfs(x, type);

 }

}



int main() {

 std::ifstream fin("ctc.in");

 std::ofstream fout("ctc.out");

 int n, m, u, v;

 fin >> n >> m;

 for (int i = 0; i < m; i++) {

  fin >> u >> v;

  in[u].push_back(v);

  out[v].push_back(u);

 }

 for (int i = 1; i <= n; i++)

  if (!viz[i]) dfs(i, 1);

 while (st.size()) {

  int node = st.back();

  st.pop_back();

  if (viz[node] == 1) k++, dfs(node, 2);

 }

 fout << k;

 for (int i = 1; i <= k; i++) {

  fout << "\n";

  for (auto x : ans[i])

   fout << x << " ";

 }

}

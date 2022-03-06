#include <bits/stdc++.h>
using namespace std;

const int kNmax = 100005;

class Task {
public:
 void solve() {
  read_input();
  print_output(get_result());
 }

private:
 int n;
 int m;

 vector<int> adj[kNmax];

 vector<int> adj_trans[kNmax];

 vector<vector<int>> scc;



 vector<int> visited;



 vector<int> topsort;


 void read_input() {
  ifstream fin("ctc.in");
  fin >> n >> m;
  visited = vector<int>(n + 1, 0);
  for (int i = 1, x, y; i <= m; i++) {
   fin >> x >> y;
   adj[x].push_back(y);
   adj_trans[y].push_back(x);
  }
  fin.close();
 }

 vector<vector<int>> get_result() {
  vector<vector<int>> sol;
  kosaraju();
  sol = scc;
  return sol;
 }

 void kosaraju() {

  topsort.push_back(-1);


  for (int i = 1; i <= n; ++i) {
   if (!visited[i]) {
    dfs(i);
   }
  }



  for (int i = n; i >= 1; --i) {
   if (visited[topsort[i]]) {

    vector<int> current_scc;
    dfs_t(topsort[i], current_scc);
    scc.push_back(current_scc);
   }
  }
 }


 void dfs(int node) {
  visited[node] = 1;

  for (auto &ngh : adj[node]) {
   if (!visited[ngh]) {
    dfs(ngh);
   }
  }


  topsort.push_back(node);
 }


 void dfs_t(int node, vector<int> &current_scc) {
  visited[node] = 0;
  current_scc.push_back(node);

  for (auto &ngh : adj_trans[node]) {
   if (visited[ngh]) {
    dfs_t(ngh, current_scc);
   }
  }
 }

 void print_output(const vector<vector<int>>& result) {
  ofstream fout("ctc.out");
  fout << result.size() << '\n';
  for (const auto& ctc : result) {
   for (int nod : ctc) {
    fout << nod << ' ';
   }
   fout << '\n';
  }
  fout.close();
 }
};


int main() {


 Task *task = new Task();
 task->solve();
 delete task;
 return 0;
}

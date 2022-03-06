#include <bits/stdc++.h>
using namespace std;

const int kNmax = 100005;

class Task {
public:
 void solve() {
  read_input();
  do_algo();
  print_output(sol);
 }

private:
 int n;
 int m;
 vector<int> adj[kNmax];
 vector<int> adj_trans[kNmax];
 vector<int> visited;
 vector<int> visited_trans;
 stack<int> s;
 vector<vector<int>> sol;


 void read_input() {
  ifstream fin("ctc.in");
  fin >> n >> m;
  for (int i = 1, x, y; i <= m; i++) {
   fin >> x >> y;
   adj[x].push_back(y);
   adj_trans[y].push_back(x);
  }
  visited.resize(n+1, 0);
  fin.close();
 }


 void dfs(int source) {

  visited[source] = 1;
  for (auto &node : adj[source]) {
   if (!visited[node]) {
    dfs(node);
    s.push(node);
   }
  }
 }

 void dfs_trans(int source, int idx) {
  visited_trans[source] = 1;

  sol[idx].push_back(source);
  for (auto &node : adj_trans[source]) {
   if (!visited_trans[node]) {
    dfs_trans(node, idx);
   }
  }
 }

 void do_algo() {
  sol.resize(n);
  int count = 0;


  for (int i = 1; i <= n; i++) {
   if (!visited[i]) {
    dfs(i);
    s.push(i);
   }
  }

  visited_trans.resize(n+1, 0);
  while (!s.empty()) {
   if (!visited_trans[s.top()]) {
    dfs_trans(s.top(), count);
   }
   count++;
   s.pop();
  }
 }
 void printGraph() {
   for (int i = 1; i <= n; i++) {
     cout << "["<< i << "]: ";
     for (int x : adj[i]) {
       cout << x << " ";
     }
     cout << endl;
   }
 }
 void printStack() {
  while(!s.empty()) {
   cout << s.top() << endl;
   s.pop();
  }
 }
 int get_zeros(const vector<vector<int>> result) {
  int zeroes = 0;
  for (const auto& ctc : result) {
   if (!ctc.size()) {
    zeroes++;
   }
  }
  return zeroes;
 }
 void print_output(const vector<vector<int>>& result) {
  ofstream fout("ctc.out");
  fout << result.size() - get_zeros(result) << '\n';
  for (const auto& ctc : result) {
   if (ctc.size()) {
    for (int nod : ctc) {
     fout << nod << ' ';
    }
    fout << '\n';
   }
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

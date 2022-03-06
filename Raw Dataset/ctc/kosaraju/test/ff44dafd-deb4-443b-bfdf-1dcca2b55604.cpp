#include <bits/stdc++.h>
using namespace std;

class Task {
public:
  void solve() {
    read_input();
    get_result();
    print_output();
  }

private:

  int n, m;


  vector<int> adj[100010];


  vector<int> adj_trans[100010];


  vector<vector<int>> ctc;







  vector<int> visited;



  vector<int> topsort;

  void read_input() {
    cin >> n >> m;
    visited = vector<int>(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
      int x, y;
      cin >> x >> y;

      adj[x].push_back(y);
      adj_trans[y].push_back(x);
    }
  }

  void get_result() {
    kosaraju();
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

        vector<int> current_ctc;

        dfs_t(topsort[i], current_ctc);


        ctc.push_back(current_ctc);
      }
    }
  }


  void dfs(int node) {
    visited[node] = 1;

    for (auto &vecin : adj[node]) {
      if (!visited[vecin]) {
        dfs(vecin);
      }
    }


    topsort.push_back(node);
  }


  void dfs_t(int node, vector<int> &current_ctc) {

    visited[node] = 0;
    current_ctc.push_back(node);

    for (auto &vecin : adj_trans[node]) {
      if (visited[vecin]) {
        dfs_t(vecin, current_ctc);
      }
    }
  }

  void print_output() {

    int sol = ctc.size();
    cout << sol << "\n";

    for (int i = 0; i < sol; ++i) {

      for (auto &node : ctc[i]) {
        cout << node << " ";
      }
      cout << '\n';
    }
  }
};

int main() {

  auto cin_buff = cin.rdbuf();
  auto cout_buff = cout.rdbuf();


  ifstream fin("ctc.in");
  cin.rdbuf(fin.rdbuf());


  ofstream fout("ctc.out");
  cout.rdbuf(fout.rdbuf());


  Task *task = new Task();
  task->solve();
  delete task;


  cin.rdbuf(cin_buff);
  cout.rdbuf(cout_buff);




  return 0;
}

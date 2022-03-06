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
    ifstream fin("ctc.in");
    fin >> n >> m;
    visited = vector<int>(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
      int x, y;
      fin >> x >> y;

      adj[x].push_back(y);
      adj_trans[y].push_back(x);
    }
    fin.close();
  }

  void get_result() {
    kosaraju();
  }

  void kosaraju() {
    topsort.push_back(-1);

    for (int i = 1; i <= n; ++i) {
      if (visited[i] == 0) {
        dfs(i);
      }
    }

    for (int i = n; i >= 1; --i) {
      if (visited[topsort[i]] == 1) {
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

    for (auto &v : adj_trans[node]) {
      if (visited[v]) {
        dfs_t(v, current_ctc);
      }
    }
  }

  void print_output() {
    ofstream fout("ctc.out");
    int sol = ctc.size();
    fout << sol << '\n';

    for (int i = 0; i < sol; ++i) {
      for (auto &node : ctc[i]) {
        fout << node << " ";
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

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
  vector<int> adj[100010];
  vector<vector<int>> ctc;
  vector<int> found;
  vector<int> low_link;
  vector<int> in_stack;
  stack<int> st;
  int n, m;

  void read_input() {
    ifstream fin("ctc.in");
    fin >> n >> m;
    in_stack = vector<int>(n + 1, 0);
    found = vector<int>(n + 1, -1);
    low_link = vector<int>(n + 1, 0);
    int x, y;
    for (int i = 0; i < m; ++i) {
      fin >> x >> y;
      adj[x].push_back(y);
    }
  }

  void get_result() {
    int current_start = 0;
    for (int i = 1; i <= n; ++i) {
      if (found[i] == -1) {
        tarjan(i, current_start);
      }
    }
  }

  void tarjan(int node, int &current_start) {
    found[node] = current_start;
    low_link[node] = current_start;
    in_stack[node] = 1;
    st.push(node);
    current_start = current_start + 1;
    for (int neighbour : adj[node]) {
      if (found[neighbour] == -1) {
        tarjan(neighbour, current_start);
        low_link[node] = min(low_link[node], low_link[neighbour]);
      } else {
        if (in_stack[neighbour] == 1) {
          low_link[node] = min(low_link[node], found[neighbour]);
        }
      }
    }
    if (low_link[node] == found[node]) {
      int current;
      vector<int> new_ctc;
      while (!st.empty() && current != node) {
        current = st.top();
        st.pop();
        new_ctc.push_back(current);
        in_stack[current] = 0;
      }
      ctc.push_back(new_ctc);
    }
  }

  void print_output() {
    ofstream fout("ctc.out");
    fout << ctc.size() << "\n";
    for (vector<int> comp : ctc) {
      for (int el : comp) {
        fout << el << " ";
      }
      fout << "\n";
    }
  }
};

int main() {
  Task *task = new Task();
  task->solve();
  delete task;
  return 0;
}

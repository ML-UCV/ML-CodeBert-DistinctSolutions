#include <bits/stdc++.h> 

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
 std::vector<int> adj[kNmax];
 std::vector<int> adjt[kNmax];

 void read_input() {
  std::ifstream fin("ctc.in");
  fin >> n >> m;
  for (int i = 1, x, y; i <= m; i++) {
   fin >> x >> y;
   adj[x].push_back(y);
   adjt[y].push_back(x);
  }
  fin.close();
 }

 std::vector<std::vector<int>> get_result() {
  std::vector<std::vector<int>> sol;
  std::stack<int> nodeStack;
  std::vector<bool> visited(n + 1, false);
  for (int i = 1; i <= n; i++) {
   if (!visited[i]) {
    dfsHelper(i, visited, nodeStack);
   }
  }

  visited = std::vector<bool>(n + 1, false);
  while(nodeStack.size()) {
   int node = nodeStack.top();
   nodeStack.pop();
   std::vector<int> auxVector;

   if (!visited[node]) {
    dfsTransposeHelper(node, visited, auxVector);
    sol.push_back(auxVector);
   }
  }
  return sol;
 }


    void dfsTransposeHelper(int node, std::vector<bool> &visited, std::vector<int> &solutionPart) {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                dfsTransposeHelper(adj[node][i], visited, solutionPart);
            }
        }
        solutionPart.push_back(node);
    }

 void dfsHelper(int node, std::vector<bool> &visited, std::stack<int> &nodeStack) {
        visited[node] = true;
        for (int i = 0; i < adjt[node].size(); i++) {
            if (!visited[adjt[node][i]]) {
                dfsHelper(adjt[node][i], visited, nodeStack);
            }
        }
        nodeStack.push(node);
    }


 void print_output(std::vector<std::vector<int>> result) {
  std::ofstream fout("ctc.out");
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

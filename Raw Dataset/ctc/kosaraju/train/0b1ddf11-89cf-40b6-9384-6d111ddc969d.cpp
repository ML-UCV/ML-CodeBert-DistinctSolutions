#include <bits/stdc++.h>




using namespace std;



class Task {

public:

  void solve() {

    read_input();



    print_output(get_result());

  }



private:



  int n, m;





  vector<int> adj[100010];

  vector<int> adjt[100010];



  void read_input() {

      ifstream in("ctc.in");

      in >> n >> m;



      for (int i = 1; i <= m; ++i) {

          int x, y;

          in >> x >> y;

          adj[x].push_back(y);

          adjt[y].push_back(x);

      }



      in.close();

  }



  void dfs(int node, vector<int> &sort, vector<int> &visited){

      visited[node] = 1;

      for (auto &neighbor : adj[node])

          if (!visited[neighbor])

            dfs(neighbor,sort,visited);



      sort.push_back(node);

 }





 void dfs_transpus(int node, vector<int> &current, vector<int> &visited){

      visited[node] = 0;

   current.push_back(node);



   for (auto &neighbor : adjt[node])

    if (visited[neighbor])

   dfs_transpus(neighbor,current,visited);

 }



  vector<vector<int>> get_result() {

      vector<vector<int>> solutie;

      vector<int> visited(n + 1);

      vector<int> sort;

      sort.push_back(-1);



      for (int i = 1; i <= n; ++i) {

          if (!visited[i]) {

              dfs(i, sort, visited);

          }

      }



      for (int i = n; i >= 1; --i)

   if (visited[sort[i]]) {

    vector<int> current;

    dfs_transpus(sort[i], current, visited);

    solutie.push_back(current);

   }



   return solutie;

  }



  void print_output(vector<vector<int>> result) {

      ofstream out("ctc.out");

   out << result.size() << '\n';

   for (const auto& ctc : result) {

    for (int nod : ctc) {

   out << nod << ' ';

          }

    out << '\n';

      }



   out.close();

  }

};



int main() {
  Task *task = new Task();

  task->solve();

  delete task;
  return 0;

}

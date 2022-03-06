#include <bits/stdc++.h>
class Task {

  int n, m;

  std::vector< std::vector<int>> adj;

  std::vector< std::vector<int>> adj_t;

  std::vector<int> t_out;

  std::vector< std::vector<int>> solutie;

  std::vector<int> vizitat;

  int pas = 1;



 public:

  void solve() {

    read();

    fa();

    print();

  }



 private:

  void read() {

    std::ifstream fin("ctc.in");

    fin >> n >> m;

    vizitat = std::vector<int>(n+1, 0);

    adj.resize(n + 1);

    adj_t.resize(n + 1);

    int x, y;

    for (int i = 0; i < m; ++i) {

      fin >> x >> y;

      adj[x].push_back(y);

      adj_t[y].push_back(x);

    }

    fin.close();

  }



  void fa() {

    sortare_timp_iesire();



    parcurge_transpusa();

  }





  void sortare_timp_iesire() {

    for (int i = 1; i <= n; ++i) {

      if (vizitat[i] == 0) {

        dfs(i);

      }

    }

  }



  void dfs(int nod) {

    vizitat[nod] = 1;

    for (auto &x : adj[nod]) {

      if (vizitat[x] == 0) {

        dfs(x);

      }

    }

    t_out.push_back(nod);

  }





  void parcurge_transpusa() {

    for (auto x = t_out.end() - 1; x >= t_out.begin(); --x) {

      if (vizitat[*x] == 1) {

        std::vector<int> rand_solutie;

        dfs_transpusa(*x, rand_solutie);

        solutie.push_back(rand_solutie);

      }

    }

  }



  void dfs_transpusa(int nod, std::vector<int> &rand_solutie) {

    vizitat[nod] = 0;

    rand_solutie.push_back(nod);

    for (auto &x : adj_t[nod]) {

      if (vizitat[x] == 1) {

        dfs_transpusa(x, rand_solutie);

      }

    }

  }



  void print() {

    std::ofstream fout ("ctc.out");

    fout << solutie.size() << "\n";

    for (auto &x : solutie) {

      for (auto &y : x) {

        fout << y << " ";

      }

      fout << "\n";

    }

    fout.close();

  }

};



int main() {

  Task *t = new Task();

  t->solve();

  delete t;

  return 0;

}

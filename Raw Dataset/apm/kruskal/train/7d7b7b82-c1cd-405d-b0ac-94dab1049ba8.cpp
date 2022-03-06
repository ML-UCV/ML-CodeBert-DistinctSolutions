#include <bits/stdc++.h>
using namespace std;


using edge = std::tuple<int, int, int>;



class DisjointSet {
    std::vector<int> parent;

 public:
    DisjointSet(int n) : parent (n + 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find_root(int &node) {
        if (node != parent[node]) {
            parent[node] = find_root(parent[node]);
        }

        return parent[node];

    }

    void reunion(int &root1, int &root2) {
        parent[find_root(root1)] = find_root(root2);
    }

};

class Task {
public:
  void solve() {
    read_input();
    get_result();
    print_output();
  }

private:

  int n, m, cost_apm;


  std::vector<edge> edges;
  std::vector<edge> apm;

  void read_input() {
    std::ifstream fin("apm.in");
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int src, dst, cost;
        fin >> src >> dst >> cost;
        edges.push_back(std::make_tuple(src,dst,cost));
    }
    fin.close();
    return ;
  }

  void Kruskal() {

    cost_apm = 0;
    DisjointSet set(n + 1);
    apm.clear();

    for (auto e : edges) {
        int x = std::get<0>(e);
        int y = std::get<1>(e);
        int c = std::get<2>(e);
        if (set.find_root(x) != set.find_root(y)) {
            cost_apm = cost_apm + c;
            apm.push_back(e);
            set.reunion(x, y);
        }
    }
  }

  void get_result() {
      std::sort(edges.begin(), edges.end(), [](auto const &t1, auto const &t2) {
          return std::get<2>(t1) < std::get<2>(t2);
      });

      Kruskal();
  }

  void print_output() {
      std::ofstream fout("apm.out");
      fout<<cost_apm<<"\n";
      fout<<apm.size()<<"\n";
      for (auto const &e : apm) {
        fout<<std::get<0>(e) <<" " << std::get<1>(e) << "\n";
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

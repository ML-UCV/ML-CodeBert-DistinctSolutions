#include <bits/stdc++.h>
using namespace std;


using edge = std::tuple<int, int>;

class Task {
public:
  void solve() {
    read_input();
    get_result();
    print_output();
  }

private:

  int n, m, cost_apm;


  std::vector<edge> edges[200010];
  std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;
  std::vector<int> p;

  void read_input() {
    std::ifstream fin("apm.in");
    fin >> n >> m;
    for (int i = 0; i < m; i++) {
        int src, dst, cost;
        fin >> src >> dst >> cost;
        edges[src].push_back(std::make_tuple(cost, dst));
        edges[dst].push_back(std::make_tuple(cost,src));
    }
    fin.close();
    return ;
  }

  void Prim() {
    std::vector<int> d(n + 1, (1 << 30));
    p = std::vector<int>(n + 1, 0);
    std::vector<bool> used(n + 1, false);
    int root = 1;
    d[root] = 0;
    p[root] = 0;
    pq.push(std::make_tuple(d[root], root));

    for (int i = 1; i <= n; i++) {
        std::tuple<int, int> e;
        int node;
        do {
            e = pq.top();
            pq.pop();
            node = std::get<1>(e);
        } while (used[node]);

        cost_apm += d[node];
        used[node] = true;
        for (auto e : edges[node]) {
            int cost = std::get<0>(e);
            int neigh = std::get<1>(e);
            if (!used[neigh] && cost < d[neigh]) {
                d[neigh] = cost;
                p[neigh] = node;
                pq.push(std::make_tuple(cost, neigh));
            }
        }
    }


  }

  void get_result() {
    Prim();
  }

  void print_output() {
      std::ofstream fout("apm.out");
      fout<<cost_apm<<"\n";
      fout<<n - 1<<"\n";
      for (int i = 2; i <= n; i++) {
            fout<<i <<" " << p[i] <<"\n";
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

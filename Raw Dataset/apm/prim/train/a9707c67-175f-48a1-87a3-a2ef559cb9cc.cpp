#include <bits/stdc++.h>


typedef std::tuple<int, int> edge;



class Task {
 public:
    void solve() {
        read_input();
        get_result();
        print_output();
    }

    int n, m, cost_apm, root;
    std::vector<int> d, p;
    std::vector<edge> G[200009];
    std::vector<edge> apm;
    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> pq;
    std::bitset<200009> used;

    void read_input() {
        std::cin >> n >> m;

        for (int i = 1, x, y, c; i <= m; ++i) {
            std::cin >> x >> y >> c;
            G[x].push_back(edge(c, y));
            G[y].push_back(edge(c, x));
        }
        cost_apm = 0;
    }

    void get_result() {
        p = std::vector<int>(n + 1, 0);
        d = std::vector<int>(n + 1, INT_MAX);

        root = 1;
        d[root] = 0;
        p[root] = 0;
        pq.push(edge(d[root], root));

        for (int i = 1; i <= n; ++i) {
            std::tuple<int, int> e;
            int node;
            do {
            e = pq.top();
            pq.pop();

            node = std::get<1>(e);
            } while (used[node]);

            cost_apm += d[node];
            used[node] = 1;

            for (auto it = G[node].begin(); it != G[node].end(); ++it) {
                int neighbour = std::get<1>(*it), cost = std::get<0>(*it);

                if (!used[neighbour] && cost < d[neighbour]) {
                    d[neighbour] = cost;
                    p[neighbour] = node;
                    pq.push(edge(d[neighbour], neighbour));
                }
            }
        }
    }

    void print_output() {
        std::cout << cost_apm << "\n";
        std::cout << n - 1 << "\n";
        for (int i = 1; i <= n; ++i) {
            if (i != root) {
                std::cout << i << " " << p[i] << "\n";
            }
        }
    }
};

int main() {
    auto cin_buff = std::cin.rdbuf();
    auto cout_buff = std::cout.rdbuf();

    std::ifstream fin("apm.in");
    std::cin.rdbuf(fin.rdbuf());

    std::ofstream fout("apm.out");
    std::cout.rdbuf(fout.rdbuf());

    Task *task = new Task();
    task->solve();
    delete task;

    std::cin.rdbuf(cin_buff);
    std::cout.rdbuf(cout_buff);
    return 0;
}

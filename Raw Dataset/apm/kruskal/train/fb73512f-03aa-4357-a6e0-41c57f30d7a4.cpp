#include <bits/stdc++.h>




struct edge {
    int first_node;
    int second_node;
    int cost;
};

bool compareEdges(const struct edge& e1, const struct edge& e2) {
    return e1.cost < e2.cost;
}

class Task {
 public:
    void solve() {
        read_input();
        get_result();
        print_output();
    }

 private:
    int n, m, cost_apm, parent[200005];
    std::vector<edge> edges;
    std::vector<edge> apm;

    void read_input() {
        std::cin >> n >> m;
        cost_apm = 0;
        for (int i = 1, x, y, c; i <= m; ++i) {
            std::cin >> x >> y >> c;

            struct edge new_edge;
            new_edge.first_node = x;
            new_edge.second_node = y;
            new_edge.cost = c;

            edges.push_back(new_edge);
        }
    }

    int get_set(int node) {
        if (parent[node] != node) {
            parent[node] = get_set(parent[node]);
        }
        return parent[node];
    }

    void reunion_set(int x, int y) {
        parent[get_set(x)] = get_set(y);
    }

    void get_result() {
        std::sort(edges.begin(), edges.end(), compareEdges);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int x, y, c;

            x = edge.first_node;
            y = edge.second_node;
            c = edge.cost;

            if (get_set(x) != get_set(y)) {
                cost_apm += c;
                apm.push_back(edge);
                reunion_set(x, y);
            }
        }
    }

    void print_output() {
        std::cout << cost_apm << "\n";
        std::cout << apm.size() << "\n";
        for (auto& edge : apm) {
            std::cout << edge.first_node << " " << edge.second_node << "\n";
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

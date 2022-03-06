#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

struct traversal_data {
    Graph &G;
    vector<bool> &visited;
    list<int> &order;
    int SCC_index;
    Graph &SCCs;
};

void read_input(int &n, int &m, Graph &G, Graph &TG);
void visit_post_order(int current_node, traversal_data &td);
void get_scc(int current_node, traversal_data &td);
void write_solution(int count, Graph &SCCs);

int main() {
    int n, m;
    Graph G, TG, SCCs;
    read_input(n, m, G, TG);

    list<int> order;
    vector<bool> visited(n, false);
    traversal_data td = {G, visited, order, 0, SCCs};

    for (int i = 0; i < n; ++i) {
        if (not visited[i]) visit_post_order(i, td);
    }

    SCCs.resize(n);
    traversal_data scc_td = {TG, visited, order, 0, SCCs};

    while (not order.empty()) {
        int node = order.front();
        order.pop_front();

        if (visited[node]) {
            get_scc(node, scc_td);
            scc_td.SCC_index++;
        }
    }

    write_solution(scc_td.SCC_index, SCCs);

    return 0;
}

const char* input_file = "ctc.in";
void read_input(int &n, int &m, Graph &G, Graph &TG) {
    ifstream f(input_file);

    f >> n >> m;
    G.resize(n);
    TG.resize(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        f >> x >> y;

        x--; y--;

        G[x].push_back(y);
        TG[y].push_back(x);
    }
}

void visit_post_order(int current_node, traversal_data &td) {
    td.visited[current_node] = true;

    for (auto neighbour: td.G[current_node]) {
        if (not td.visited[neighbour]) visit_post_order(neighbour, td);
    }
    td.order.push_front(current_node);
}

void get_scc(int current_node, traversal_data &td) {
    td.visited[current_node] = false;
    td.SCCs[td.SCC_index].push_back(current_node);

    for (auto neighbour: td.G[current_node]) {
        if (td.visited[neighbour]) get_scc(neighbour, td);
    }
}

const char* output_file = "ctc.out";
void write_solution(int count, Graph &SCCs) {
    ofstream f(output_file);
    f << count << "\n";
    for (int i = 0; i < count; ++i) {
        for (auto node: SCCs[i]) {
            f << node + 1 << " ";
        }
        f << "\n";
    }
}

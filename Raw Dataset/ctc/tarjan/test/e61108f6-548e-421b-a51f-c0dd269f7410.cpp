#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

struct traversal_data {
    Graph &G;
    vector<bool> &visited;
    stack<int> &post_order_stack;
    vector<bool> &in_stack;

    int current_time;
    vector<int> &found_time;
    vector<int> &lowlink;

    int SCC_index;
    Graph &SCCs;
};

void read_input(int &n, int &m, Graph &G, Graph &TG);
void get_scc(int current_node, traversal_data &td);
void write_solution(int count, Graph &SCCs);

int main() {
    int n, m;
    Graph G, TG, SCCs;
    read_input(n, m, G, TG);

    vector<bool> visited(n, false);
    stack<int> post_order_stack;
    vector<bool> in_stack(n, false);
    SCCs.resize(n);
    vector<int> found_time(n, -1);
    vector<int> lowlink(n, -1);

    traversal_data td = {G, visited, post_order_stack, in_stack, 0, found_time, lowlink, 0, SCCs};
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) get_scc(i, td);
    }

    write_solution(td.SCC_index, SCCs);

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

void get_scc(int current_node, traversal_data &td) {
    td.visited[current_node] = true;
    td.found_time[current_node] = td.current_time++;
    td.lowlink[current_node] = td.found_time[current_node];
    td.post_order_stack.push(current_node);
    td.in_stack[current_node] = true;

    for (auto neighbour: td.G[current_node]) {
        if (not td.visited[neighbour]) {
            get_scc(neighbour, td);
            td.lowlink[current_node] = min(
                td.lowlink[current_node],
                td.lowlink[neighbour]
            );
        } else if (td.in_stack[neighbour]) {
            td.lowlink[current_node] = min(
                td.lowlink[current_node],
                td.lowlink[neighbour]
            );
        }
    }

    if (td.found_time[current_node] == td.lowlink[current_node]) {
        int top_node;
        do {
            top_node = td.post_order_stack.top();
            td.post_order_stack.pop();

            td.SCCs[td.SCC_index].push_back(top_node);
            td.in_stack[top_node] = false;
        } while (top_node != current_node);
        td.SCC_index++;
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

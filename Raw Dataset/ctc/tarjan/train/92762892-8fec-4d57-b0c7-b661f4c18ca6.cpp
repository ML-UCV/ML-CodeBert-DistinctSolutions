#include <bits/stdc++.h>

const int MAXN = 100005;

using namespace std;

struct tarjan_node {
    int index, lowlink, on_stack;
};

void tarjan_DFS(int node, vector<int> *Graph, vector<vector<int> > &output, stack<int> &s, tarjan_node *nodes) {
    static int pos = 0;
    nodes[node].index = nodes[node].lowlink = ++pos;
    nodes[node].on_stack = 1;
    s.push(node);

    for(long unsigned int i = 0; i < Graph[node].size(); i++) {
        int son = Graph[node][i];

        if(nodes[son].index == 0) {
            tarjan_DFS(son, Graph, output, s, nodes);
            nodes[node].lowlink = min(nodes[node].lowlink, nodes[son].lowlink);
        } else if(nodes[son].on_stack == 1) {
            nodes[node].lowlink = min(nodes[node].lowlink, nodes[son].lowlink);
        }
    }

    if(nodes[node].lowlink == nodes[node].index) {
        vector<int> SCC;
        int new_node;

        do {
            new_node = s.top();
            s.pop();
            nodes[new_node].on_stack = 0;
            SCC.push_back(new_node);
        } while(new_node != node);

        output.push_back(SCC);
    }
}

void tarjan(int N, vector<int> *Graph, vector<vector<int> > &output) {
    stack<int> s;
    tarjan_node nodes[MAXN];
    memset(nodes, 0, sizeof(nodes));

    for(int i = 1; i <= N; i++)
        if(nodes[i].index == 0)
            tarjan_DFS(i, Graph, output, s, nodes);
}

int main() {
    FILE *in = fopen("ctc.in", "r");
    FILE *out = fopen("ctc.out", "w");

    int N, M, X, Y;
    vector<int> Graph[MAXN];
    vector<vector<int> > output;

    fscanf(in, "%d %d", &N, &M);

    for(int i = 1; i <= M; i++) {
        fscanf(in, "%d %d", &X, &Y);
        Graph[X].push_back(Y);
    }

    tarjan(N, Graph, output);

    fprintf(out, "%lu\n", output.size());

    for(long unsigned int i = 0; i < output.size(); i++) {
        for(long unsigned int j = 0; j < output[i].size(); j++) {
            fprintf(out, "%d ", output[i][j]);
        }
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);

    return 0;
}

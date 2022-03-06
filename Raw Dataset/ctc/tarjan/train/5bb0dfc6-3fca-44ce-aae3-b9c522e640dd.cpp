#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector <std::vector<int>> adj, sccList;
std::vector <int> idx, lowlink, conex, onStack;
std::stack <int> stack;
int atIDX = 0;

void read(int &n) {
    std::ifstream f("ctc.in");
    f >> n;;
    int edges;
    adj.resize(n);
    f >> edges;
    for (int i = 0; i < edges; i++) {
        int x, y;
        f >> x >> y;
        adj[x-1].push_back(y-1);
    }
    f.close();
}

void print(const std::vector <std::vector<int>> sccList) {
    std::ofstream g("ctc.out");
    g << sccList.size() << '\n';
    for (int i = 0; i < sccList.size(); i++) {
        for (int j = 0; j < sccList[i].size(); j++) {
            g << sccList[i][j] + 1 << " ";
        }
        g << '\n';
    }
    g.close();
}

void tarjan(int x) {
    idx[x] = lowlink[x] = atIDX;
    stack.push(x);
    onStack[x] = 1;
    atIDX++;
    for (int i = 0; i < adj[x].size(); i++) {
        if (idx[adj[x][i]] == -1) {
            tarjan(adj[x][i]);
            lowlink[x] = std::min(lowlink[x], lowlink[adj[x][i]]);
        } else if (onStack[adj[x][i]] == 1) {
            lowlink[x] = std::min(lowlink[x], lowlink[adj[x][i]]);
        }
    }

    if (idx[x] == lowlink[x]) {
        conex.clear();
        int node;
        do {
            conex.push_back(node = stack.top());
            stack.pop();
            onStack[node] = 0;
        } while (node != x);

        sccList.push_back(conex);
    }
}

int main() {
    int n;
    read(n);


    idx.resize(n);
    lowlink.resize(n);
    onStack.resize(n);
    idx.assign(n, -1);
    onStack.assign(n, 0);

    for (int i = 0; i < n; i++) {
        if (idx[i] == -1) {
            tarjan(i);
        }
    }

    print(sccList);
    return 0;
}

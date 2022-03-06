#include <iostream>
#include <vector>
#include <set>
#include <set>
#include <fstream>

using namespace std;





struct Edge {
    int node;

    int cost;

    bool operator < (Edge e) const {
        if (cost != e.cost) {
            return cost < e.cost;
        }

        return node < e.node;
    }
};

int n, m;

vector<Edge> g[200001];

set<Edge> available;

bool visited[200001];

int dist[200001];

int sol = 0;

int solEdge[200001];

int main() {
    ofstream out("apm.out");

    ifstream in("apm.in");

    in >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, c;

        in >> x >> y >> c;

        x--; y--;

        g[x].push_back({y, c});

        g[y].push_back({x, c});
    }

    for (int i = 0; i < 200001; i++) {
        dist[i] = 1e9;
    }

    dist[0] = 0;

    available.insert({0, 0});

    while (!available.empty()) {
        Edge curr = *available.begin();

        available.erase(available.begin());

        visited[curr.node] = true;

        int bestEdge = -1;

        for (int i = 0; i < g[curr.node].size(); i++) {
            if (g[curr.node][i].cost < dist[g[curr.node][i].node] && !visited[g[curr.node][i].node]) {
                dist[g[curr.node][i].node] = g[curr.node][i].cost;

                available.insert({g[curr.node][i].node, dist[g[curr.node][i].node]});

                bestEdge = g[curr.node][i].node;

                solEdge[g[curr.node][i].node] = curr.node;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        sol += dist[i];
    }

    out << sol << '\n';

    out << n - 1 << '\n';

    for (int i = 1; i < n; i++) {
        out << solEdge[i] + 1 << " " << i + 1 << '\n';
    }

    return 0;
}

#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct edge {
    int x, y, c;
};

pair<int, vector<edge>> readGraph() {
    ifstream fin("apm.in");
    int n, m;
    vector<edge> edges;

    fin >> n >> m;
    int x, y, c;
    while (m--) {
        fin >> x >> y >> c;
        edges.push_back((edge) {x, y, c});
    }

    return make_pair(n, edges);
}

int dsuRoot(int node, const vector<int> &parent) {
    while (parent[node])
        node = parent[node];
    return node;
}

pair<int, vector<int>> kruskal(int n, vector<edge> &edges) {
    int cost = 0;
    vector<int> selEdges;
    vector<int> parent(n + 1, 0);
    vector<int> height(n + 1, 0);

    sort(edges.begin(), edges.end(), [](edge &a, edge &b) {
        return a.c < b.c;
    });

    int last = -1, root1, root2;

    for (int i = 1; i < n; i++) {
        do {
            last++;
            root1 = dsuRoot(edges[last].x, parent);
            root2 = dsuRoot(edges[last].y, parent);
        } while (root1 == root2);

        selEdges.push_back(last);
        cost += edges[last].c;


        if (height[root1] < height[root2])
            parent[root1] = root2;
        else if (height[root1] > height[root2])
            parent[root2] = root1;
        else {
            parent[root2] = root1;
            height[root1]++;
        }
    }

    return make_pair(cost, selEdges);
}

int main() {
    ofstream fout("apm.out");

    int n;
    vector<edge> edges;
    tie(n, edges) = readGraph();

    int cost;
    vector<int> selectedEdges;
    tie(cost, selectedEdges) = kruskal(n, edges);

    fout << cost << '\n' << n - 1;
    for (const int e : selectedEdges)
        fout << '\n' << edges[e].x << " " << edges[e].y;
    return 0;
}

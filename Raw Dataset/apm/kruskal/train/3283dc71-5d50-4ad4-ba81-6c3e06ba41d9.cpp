#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int NMAX = 200005;

int n, m;
vector<pair<int, pair<int,int>>> graph;
vector<pair<int, pair<int,int>>> tree;
int color[NMAX];
int parent[NMAX];

void initialize(int node) {
    parent[node] = color[node] = 0;
}

int get_repr(int node) {
    while (parent[node] != 0)
        node = parent[node];
    return node;
}

void reunion(int i, int j) {
    int repr_i = get_repr(i);
    int repr_j = get_repr(j);

    if (color[repr_i] > color[repr_j]) {
        parent[repr_j] = repr_i;
    }
    else {
        parent[repr_i] = repr_j;

        if (color[repr_i] == color[repr_j]) {
            color[repr_j]++;
        }
    }
}

int main() {
    ifstream fin("apm.in");
    ofstream fout("apm.out");

    fin >> n >> m;
    int x, y, w;

    for (int i = 0; i < m; i++) {
        fin >> x >> y >> w;
        graph.emplace_back(w, make_pair(x, y));
    }

    sort(graph.begin(), graph.end());

    for (int node = 1; node <= n; node++) {
        initialize(node);
    }

    int nr = 0;
    int cost = 0;

    for (int i = 0; i < m; i++) {
        auto edge = graph[i].second;
        w = graph[i].first;
        x = edge.first;
        y = edge.second;
        if (get_repr(x) != get_repr(y)) {
            tree.emplace_back(w, make_pair(x, y));
            cost += w;

            reunion(x, y);
            nr++;

            if (nr == n - 1) {
                break;
            }
        }
    }

    fout << cost << "\n" << nr << "\n";
    for (auto edge : tree) {
        x = edge.second.first;
        y = edge.second.second;
        fout << x << " " << y << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}

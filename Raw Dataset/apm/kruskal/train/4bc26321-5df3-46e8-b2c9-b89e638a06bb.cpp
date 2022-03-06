#include <bits/stdc++.h>


using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");


class DisjointSets {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSets(int n) {
        for (int i = 0; i < n; i++)
            make_set(i);
    }

    ~DisjointSets() {
        parent.clear();
        rank.clear();
    }

    void make_set(int x) {
        parent.push_back(x);
        rank.push_back(0);
    }

    int find_set(int x) {
        vector<int> queue;
        while (parent[x] != x) {
            queue.push_back(x);
            x = parent[x];
        }

        for (int it: queue)
            parent[it] = x;

        queue.clear();

        return x;
    }

    void union_set(int x, int y) {
        int rx = find_set(x);
        int ry = find_set(y);

        if (rank[rx] <= rank[ry]) {
            parent[rx] = ry;
            rank[rx] == rank[ry] ? rank[ry]++ : false;
        }
        else
            parent[ry] = rx;
    }

    void show() {
        for (int i = 0; i < (int)parent.size(); i++)
            cout << i << " " << parent[i] << " " << rank[i] << endl;

    }
};


struct edge {
    int u, v, eticheta;
};

vector<edge> edges;

bool comparator(edge x, edge y) {
    return x.eticheta < y.eticheta;
}

void read(vector<edge> &edges, int &n, int &m) {
    f >> n >> m;
    for (int i = 0; i < m; i++) {
        edge e;
        f >> e.u >> e.v >> e.eticheta;
        e.u--;
        e.v--;
        edges.push_back(e);
    }
}

void showEdges(vector<edge> edges) {
    for (auto it: edges)
        cout << it.u << " " << it.v << " " << it.eticheta << "\n";
}

int main() {
    int n, m;
    vector<edge> edges;

    read(edges, n, m);

    sort(edges.begin(), edges.end(), comparator);

    DisjointSets sets(n);

    long long min = 0;
    vector<pair<int, int>> answer;

    for (auto it: edges) {
        if (sets.find_set(it.u) != sets.find_set(it.v)) {
            min += it.eticheta;
            sets.union_set(it.u, it.v);
            answer.push_back({it.u, it.v});
        }
    }

    g << min << "\n";

    g << answer.size() << "\n";
    for (auto it: answer)
        g << it.second + 1 << " " << it.first + 1 << "\n";

    return 0;
}

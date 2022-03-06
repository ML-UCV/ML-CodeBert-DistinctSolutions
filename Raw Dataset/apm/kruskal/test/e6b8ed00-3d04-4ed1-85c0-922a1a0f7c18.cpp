#include <bits/stdc++.h>
using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

struct Edge {
    int x, y, z;
    Edge(int x = 0, int y = 0, int z = 0) :
        x(x), y(y), z(z) { }
    inline bool operator<(Edge e) const {
        return z > e.z;
    }
};

class Forest {
  private:
    vector<int> height;
    vector<int> father;

  public:
    Forest(int n) :
        height(n + 1), father(n + 1) { }

    int find(int x) {
        int root = x;
        while (father[root])
            root = father[root];

        while (father[x]) {
            int aux = father[x];
            father[x] = root;
            x = aux;
        }
        return root;
    }

    void unite(int rootX, int rootY) {
        if (height[rootX] < height[rootY])
            father[rootX] = rootY;
        else {
            father[rootY] = rootX;
            if (height[rootX] == height[rootY])
                height[rootX]++;
        }
    }
};

int main() {
    int n, m; fin >> n >> m;
    vector<Edge> edg(m);
    for (int i = 0; i < m; i++)
        fin >> edg[i].x >> edg[i].y >> edg[i].z;

    int cost = 0;
    vector<pair<int, int>> sol;
    sol.reserve(n - 1);

    Forest forest(n);
    make_heap(edg.begin(), edg.end());
    for (int i = 1; i < n; ) {
        Edge top = edg.front();
        pop_heap(edg.begin(), edg.end());
        edg.pop_back();

        int rootX = forest.find(top.x);
        int rootY = forest.find(top.y);
        if (rootX != rootY) {
            forest.unite(rootX, rootY);
            sol.emplace_back(top.x, top.y);
            cost += top.z;
            i++;
        }
    }

    fout << cost << '\n' << n - 1 << '\n';
    for (auto edg : sol)
        fout << edg.first << ' ' << edg.second << '\n';

    fout.close();
    return 0;
}

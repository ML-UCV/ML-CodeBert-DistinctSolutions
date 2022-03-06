#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

const int NMAX = 200'001;

struct Edge {
    int x, y, cost;
};

template < int SIZE >
class Disjoint {

private:

    vector < int > tree;

    void collapse(const int& root, int node) {
        while(node != root) {
            int aux = tree[node];
            tree[node] = root;
            node = aux;
        }
    }

public:

    Disjoint() {
        tree.resize(SIZE + 1, -1);
    }

    int Find(const int& node) {
        int root = node;

        while(tree[root] > 0)
            root = tree[root];

        collapse(root, node);

        return root;
    }

    void Union(int rootX, int rootY) {
        if(-tree[rootX] < -tree[rootY])
            swap(rootX, rootY);

        tree[rootX] = tree[rootX] + tree[rootY];
        tree[rootY] = rootX;
    }

};

int n, m;
vector < pair < int, int > > G[NMAX];
vector < Edge > edges, sol;

int main() {

    f >> n >> m;

    while(m--) {
        int x, y, c;
        f >> x >> y >> c;

        G[x].push_back( { y, c } );
        G[y].push_back( { x, c } );
        edges.push_back({ x, y, c });
    }

    sort(edges.begin(), edges.end(),[](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });

    Disjoint < NMAX > disjoint;
    int cnt = 0, cost = 0;

    for(Edge e : edges) {

        const int rootX = disjoint.Find(e.x);
        const int rootY = disjoint.Find(e.y);

        if(rootX != rootY) {
            sol.push_back(e);
            disjoint.Union(rootX, rootY);
            cnt++;
            cost += e.cost;
        }

        if(cnt == n - 1)
            break;
    }

    g << cost << '\n';
    g << (int) sol.size() << '\n';

    for(auto it : sol)
        g << it.x << ' ' << it.y << '\n';

    return 0;
}

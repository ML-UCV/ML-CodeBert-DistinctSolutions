#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream f("apm.in");
ofstream g("apm.out");

struct edge { int x,y,cost; };

int n,m;
vector<edge>edges;
vector<int>sol;

class DisjointSet {

private:

    vector<int> parent;


    void compress(int node,const int& root) {
        while(node != root) {
            int aux = parent[node];
            parent[node] = root;
            node = aux;
        }
    }

public:

    DisjointSet(const int& size) {
        parent.resize(size + 1,-1);
    }


    int _find( const int& node ) {

        int root = node;

        while(parent[root] > 0)
            root = parent[root];

        compress(node,root);

        return root;
    }


    void _union(int X,int Y) {
        if(parent[X] >= parent[Y]) {
            parent[X] += parent[Y];
            parent[Y] = X;
        }else {
            parent[Y] += parent[X];
            parent[X] = Y;
        }
    }
};

void kruskal() {

    DisjointSet disjoint(n);


    sort(edges.begin(),edges.end(),[](const edge& a,const edge& b) {
        return a.cost < b.cost;
    });

    int cnt{}, cost{};

    for(int i = 0;i < m;++i) {

        int rootX = disjoint._find(edges[i].x);
        int rootY = disjoint._find(edges[i].y);


        if(rootX != rootY) {
            cnt++;
            disjoint._union(rootX,rootY);
            sol.push_back(i);
            cost += edges[i].cost;
        }

        if(cnt == n - 1)
            break;
    }

    g << cost << '\n' << n - 1 << '\n';

    for(int it : sol)
        g << edges[it].x << ' ' << edges[it].y << '\n';
}

int main() {

    f >> n >> m;

    edges.resize(m);

    for(int i = 0;i < m;++i)
        f >> edges[i].x >> edges[i].y >> edges[i].cost;

    kruskal();

    return 0;
}

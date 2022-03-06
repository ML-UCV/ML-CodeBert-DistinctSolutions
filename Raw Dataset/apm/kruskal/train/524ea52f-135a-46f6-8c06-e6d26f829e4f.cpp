#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stdint.h>
#include <fstream>


using namespace std;



ifstream fin ("apm.in");

ofstream fout("apm.out");





typedef pair<int, int> iPair;



struct Graph {

    int V, E;

    vector< pair<int, iPair>> edges;

    vector<pair<int, int>> kruskalPath;



    void addEdge(int u, int v, int w) {

        edges.push_back({ w, {u, v} });

    }

    int kruskalMST();

    void readKruskal();

};





void Graph::readKruskal() {



    fin >> V >> E;



    int edge1, edge2, cost;

    for (int i = 0; i < E; i++) {

        fin >> edge1>> edge2>>cost;

        addEdge(edge1, edge2, cost);

    }

}





struct DisjointSets {

    int* parent, * rnk;

    int n;

    DisjointSets(int n) {

        this->n = n;

        parent = new int[n + 1];

        rnk = new int[n + 1];

        for (int i = 0; i <= n; i++) {

            rnk[i] = 0;

            parent[i] = i;

        }

    }

    int find(int u) {

        if (u != parent[u])

            parent[u] = find(parent[u]);

        return parent[u];

    }

    void merge(int x, int y) {

        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])

            parent[y] = x;

        else

            parent[x] = y;

        if (rnk[x] == rnk[y])

            rnk[y]++;

    }

};

int Graph::kruskalMST() {

    int mst_wt = 0;



    sort(edges.begin(), edges.end());



    DisjointSets ds(V);



    vector< pair<int, iPair> >::iterator it;

    for (it = edges.begin(); it != edges.end(); it++) {



        int u = it->second.first;



        int v = it->second.second;



        int set_u = ds.find(u);

        int set_v = ds.find(v);



        if (set_u != set_v) {

            kruskalPath.push_back({ u,v });

            mst_wt += it->first;

            ds.merge(set_u, set_v);

        }

    }

    return mst_wt;

}

int main() {

    Graph g;

    g.readKruskal();



    int mst_wt = g.kruskalMST();

    fout << mst_wt << "\n" << g.kruskalPath.size() << "\n";

    for (vector<pair<int, int>>::iterator it = g.kruskalPath.begin(); it != g.kruskalPath.end(); it++) {

        fout << it->first << " " << it->second << "\n";

    }



    return 0;

}

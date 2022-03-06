#include <bits/stdc++.h>


using namespace std;



ifstream fin("dmin.in");

ofstream fout("dmin.out");

const int MAXN = 1510, MOD = 104659;

const long double INF = 0x3f3f3f3f, EPS = 0.0000000001;



struct Node {

    int node;

    long double cost;

    bool operator<(const Node& other) const {

        if (cost != other.cost)

            return cost < other.cost;

        return node < other.node;

    }

};



long double dist[MAXN];

int way[MAXN], n, m;

vector<Node> edges[MAXN];

set<Node> heap;



void initialize() {

    for (int i = 1; i <= n; ++i)

        dist[i] = INF;

}



void dijkstra() {

    initialize();

    dist[1] = 0;

    way[1] = 1;

    heap.insert({1, 0});

    while(!heap.empty()) {

        int node = heap.begin()->node;

        heap.erase(heap.begin());

        for (const auto& it: edges[node])

            if (abs(dist[node] + it.cost - dist[it.node]) < EPS)

                way[it.node] += way[node], way[it.node] %= MOD;

            else if (dist[node] + it.cost < dist[it.node]) {

                if (dist[it.node] != INF)

                    heap.erase({it.node, dist[it.node]});

                dist[it.node] = dist[node] + it.cost;

                way[it.node] = way[node];

                heap.insert({it.node, dist[it.node]});

            }

    }

}



void read() {

    fin >> n >> m;

    for (int i = 0; i < m; ++i) {

        int x, y, cost;

        long double ln;

        fin >> x >> y >> cost;

        ln = log10(cost);

        edges[x].push_back({y, ln});

        edges[y].push_back({x, ln});

    }

}



void print() {

    for (int i = 2; i <= n; ++i)

        fout << way[i] << ' ';

}



int main() {

    read();

    dijkstra();

    print();

    return 0;

}

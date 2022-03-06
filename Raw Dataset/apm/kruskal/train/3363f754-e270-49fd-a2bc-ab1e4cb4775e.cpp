#include <fstream>
#include <limits>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");

int find(vector<int>& parent, int a) {
    int parenta = a;
    while(parenta != parent[parenta]) {
        parenta = parent[parenta];
    }

    while(a != parent[a]) {
        int tmp = parent[a];
        parent[a] = parenta;
        a = tmp;
    }

    return parenta;
}


void union_find(vector<int>& rank, vector<int>& parent, int a, int b) {
    int parenta = find(parent, a);
    int parentb = find(parent, b);
    if (rank[parenta] >= rank[parentb]) {
        parent[parentb] = parenta;
    } else {
        parent[parenta] = parentb;
    }

    if (rank[parenta] == rank[parentb]) {
        ++rank[parenta];
    }
}

int main()
{
    int n, m, a, b, c;
    fin>>n>>m;
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 1;
    }
    priority_queue<std::tuple<int, int, int>, vector<std::tuple<int, int, int> >, greater<std::tuple<int,int,int> > > pq;
    for (int i = 0; i < m; ++i) {
        fin>>a>>b>>c;
        pq.emplace(c, a, b);
    }

    int final_cost = 0;
    vector<pair<int, int> > ret;
    while (pq.size()) {
        auto tp = pq.top(); pq.pop();
        int cost = get<0>(tp); int node_a = get<1>(tp); int node_b = get<2>(tp);

        if (find(parent, node_a) == find(parent, node_b)) {
            continue;
        }

        union_find(rank, parent, node_a, node_b);
        ret.push_back(make_pair(node_a, node_b));
        final_cost += cost;
    }

    fout<<final_cost<<"\n";
    fout<<ret.size()<<"\n";
    for(int i = 0; i < ret.size(); ++i) {
        fout<<ret[i].first << " " << ret[i].second<<"\n";
    }

    fin.close();
    fout.close();
}

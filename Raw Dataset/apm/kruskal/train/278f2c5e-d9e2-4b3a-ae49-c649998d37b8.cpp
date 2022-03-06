#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;

int N, M;

vector<int> parent, tree_size;

vector<pair<int, pii>> adj;





void make_set(const int &vertex)

{

    parent[vertex] = vertex;

    tree_size[vertex] = 1;

}





int find_leader(const int &vertex)

{

    if (parent[vertex] == vertex)

    {

        return vertex;

    }



    return parent[vertex] = find_leader(parent[vertex]);

}





void unite_sets(int &set1, int &set2)

{

    set1 = find_leader(set1);

    set2 = find_leader(set2);



    if (set1 != set2)

    {

        if (tree_size[set1] < tree_size[set2])

        {

            swap(set1, set2);

        }



        tree_size[set1] += tree_size[set2];

        parent[set2] = set1;

    }

}





void Kruskal()

{

    vector<pii> MST_edges;

    int total_weight = 0;



    for (int node = 1; node <= N; ++node)

    {

        make_set(node);

    }



    sort(begin(adj), end(adj));



    for (const auto &edge : adj)

    {

        int CC1 = edge.second.first, CC2 = edge.second.second;

        int leader1 = find_leader(CC1), leader2 = find_leader(CC2);



        if (leader1 != leader2)

        {

            total_weight += edge.first;

            MST_edges.push_back({CC1, CC2});

            unite_sets(leader1, leader2);

        }

    }



    ofstream fout("apm.out");



    fout << total_weight << "\n" << N - 1 << "\n";

    for (const pii &MST_edge : MST_edges)

    {

        fout << MST_edge.first << " " << MST_edge.second << "\n";

    }

}





int main()

{

    ifstream fin("apm.in");



    fin >> N >> M;

    parent.resize(N + 1);

    tree_size.resize(N + 1);



    while (M--)

    {

        int i, j, weight;

        fin >> i >> j >> weight;



        adj.push_back({weight, {i, j}});

        adj.push_back({weight, {j, i}});

    }



    Kruskal();

}

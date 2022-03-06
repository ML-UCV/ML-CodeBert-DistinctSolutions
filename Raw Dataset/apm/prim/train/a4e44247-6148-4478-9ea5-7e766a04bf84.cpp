#include <fstream>
#include <set>
#include <cassert>
#include <vector>
using namespace std;

using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;

int N, M;

vector<vector<pii>> adj;





void Prim(const int &beg_node)

{

    int total_weight = 0;

    vector<bool> is_in_MST(N + 1);

    for (int i = 1; i <= N; ++i)

    {

        assert(!is_in_MST[i]);

    }

    vector<int> key(N + 1, INF), parent(N + 1);

    set<pii> Q;



    Q.insert({0, beg_node});

    key[beg_node] = 0;



    for (int node = 1; node <= N; ++node)

    {

        assert(!Q.empty());



        total_weight += begin(Q)->first;

        int min_node = begin(Q)->second;

        assert(!is_in_MST[min_node]);

        is_in_MST[min_node] = true;

        Q.erase(begin(Q));



        for (const pii &adj_node : adj[min_node])

        {

            if (!is_in_MST[adj_node.second] && adj_node.first < key[adj_node.second])

            {

                Q.erase({key[adj_node.second], adj_node.second});

                key[adj_node.second] = adj_node.first;

                parent[adj_node.second] = min_node;

                Q.emplace(adj_node);

            }

        }

    }



    ofstream fout("apm.out");



    fout << total_weight << "\n" << N - 1 << "\n";

    for (int node = 1; node <= N; ++node)

    {

        if (node != beg_node)

        {

            fout << node << " " << parent[node] << "\n";

        }

    }

}





int main()

{

    ifstream fin("apm.in");



    fin >> N >> M;

    adj.resize(N + 1);



    while (M--)

    {

        int i, j, weight;

        fin >> i >> j >> weight;



        adj[i].push_back({weight, j});

        adj[j].push_back({weight, i});

    }



    Prim(1);

}

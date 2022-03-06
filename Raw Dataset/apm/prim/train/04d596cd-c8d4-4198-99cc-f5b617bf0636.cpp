#include <bits/stdc++.h>




using namespace std;



int main()

{

    int n , m, cost = 0;

    ifstream fin("apm.in");

    fin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    vector<vector<pair<int, int>>> adj(n + 1);

    vector<int> dist(n + 1, 1e9);

    vector<int> parent(n + 1, 0);

    vector<bool> used(n + 1, false);

    for (int i = 1, x, y, c; i <= m; ++i) {

        fin >> x >> y >> c;

        adj[x].push_back({c, y});

        adj[y].push_back({c, x});

    }

    fin.close();



    dist[1] = 0;

    q.push({dist[1], 1});



    for (int i = 1; i <= n; ++i) {

        int node;

        do {

            node = q.top().second;

            q.pop();

        } while (used[node]);



        cost += dist[node];

        used[node] = true;



        for (auto &neigh : adj[node]) {

            if (!used[neigh.second] && neigh.first < dist[neigh.second]) {

                dist[neigh.second] = neigh.first;

                parent[neigh.second] = node;

                q.push({neigh.first, neigh.second});

            }

        }

    }



    ofstream fout("apm.out");

    fout << cost << '\n' << n - 1 << '\n';

    for (int i = 2; i <= n; ++i) {

        fout << i << ' ' << parent[i] << '\n';

    }

    fout.close();

    return 0;

}

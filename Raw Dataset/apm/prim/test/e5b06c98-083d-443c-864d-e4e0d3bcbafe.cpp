#include <fstream>
#include <vector>
#include <queue>
using namespace std;



ifstream in("apm.in");

ofstream out("apm.out");



const int INF = 1e9;



vector <int> dist, t;



vector <bool> vis;



vector<vector<pair<int, int>>> adj;

vector<pair<int, int>> ans;

priority_queue <pair<int, int>> pq;



int main()

{

    int n, m, costTotal = 0;

    in >> n >> m;



    dist.resize(n + 1, INF);

    t.resize(n + 1, 0);

    vis.resize(n + 1, false);

    adj.resize(n + 1);



    for(int i = 0; i < m; ++i)

    {

        int x, y, cost;

        in >> x >> y >> cost;

        adj[x].push_back({y, cost});

        adj[y].push_back({x, cost});

    }



    dist[1] = 0;



    pq.push({0, 1});



    while(!pq.empty())

    {

        int node = pq.top().second;

        pq.pop();



        if(vis[node] == false)

        {

            vis[node] = true;

            costTotal += dist[node];

            if(t[node])

                ans.push_back({node, t[node]});



            for(auto it : adj[node])

            {

                if(it.second < dist[it.first])

                {

                    dist[it.first] = it.second;

                    t[it.first] = node;

                    pq.push({-it.second, it.first});

                }

            }

        }

    }



    out << costTotal << '\n' << n - 1 << '\n';

    for(auto it : ans)

    {

        out << it.first << " " << it.second << '\n';

    }

    return 0;

}

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

int n, m, x, y;
int d[30005];
vector<vector<pair<int, int>>> adj;

void bfs()
{
    queue<int> q;
    q.push(x);
    d[x] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it: adj[node])
        {
            int next = it.first;
            int dist = it.second;

            if(d[next] != 0)
                continue;

            if(x > node)
            {
                if(node > next)
                    d[next] = d[node] + dist;
                else
                    d[next] = abs(d[node] - dist);
            }
            else
            {
                if(node > next)
                    d[next] = abs(d[node] - dist);
                else
                    d[next] = d[node] + dist;
            }

            q.push(next);
        }
    }
}

int main()
{
    in >> n >> m >> x >> y;
    adj.resize(n + 5);
    for(int i = 1; i <= m; i++)
    {
        int a, b, dist;
        in >> a >> b >> dist;
        adj[a].emplace_back(b, dist);
        adj[b].emplace_back(a, dist);
    }

    bfs();

    out << d[y] << '\n';

    return 0;
}

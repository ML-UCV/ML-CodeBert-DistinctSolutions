#include <bits/stdc++.h>

using namespace std;

int nodes, edges, X, Y, u, v, cost, visited[30001];

vector<pair<int, int> > adj[30001];

int BFS(int start)
{
    queue<pair<int, int> > q; q.push({start, 0});

    while(!q.empty())
    {
        int current = q.front().first,
            cost    = q.front().second;

        if(current == Y) return cost;

        q.pop();

        for(auto child : adj[current])
        {
            if(!visited[child.first])
            {
                q.push({child.first, child.second + cost});

                visited[child.first] = 1;
            }
        }
    }
}

int main()
{
    freopen("sate.in", "r", stdin);
    freopen("sate.out", "w", stdout);

    scanf("%d %d %d %d", &nodes, &edges, &X, &Y);

    for(int i = 1; i <= edges; i++)
    {
        scanf("%d %d %d", &u, &v, &cost);

        adj[u].push_back({v,  cost});

        adj[v].push_back({u, -cost});
    }

    printf("%d", BFS(X));

    return 0;
}

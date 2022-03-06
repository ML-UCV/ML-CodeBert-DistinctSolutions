#include <bits/stdc++.h>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

struct Edge
{
    int dest, cost;
};

vector <Edge> v[30005];

int dist[30005];
bool viz[30005];

int main()
{
    int N, M, S, F;

    fin >> N >> M >> S >> F;

    for(int i = 1; i <= M; i++)
    {
        int x, y, z;

        fin >> x >> y >> z;

        v[x].push_back({y, z});
        v[y].push_back({x, -z});
    }

    for(int i = 1; i <= N; i++)
        dist[i] = -1;

    dist[S] = 0;
    queue <int> q;

    q.push(S);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        viz[node] = false;

        for(int i = 0; i < v[node].size(); i++)
            if(viz[v[node][i].dest] == false && dist[v[node][i].dest] == -1)
        {
            dist[v[node][i].dest] = dist[node] + v[node][i].cost;
            viz[v[node][i].dest] = true;

            q.push(v[node][i].dest);
        }
    }

    fout << dist[F] << '\n';

    return 0;
}

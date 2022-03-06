#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int Nmax = 30000;
int dist[Nmax + 1];
bool visited[Nmax + 1];
vector <pair <int, int>> adj[Nmax + 1];
queue <int> q;

int main()
{
    ifstream fin("sate.in");
    ofstream fout("sate.out");
    int n, m, x, y;
    fin >> n >> m >> x >> y;
    for (int k = 1; k <= m; k++)
    {
        int i, j, d;
        fin >> i >> j >> d;
        if (i > j)
        {
            swap(i, j);
        }
        adj[i].push_back({j, d});
        adj[j].push_back({i, -d});
    }
    ///bfs din nodul x
    visited[x] = true;
    q.push(x);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (auto u : adj[s])
        {
            if (visited[u.first])
            {
                continue;
            }
            if (dist[u.first] == 0)
            {
                dist[u.first] = dist[s] + u.second;
            }
            else
            {
                dist[u.first] = dist[u.first], dist[s] + u.second;
            }
            visited[u.first] = true;
            q.push(u.first);
        }
    }
    fout << dist[y];
    return 0;
}

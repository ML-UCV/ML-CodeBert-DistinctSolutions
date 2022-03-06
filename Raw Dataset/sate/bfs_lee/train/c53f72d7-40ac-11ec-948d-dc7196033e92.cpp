#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n, m, x, y;
vector< pair<int, int> > adj[30005];
int dist[30005];
bool viz[30005];

void BFS()
{
    int curr, next, distanta;
    queue<int> queue;
    queue.push(x);
    viz[x] = true;
    while (!queue.empty())
    {
        curr = queue.front();
        queue.pop();
        for (auto rel : adj[curr])
        {
            next = rel.first;
            distanta = rel.second;
            if (!viz[next])
            {
                viz[next] = true;
                dist[next] = dist[curr] + distanta;

                queue.push(next);

                if (next == y)
                {
                    g << dist[y] << "\n";
                    return;
                }
            }
        }
    }
}

int main()
{

    f >> n >> m >> x >> y;
    while(m--)
    {
        int a, b, distanta;
        f >> a >> b >> distanta;
        adj[a].push_back({b, distanta});
        adj[b].push_back({a, -distanta});
    }
    BFS();
    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n, m, x, y;
vector< pair<int, int> > r[30005]; //relatia dintre x si y
int dist[30005];//distanta dintre x si nod
int viz[30005]; //frecventa

void BFS()
{
    int s, i, distanta;
    queue<int> q;
    q.push(x);
    viz[x] = 1;
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (auto j : r[s])
        {
            i = j.first;
            distanta = j.second;
            if (!viz[i])
            {
                viz[i] = 1;
                dist[i] = dist[s] + distanta;
                q.push(i);

                if (i == y)
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
    int a, b, d;
    f >> n >> m >> x >> y;
   for (int i = 1; i <= m; i++)
    {
        f >> a >> b >> d;
        r[a].push_back({b, d});
        r[b].push_back({a, -d});
    }
    BFS();
    return 0;
}
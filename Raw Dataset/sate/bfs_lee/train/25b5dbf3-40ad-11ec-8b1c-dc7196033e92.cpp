#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define MAXN 30005
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
vector <pair <int, int> > G[MAXN];
queue

<int> Q;
int n, m, dist[MAXN];
bool viz[MAXN];

void bfs(int start)
{
    viz[start] = 1;
    dist[start] = 0;
    Q.push(start);
    while(!Q.empty())
    {
        int nod = Q.front();
        Q.pop();
        for(auto it:G[nod])
        {
            if(!viz[it.first])
            {
                viz[it.first] = 1;
                if(nod < it.first)
                {
                    Q.push(it.first);
                    dist[it.first] = dist[nod] + it.second;
                }
                else
                {
                    Q.push(it.first);
                    dist[it.first] = dist[nod] - it.second;
                }
            }

        }
    }
}

int main()
{
    int n, m, X, Y, d, x, y;
    f >> n >> m >> X >> Y;
    for(int i = 1; i <= m; i++)
    {
        f >> x >> y >> d;
        G[x].push_back(make_pair(y, d));
        G[y].push_back(make_pair(x, d));
    }
    bfs(X);

    g << dist[Y];
    return 0;
}

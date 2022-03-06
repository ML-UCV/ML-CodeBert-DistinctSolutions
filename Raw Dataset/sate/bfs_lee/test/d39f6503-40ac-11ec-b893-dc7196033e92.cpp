#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream f("sate.in");
ofstream g("sate.out");

int n, m, x, y;
int dist[30001];
bool u[30001];
vector < pair < int, int > > v[30001];
queue < int > coada;

int main()
{
    f >> n >> m >> x >> y;
    while (m--)
    {
        int i, j, d;
        f >> i >> j >> d;
        v[i].push_back({j,  d});
        v[j].push_back({i, -d});
    }

    u[x] = 1;
    coada.push(x);
    while (!coada.empty())
    {
        int nod = coada.front();
        coada.pop();

        for (int i=0; i<v[nod].size(); i++)
            if (!u[v[nod][i].first])
            {
                u[v[nod][i].first] = 1;
                dist[v[nod][i].first] = dist[nod] + v[nod][i].second;
                coada.push(v[nod][i].first);
            }
    }

    g << dist[y];

    return 0;
}

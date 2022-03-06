#include <iostream>
#include <fstream>
#include <queue>
#define pb push_back
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");

vector < pair <int, int > > v[30005];
bool viz[30005];
int drum[30005];
int n, m, x, y, ans;

void parcg(int x)
{
    queue < int > q;
    q.push(x);
    viz[x] = 1;
    drum[x] = 0;
    while (!q.empty())
    {
        int nod = q.front();
        q.pop();
        for (auto it : v[nod])
        {
            if (!viz[it.first])
            {
                viz[it.first] = 1;
                if (it.first < nod) drum[it.first] = drum[nod] - it.second;
                else drum[it.first] = drum[nod] + it.second;
                q.push(it.first);
            }
        }
    }
}

main()
{
    f >> n >> m >> x >> y;

    for (int i = 1; i <= m; i++)
    {
        int a, b, x;
        f >> a >> b >> x;
        v[a].pb({ b,x });
        v[b].pb({ a,x });
    }

    parcg(x);
    g << drum[y];
    return 0;
}
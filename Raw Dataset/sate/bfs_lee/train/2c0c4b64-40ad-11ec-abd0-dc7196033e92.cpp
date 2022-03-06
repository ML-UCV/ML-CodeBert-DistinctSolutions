#include <fstream>
#include <vector>

using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
const int N = 30002;

struct pereche
{
    int nod, cost;
};

vector <pereche> g[N];
int c[N], d[N];
bool viz[N];
int n, m, X, Y;

void Aranjare()
{
    in >> n >> m >> X >> Y;
    int x, y, d;
    for(int i = 1; i <= m; i++)
    {
        in >> x >> y >> d;
        g[x].push_back({y, d});
        g[y].push_back({x, d});
    }
}

void Bfs(int a, int b)
{
    int p = 1, u = 1, now;
    c[1] = a;
    viz[a] = true;
    while(p <= u)
    {
        now = c[p];
        p++;
        for(int i = 0; i < g[now].size(); ++i)
        {
            if(viz[g[now][i].nod] == false)
            {
                if(g[now][i].nod > now)
                    d[g[now][i].nod] = d[now] + g[now][i].cost;
                else
                    d[g[now][i].nod] = d[now] - g[now][i].cost;
                u++;
                c[u] = g[now][i].nod;
                viz[g[now][i].nod] = true;
            }
        }

    }
    out << d[b];
}

int main()
{
    Aranjare();
    Bfs(X, Y);
    return 0;
}

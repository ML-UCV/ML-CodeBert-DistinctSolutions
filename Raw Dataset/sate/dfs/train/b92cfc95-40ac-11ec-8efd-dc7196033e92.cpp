#include <fstream>
#include <vector>
#define N 30001

using namespace std;

struct elem
{
    int nod, cost;
};

ifstream fin("sate.in");
ofstream fout("sate.out");

vector <elem> G[N];
int n, m, start, finish, dist[N];
bool viz[N];

void Citire()
{
    int x, y, d;
    elem e;

    fin>>n>>m>>start>>finish;

    while (m--)
    {
       fin>>x>>y>>d;

        e.cost = d;
        e.nod = y;
        G[x].push_back(e);

        e.cost = -d;
        e.nod = x;
        G[y].push_back(e);
    }
}

void Dfs(int nod)
{
    elem el;
    int i;

    if (!viz[finish])

        for (i = 0; i < G[nod].size(); ++i)
        {
            el=G[nod][i];

            if (!viz[el.nod])
            {
                dist[el.nod] = dist[nod] + el.cost;
                viz[nod] = 1;
                Dfs(el.nod);
            }
        }
}

void Afisare()
{
    fout<<dist[finish];
}

int main()
{
    Citire();
    Dfs(start);
    Afisare();
    return 0;
}

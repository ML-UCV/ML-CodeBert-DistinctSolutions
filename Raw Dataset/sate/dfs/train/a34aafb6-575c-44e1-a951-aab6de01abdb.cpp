#include <fstream>
#include <vector>
#define N 30005
using namespace std;

struct elem{
            int node, cost;
           };

ifstream fin("sate.in");
ofstream fout("sate.out");

vector <elem> G[N];
int n, st, fi, dist[N];
bool viz[N];

inline void Read()
{
    int m, x, y, d;
    elem e;

    fin>>n>>m>>st>>fi;

    while (m--)
    {
       fin>>x>>y>>d;

        e.cost = d;
        e.node = y;
        G[x].push_back(e);

        e.cost = -d;
        e.node = x;
        G[y].push_back(e);
    }
}

inline void Dfs(int node)
{
    elem vec;
    int i;

    if (!viz[fi])

        for (i = 0; i < G[node].size(); ++i)
        {
            vec=G[node][i];

            if (!viz[vec.node])
            {
                dist[vec.node] = dist[node] + vec.cost;
                viz[node] = 1;
                Dfs(vec.node);
            }
        }
}

void Write()
{
    fout<<dist[fi];
}

int main()
{
    Read();
    Dfs(st);
    Write();
    return 0;
}

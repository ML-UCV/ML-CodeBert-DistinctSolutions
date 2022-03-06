#include <iostream>
#include <fstream>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

const int NMAX = 30001, MMAX = 100024, INF=1<<31;
int lst[NMAX], vf[2*MMAX], urm[2*MMAX], w[2*MMAX], dist[NMAX], nr=0;

void Add(int x, int y, int weight)
{
    ++nr;
    vf[nr]=y;
    urm[nr]=lst[x];
    w[nr]=weight;
    lst[x]=nr;
}

void Dfs(int x);

int main()
{
    int n, m, st, fn;
    in >> n >> m >> st >> fn;
    for(int i=1; i<=n; i++) dist[i]=INF;

    for(int i=1; i<=m; i++)
    {
        int x, y, weight;
        in >> x >> y >> weight;
        Add(x, y, weight);
        Add(y, x, weight);
    }

    dist[st]=0;
    Dfs(st);

    out << dist[fn];
    return 0;
}

void Dfs(int x)
{
    for(int p=lst[x];p;p=urm[p])
    {
        int y=vf[p];
        if(dist[y]==INF)
        {
            if(y<x) dist[y]=dist[x]-w[p];
            else dist[y]=dist[x]+w[p];
            Dfs(y);
        }
    }
}

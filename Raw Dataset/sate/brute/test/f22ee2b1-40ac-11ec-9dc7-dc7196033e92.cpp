#include <iostream>
#include <fstream>

using namespace std;

ifstream in("sate.in");
ofstream out("sate.out");

const int N = 30001, M = 100025, INF=1<<31;
int lst[N], vf[2*M], urm[2*M], w[2*M], q[N], dist[N], nr=0;

void Add(int x, int y, int d);

int main()
{
    int n, m, s, fn;
    in >> n >> m >> s >> fn;
    for(int i=1; i<=n; i++) dist[i]=INF;
    for(int i=1; i<=m; i++)
    {
        int x, y, d;
        in >> x >> y >> d;
        Add(x, y, d);
        Add(y, x, d);
    }

    int st=0, dr=-1;
    q[++dr]=s;
    dist[s]=0;

    while(st<=dr)
    {
        int x=q[st++];
        for(int p=lst[x];p;p=urm[p])
        {
            int y=vf[p];
            if(dist[y]==INF)
            {
                q[++dr]=y;
                if(x<y) dist[y]=dist[x]+w[p];
                else dist[y]=dist[x]-w[p];
            }
        }
    }
    out << dist[fn];
    return 0;
}

void Add(int x, int y, int d)
{
    nr++;
    vf[nr]=y;
    w[nr]=d;
    urm[nr]=lst[x];
    lst[x]=nr;
}

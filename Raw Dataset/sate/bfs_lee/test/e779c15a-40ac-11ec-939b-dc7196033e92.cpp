#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("sate.in");
ofstream out ("sate.out");

const int N=30000;
const int M=100024;
int lst[N+1],nr,urm[2*M+1],dist[2*M+1],vf[2*M+1],d[N+1],q[N+1],fin,n;
bool viz[N+1];

void adauga (int a, int b, int l)
{
    vf[++nr]=b;
    urm[nr]=lst[a];
    lst[a]=nr;
    dist[nr]=l;
}
void bfs (int x)
{
    int st=0;
    int dr=-1;
    q[++dr]=x;
    viz[x]=true;

    while (st<=dr)
    {
        int next=q[st++];
        for (int p=lst[next];p!=0;p=urm[p])
        {
            int y=vf[p];
            if (!viz[y])
            {
                viz[y]=true;
                d[y]=d[next]+dist[p];
                q[++dr]=y;
            }
        }
    }
}
int main()
{
    int m,x,a,b,l;
    in>>n>>m>>x>>fin;
    for (int i=1;i<=m;i++)
    {
        in>>a>>b>>l;
        adauga (a,b,l);
        adauga (b,a,-l);
    }
    bfs (x);
    out<<d[fin];
    return 0;
}

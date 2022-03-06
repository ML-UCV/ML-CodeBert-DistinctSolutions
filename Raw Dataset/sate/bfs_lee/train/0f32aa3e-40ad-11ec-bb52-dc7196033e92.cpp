#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#define NMAX 30000

using namespace std;
ifstream fi("sate.in");
ofstream fo("sate.out");
int n, m, x, y, rez;
int VIZ[NMAX+5], PRE[NMAX+5];
vector <pair <int, int> > VEC[NMAX+5];
queue <int> Q;

void citire(void)
{
    int a, b, c;
    fi>>n>>m>>x>>y;
    for(int i=1; i<=m; i++)
    {
        fi>>a>>b>>c;
        VEC[a].push_back({b, c});
        VEC[b].push_back({a, -c});
    }
}

void BFS(int src)
{
    int nod, nods;
    VIZ[src]=1;
    memset(PRE, -1, sizeof(PRE));
    Q.push(src);
    while(!Q.empty())
    {
        nod=Q.front();
        Q.pop();
        for(int i=0; i<VEC[nod].size(); i++)
        {
            nods=VEC[nod][i].first;
            if(!VIZ[nods])
            {
                VIZ[nods]=1;
                PRE[nods]=nod;
                Q.push(nods);
            }
        }
    }
}

void rezolvare(void)
{
    int nod=y;
    while(PRE[nod]!=-1)
    {
        for(int i=0; i<VEC[nod].size(); i++)
            if(VEC[nod][i].first==PRE[nod])
            {
                rez+=VEC[nod][i].second;
                break;
            }
        nod=PRE[nod];
    }
}

void afisare(void)
{
    if(rez<0)
        fo<<-rez;
    else
        fo<<rez;
}

int main()
{
    citire();
    BFS(x);
    rezolvare();
    afisare();
    fi.close();
    fo.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define NM 30005
using namespace std;
ifstream in("sate.in");
ofstream out("sate.out");
vector<pii> v[NM];
queue<int> q;///nodul si distanta incpand cu ST
int n,m,st,fn,a,b,d,dist[NM],viz[NM];
pii fr;
int nod;
int verif(int n1,int n2,int n3)
{
    return(n1<=n2 && n2<=n3);
}
///dist[i] distanta de la st la i
int main()
{
    in>>n>>m>>st>>fn;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>d;
        v[a].pb(mp(b,d));
        v[b].pb(mp(a,d));
    }
    q.push(st);
    viz[st]=1;
    while(!viz[fn])
    {
        nod=q.front();
        q.pop();
        for(auto i:v[nod])
        {
            if(!viz[i.x])
            {
                if(verif(nod,i.x,st) || verif(st,i.x,nod))dist[i.x]=dist[nod]-i.y;
                else
                {
                    if(verif(nod,st,i.x) || verif(i.x,st,nod))dist[i.x]=i.y-dist[nod];
                    else dist[i.x]=dist[nod]+i.y;
                }
                q.push(i.x);
                viz[i.x]=1;
            }
        }
    }
    out<<dist[fn];
    return 0;
}
///nod   st   i.x--->diferenta  2
///nod   i.x  st---->diferenta  1
///st    nod  i.x--->suma
///st    i.x  nod--->diferenta  1
///i.x   st   nod--->diferenta  2
///i.x   nod  st---->suma

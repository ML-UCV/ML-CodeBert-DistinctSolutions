#include <fstream>
#include <cmath>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
struct nod
{
    int val,cost;
    nod *urm;
};
typedef nod *pnod;
#define nmax 30010
pnod v[nmax],p;
void ad(int x,int y,int c)
{
    p=new nod;
    p->val=y;
    p->cost=c;
    p->urm=v[x]->urm;
    v[x]->urm=p;
}
#define inf 2000000000
int dist[nmax],t[nmax];
bool use[nmax];
void bfs(int inc)
{
    int k,s;
    k=1;
    s=1;
    t[1]=inc;
    dist[inc]=0;
    use[inc]=1;
    while(k<=s)
    {
        p=v[t[k]]->urm;
        while(p)
        {
            if(use[p->val]==0)
            {
            s+=1;
            t[s]=p->val;
            use[p->val]=1;
            if(p->val>t[k])
            {
                dist[p->val]=dist[t[k]]+p->cost;
            }
            else
                dist[p->val]=dist[t[k]]-p->cost;
            }
            p=p->urm;
        }
        k+=1;
    }
}
int main()
{
    int n,m,start,finish,i,x,y,c;
    f>>n>>m>>start>>finish;
    for(i=1;i<=n;i++)
    {
        v[i]=new nod;
        v[i]->urm=0;
        dist[i]=inf;
    }
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>c;
        ad(x,y,c);
        ad(y,x,c);
    }
    bfs(start);
    g<<dist[finish];
    return 0;
}

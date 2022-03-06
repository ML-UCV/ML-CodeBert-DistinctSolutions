#include<fstream>
using namespace std;

struct nod
{
    int x,d;
    nod *urm;
};
nod *gr[30002],*q;
int n,m,X,Y,c[30005],ds[30005],viz[30005],i,x,y,d;
int inf=2000000000;

ifstream f("sate.in");
ofstream g("sate.out");

void adaug(int x,int y,int d)
{
    nod *p=new nod;
    p->x=y;
    p->d=d;
    p->urm=gr[x];
    gr[x]=p;
}

int bfs()
{
    int pr=1,ul=1;
    c[ul]=X;
    for(int i=1;i<=n;i++)
        ds[i]=inf;
    ds[X]=0;
    viz[X]=1;
    while(pr<=ul)
    {
        for(q=gr[c[pr]];q!=NULL;q=q->urm)
        {
            if(viz[q->x]==0)
            {
                if(q->x>c[pr]) ds[q->x]=min(ds[q->x],ds[c[pr]]+q->d);
                else ds[q->x]=min(ds[q->x],ds[c[pr]]-q->d);
                viz[q->x]=1;
                ul++;
                c[ul]=q->x;
            }
        }
        pr++;
    }
    return ds[Y];
}

int main()
{
    f>>n>>m>>X>>Y;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>d;
        adaug(x,y,d);
        adaug(y,x,d);
    }

    g<<bfs();

    f.close();
    g.close();
    return 0;
}

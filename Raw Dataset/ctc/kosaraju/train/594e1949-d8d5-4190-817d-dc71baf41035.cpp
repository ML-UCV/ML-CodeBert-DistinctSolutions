#include <fstream>
using namespace std;
const int N=100009;
const int M = 200001;
int lst1[N],vf1[M],n,m,L,D,nr1,urm1[M],sorttop[N],ns,lst2[N],vf2[M],urm2[M],nr2,nrcomp,nrel[N], nrv, c[N];
bool viz[N],v[N];
ifstream in("ctc.in");
ofstream out("ctc.out");
void adauga1(int x, int y)
{
    vf1[++nr1]=y;
    urm1[nr1]=lst1[x];
    lst1[x]=nr1;

}

void adauga2(int x,int y)
{
    vf2[++nr2]=y;
    urm2[nr2]=lst2[x];
    lst2[x]=nr2;

}
void dfs(int x)
{
    viz[x]=true;
    int y;
    for(int p=lst1[x]; p!=0; p=urm1[p])
    {
        y=vf1[p];
        if(!viz[y]) dfs(y);
    }
    sorttop[++ns]=x;
}

void dfs2(int x)
{
    v[x]=true;
    nrel[nrcomp]++;
    c[++nrv] = x;
    int y;
    for(int p=lst2[x]; p!=0; p=urm2[p])
    {
        y=vf2[p];
        if(!v[y]) dfs2(y);

    }

}
int main()
{
    in>>n>>m;
    for(int i=1; i<=m; i++)
    {
        in>>L>>D;
        adauga1(L,D);
        adauga2(D,L);
    }
    for(int i=1; i<=n; i++)
    {
        if(!viz[i]) dfs(i);
    }


    for(int i=ns; i>=1; i--)
    {
        if(!v[sorttop[i]])
        {
            nrcomp++;
            dfs2(sorttop[i]);

        }

    }


    out<<nrcomp<<"\n";
    int ind=1;



    for(int i=1;i<=nrcomp;i++)
    {
        for(int j=1;j<=nrel[i];j++)
        {
            out<<c[ind]<<" ";
            ind++;
        }
        out<<'\n';

    }
    return 0;



}

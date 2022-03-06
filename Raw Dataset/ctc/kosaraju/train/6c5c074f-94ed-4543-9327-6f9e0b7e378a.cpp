#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in ("ctc.in");
ofstream out ("ctc.out");

const int N=100001;
const int M=200001;

int lst[N],lst_inv[N],urm[M],urm_inv[M],vf[M],vf_inv[M],nr,q[N];
bool viz[N],viz_inv[N];
vector <int> comp[N];

void dfs (int nod)
{
    viz[nod]=true;
    for (int p=lst[nod];p!=0;p=urm[p])
    {
        int y=vf[p];
        if (!viz[y])
            dfs (y);
    }
    q[++nr]=nod;
}
void dfs_inv (int nod)
{
    viz_inv[nod]=true;
    comp[nr].push_back(nod);
    for (int p=lst_inv[nod];p!=0;p=urm_inv[p])
    {
        int y=vf_inv[p];
        if (!viz_inv[y])
            dfs_inv(y);
    }
}
void adauga (int x, int y)
{
    ++nr;
    vf[nr]=y;
    urm[nr]=lst[x];
    lst[x]=nr;
    vf_inv[nr]=x;
    urm_inv[nr]=lst_inv[y];
    lst_inv[y]=nr;
}
int main()
{
    int n,m,x,y;
    in>>n>>m;
    for (int i=1;i<=m;i++)
    {
        in>>x>>y;
        adauga (x,y);
    }
    nr=0;
    for (int i=1;i<=n;i++)
        if (!viz[i]) dfs (i);
    nr=0;
    for (int i=n;i>0;i--)
        if (!viz_inv[q[i]])
        {
            nr++;
            dfs_inv(q[i]);
        }
    out<<nr<<'\n';
    for (int i=1;i<=nr;i++)
    {
        for (int j=0;j<comp[i].size();j++)
            out<<comp[i][j]<<' ';
        out<<'\n';
    }
    return 0;
}

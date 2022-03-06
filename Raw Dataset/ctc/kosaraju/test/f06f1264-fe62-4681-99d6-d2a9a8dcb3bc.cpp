#include <fstream>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int N=100001;
const int M=2*N;

int lst[N], vf[2*M], urm[2*M], lst_inv[N], vf_inv[2*M], urm_inv[2*M], sorttop[N], ctc[2*M];
int nr, ct, cnt;

bool viz[N];

void adauga(int x, int y)
{
    ++nr;
    vf[nr]=y;
    urm[nr]=lst[x];
    lst[x]=nr;

    vf_inv[nr]=x;
    urm_inv[nr]=lst_inv[y];
    lst_inv[y]=nr;
}

void dfs1(int x)
{
    viz[x]=true;
    for(int p=lst[x]; p!=0; p=urm[p])
    {
        int y=vf[p];
        if(!viz[y])
            dfs1(y);
    }
    sorttop[++nr]=x;
}

void dfs2(int x)
{
    viz[x]=true;
    for(int p=lst_inv[x]; p!=0; p=urm_inv[p])
    {
        int y=vf_inv[p];
        if(!viz[y])
        {
        cnt++;
        ctc[cnt]=y;
        dfs2(y);
        }
    }
}

int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        fin>>x>>y;
        adauga(x,y);
    }
    nr=0;
    for(int i=1; i<=n; i++)
        if(!viz[i])
            dfs1(i);
    for(int i=1; i<=n; i++)
    viz[i]=false;
    for(int i=n; i>=1; i--)
    {
       if(!viz[sorttop[i]])
       {
         ct++;
         cnt++;
         ctc[cnt]=sorttop[i];
         dfs2(sorttop[i]);
         cnt++;
         ctc[cnt]=-1;
       }
    }
    fout<<ct<<"\n";
    for(int i=1; i<=cnt; i++)
    {
        if(ctc[i]==-1)
        fout<<"\n";
        else
        fout<<ctc[i]<<" ";
    }
    return 0;
}

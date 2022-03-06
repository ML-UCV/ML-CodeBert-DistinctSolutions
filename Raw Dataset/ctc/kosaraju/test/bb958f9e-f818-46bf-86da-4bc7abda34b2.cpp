#include <bits/stdc++.h>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

int n,m;
int vf[200001],urm[200001],last[100001],nr;
int vfT[200001],urmT[200001],lastT[100001],nrT;
int comp[100001],urmC[100001],lastC[100001],nrC;
int ord[100001],t;
bitset <100001> viz;
int k;

void adauga(int nod,int vec)
{
    vf[++nr]=vec;
    urm[nr]=last[nod];
    last[nod]=nr;
}

void adaugaT(int nod,int vec)
{
    vfT[++nrT]=vec;
    urmT[nrT]=lastT[nod];
    lastT[nod]=nrT;
}

void adaugaC(int nod,int c)
{
    comp[++nrC]=nod;
    urmC[nrC]=lastC[c];
    lastC[c]=nrC;
}

void dfs(int nod)
{
    viz[nod]=1;

    for(int k=last[nod];k;k=urm[k])
        if(!viz[ vf[k] ])
            dfs(vf[k]);

    ord[++t]=nod;
}

void dfsT(int nod,int c)
{
    viz[nod]=1;
    adaugaC(nod,c);

    for(int k=lastT[nod];k;k=urmT[k])
        if(!viz[ vfT[k] ])
            dfsT(vfT[k],c);
}

int main()
{
    in>>n>>m;

    for(int i,j,k=1;k<=m;k++)
    {
        in>>i>>j;

        adauga(i,j);
        adaugaT(j,i);
    }

    for(int i=1;i<=n;i++)
        if(!viz[i])
            dfs(i);

    viz.reset();

    for(int i=n;i>=1;i--)
        if(!viz[ ord[i] ])
            dfsT(ord[i],++k);

    out<<k<<'\n';

    for(int i=1;i<=k;i++)
    {
        for(int q=lastC[i];q;q=urmC[q])
            out<<comp[q]<<' ';
        out<<'\n';
    }

    return 0;
}

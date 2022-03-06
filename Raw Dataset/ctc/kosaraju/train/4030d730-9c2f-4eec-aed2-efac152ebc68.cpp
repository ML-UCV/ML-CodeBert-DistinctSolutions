#include <iostream>
#include <fstream>

using namespace std;

ifstream in("ctc.in");
ofstream out("ctc.out");

const int N = 100001;
const int M = 200001;
int n, m, nr, x, y, ns;
int vf[2*M], lst[N], urm[2*M];
int vf_inv[2*M], lst_inv[N], urm_inv[2*M];
int sorttop[N];
int sortare[2*N], comp, nrc;
bool viz[N];


void adauga(int x, int y){
    ++nr;
    vf[nr] = y;
    urm[nr] = lst[x];
    lst[x] = nr;
    vf_inv[nr] = x;
    urm_inv[nr] = lst_inv[y];
    lst_inv[y] = nr;
}

void dfs(int x)
{
    viz[x] = true;
    for(int p=lst[x]; p!=0; p=urm[p])
    {
        y = vf[p];
        if(!viz[y])
            dfs(y);
    }
    sorttop[++ns] = x;
}

void dfs2(int x)
{
    sortare[++nrc] = x;
    viz[x] = true;

    for(int p=lst_inv[x]; p!=0; p=urm_inv[p])
    {
        y = vf_inv[p];
        if(!viz[y])
            dfs2(y);
    }
}

int main()
{
    in>>n>>m;
    for(int i=1; i<=m; i++)
    {
        in>>x>>y;
        adauga(x, y);
    }
    for(int i=1; i<=n; i++)
        if(!viz[i])
            dfs(i);

    for(int i=1; i<=n; i++)
        viz[i] = false;

    for(int i=ns; i>=1; i--)
    {
        x = sorttop[i];
        if(!viz[x])
        {
            comp++;
            dfs2(x);
            sortare[++nrc] = -1;
        }
    }

    out<<comp<<'\n';
    for(int i=1; i<=nrc; i++)
    {
        if(sortare[i] == -1) out<<'\n';
        else out<<sortare[i]<<' ';
    }
    return 0;
}

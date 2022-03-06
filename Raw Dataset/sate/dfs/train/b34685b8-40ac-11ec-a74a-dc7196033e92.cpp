#include <bits/stdc++.h>
using namespace std;
ifstream f("sate.in");
ofstream g("sate.out");
const int N=3e4+10;
struct pereche{
    int nod;
    int cost;
};
vector <pereche> mat[N];
bitset <N> vizitat;
int n,start,stop;
bool FINAL=false;
void dfs(int x,int c)
{
    if(x==stop)
    {
        g<<c;
        FINAL=true;
        return;
    }
    for(int i=0;i<mat[x].size() && !FINAL;i++)
    {
        int nd=mat[x][i].nod,ct=mat[x][i].cost;
        if(!vizitat[nd])
        {
            vizitat[nd]=1;
            dfs(nd,c+ct);
        }
    }
}
int main()
{
    int m;
    f>>n>>m>>start>>stop;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        f>>x>>y>>z;
        pereche aux;
        aux.nod=y;
        aux.cost=z;
        mat[x].push_back(aux);
        aux.nod=x;
        aux.cost=-z;
        mat[y].push_back(aux);
    }
    dfs(start,0);
    return 0;
}

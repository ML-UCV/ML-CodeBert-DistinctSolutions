#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");
struct drum
{
    int nod,cost;
} varaux1,varaux2;

int seen [40001];
int n,x,y,distanta;
vector<drum>v[100050];
void dfs ( int nod )
{
    if(nod==y)
    {
        fout<<distanta;
        exit(0);
    }
    seen[nod]=-1;
    for(int i=0; i<v[nod].size(); i++)
        if(seen[v[nod][i].nod]==0)
        {
            distanta+=v[nod][i].cost;
            dfs(v[nod][i].nod);
            distanta-=v[nod][i].cost;
        }
}



int main()
{
    int i,m,a,b,dist;
    fin>>n>>m>>x>>y;
    for(i=0; i<m; i++)
    {
        fin>>a>>b>>dist;
        varaux1= {b,dist};
        varaux2= {a,-dist};
        v[a].push_back(varaux1);
        v[b].push_back(varaux2);
    }
    dfs(x);
    return 0;
}

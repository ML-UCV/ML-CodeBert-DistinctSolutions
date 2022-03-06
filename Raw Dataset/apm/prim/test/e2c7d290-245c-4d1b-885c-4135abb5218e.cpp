#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");
int cost[200005],mcost[200005],f[200005];
int n,m,i,j,sum;
struct muchie
{
    int nod;
    int c;
};
muchie aux;
vector<muchie> G[200005];
class cmp1
{
public:
    bool operator() (const muchie& a, const muchie& b) const
    {
        if(a.c<b.c)
            return 0;
        return 1;
    }
};
priority_queue<muchie, vector<muchie>, cmp1> pq;
int x,y,c;
int main()
{
    fin>>n>>m;
    while(m--)
    {
        fin>>x>>y>>c;
        aux.c=c;
        aux.nod=y;
        G[x].push_back(aux);
        aux.nod=x;
        G[y].push_back(aux);
    }
    f[1]=1;
    for(i=1;i<=n;i++)
        cost[i]=1005;
    for(i=0;i<G[1].size();i++)
    {
        if(G[1][i].c<cost[G[1][i].nod])
        {
            mcost[G[1][i].nod]=1;
            cost[G[1][i].nod]=G[1][i].c;
            aux.nod=G[1][i].nod;
            aux.c=G[1][i].c;
            pq.push(aux);
        }
    }
    for(j=1;j<n;j++)
    {
        while(f[pq.top().nod]==1)
            pq.pop();
        aux=pq.top();
        i=aux.nod;
        f[i]=1;
        sum+=cost[i];
        for(int l=0;l<G[i].size();l++)
            if(f[G[i][l].nod]==0)
                if(cost[G[i][l].nod]>G[i][l].c)
                {
                    mcost[G[i][l].nod]=i;
                    cost[G[i][l].nod]=G[i][l].c;
                    aux.nod=G[i][l].nod;
                    aux.c=G[i][l].c;
                    pq.push(aux);
                }
    }
    fout<<sum<<"\n";
    fout<<n-1<<"\n";
    for(i=2;i<=n;i++)
        fout<<i<<" "<<mcost[i]<<"\n";
    fin.close();
    fout.close();
    return 0;
}

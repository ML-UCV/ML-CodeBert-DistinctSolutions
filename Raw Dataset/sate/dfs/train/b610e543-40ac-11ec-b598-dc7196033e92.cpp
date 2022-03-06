#include <fstream>
#include<vector>
#define NMAX 30005
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

struct ura
{
    int nod,cost;
}aux;

vector <ura>adj[NMAX];
int n,m,x,y;
int viz[NMAX];

void dfs(int cv)
{
    for(vector<ura>:: iterator it=adj[cv].begin();it!=adj[cv].end();it++)
    {
        aux=*it;
        if(!viz[aux.nod])
        {
            viz[aux.nod]=viz[cv]+aux.cost;
            dfs(aux.nod);
        }
    }
}

int main()
{
    fin>>n>>m>>x>>y;
    int i,j,d;
    for(int bla=1;bla<=m;bla++)
    {
        fin>>i>>j>>d;
        aux.cost=d;
        aux.nod=j;
        adj[i].push_back(aux);
        aux.cost=-d;
        aux.nod=i;
        adj[j].push_back(aux);
    }
    viz[x]=1;
    dfs(x);
    fout<<max(viz[y]-viz[x],viz[x]-viz[y]);
    return 0;
}

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define maxn 300005

int n,m,x,y,D[maxn];
bool viz[maxn];

queue < int > q;

vector < pair < int , int > > G[maxn];

void Read()
{
    int aux1,aux2,co;
    freopen("sate.in","r",stdin);
    freopen("sate.out","w",stdout);
    scanf("%i %i %i %i",&n,&m,&x,&y);
    for(int i=1;i<=m;i++)
    {
        scanf("%i %i %i",&aux1,&aux2,&co);
        G[aux1].push_back(make_pair(aux2,co));
        G[aux2].push_back(make_pair(aux1,co));
    }
}

void BFS(int nodP)
{
    D[nodP] = 0;
    q.push(nodP);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        if(nod == y)
            return;
        viz[nod] = 1;
        for(int i=0;i<G[nod].size();i++)
        {
            int neigh = G[nod][i].first;
            if(viz[neigh] == 0)
            {
                if(nod < neigh)
                    D[neigh] = D[nod] + G[nod][i].second;
                else
                    D[neigh] = D[nod] - G[nod][i].second;
                q.push(neigh);
            }
        }
    }

}

int main()
{
    int aux;
    Read();
    if(x > y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    BFS(x);
    printf("%i",D[y]);
    return 0;
}

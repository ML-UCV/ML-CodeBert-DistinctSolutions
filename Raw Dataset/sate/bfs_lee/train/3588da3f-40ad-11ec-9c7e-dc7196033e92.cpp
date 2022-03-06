#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#define NMAX 30005
using namespace std;
FILE* fin = fopen("sate.in","r");
FILE* fout = fopen("sate.out","w");

vector<pair<int,int> > G[NMAX];
queue<int> Q;
int cost[NMAX],viz[NMAX];
int N,M,X,Y;

void BFS(int X);
int main()
{
    fscanf(fin,"%d %d %d %d",&N,&M,&X,&Y);
    int a,b,c;
    while(M--)
    {
        fscanf(fin,"%d %d %d",&a,&b,&c);
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,-c));
    }

    BFS(X);

    fprintf(fout,"%d\n",cost[Y]);
    return 0;
}


void BFS(int X)
{
    viz[X] = 1;
    Q.push(X);
    while(!Q.empty())
    {
        int nod = Q.front();
        Q.pop();
        for(int i = 0; i<G[nod].size();i++)
            if(!viz[G[nod][i].first])
            {
                cost[G[nod][i].first] = cost[nod] + G[nod][i].second;
                viz[G[nod][i].first] = 1;
                Q.push(G[nod][i].first);
            }
    }
}

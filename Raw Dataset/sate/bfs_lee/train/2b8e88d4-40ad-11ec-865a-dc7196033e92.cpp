#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");
const int NMax=300005;
int D[NMax],N,M,X,Y;
bool Use[NMax];
vector < pair <int, int> > G[NMax];
queue <int> Q;

void Read()
{
    fin>>N>>M>>X>>Y;
    for(int i=1;i<=M;++i)
    {
        int x,y,z;
        fin>>x>>y>>z;
        G[x].push_back(make_pair(y,z));
        G[y].push_back(make_pair(x,z));
    }
}

void BFS(int Start)
{
    D[Start]=0;
    Q.push(Start);
    while(!Q.empty())
    {
        int Nod=Q.front();
            Q.pop();
        if(Nod==Y)
            return;
        Use[Nod]=1;
        for(unsigned int j = 0 ; j < G[Nod].size(); j++)
          {
            int Vecin = G[Nod][j].first;
            if(Use[Vecin] == 0)
              {
                if(Vecin>Nod)
                D[Vecin] = D[Nod] + G[Nod][j].second;
                else
                D[Vecin]=D[Nod] - G[Nod][j].second;
                Q.push(Vecin);

              }
          }
    }


}


int main()
{
    Read();
    if(Y<X)
    {
        int z=Y;
        Y=X;
        X=z;
    }
    BFS(X);

    fout<<D[Y]<<"\n";
    return 0;
}

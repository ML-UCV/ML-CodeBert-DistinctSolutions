#include <iostream>
#include <fstream>
#include <vector>
#define Nmax 30005
using namespace std;
ifstream fin("sate.in");
ofstream fout("sate.out");

bool Use[Nmax];
int D[Nmax],N,M,X,Y;

vector < pair <int,int> > G[Nmax];

void Read()
{
    fin>>N>>M>>X>>Y;
    while(M--)
    {
        int i,j,D;
        fin>>i>>j>>D;
        G[i].push_back(make_pair(j,D));
        G[j].push_back(make_pair(i,D));
    }
}

void DFS(int Node)
{
    Use[Node]=1;
    for(int i=0;i<(int)G[Node].size();++i)
    {
        int Vecin=G[Node][i].first;
        int Dist=G[Node][i].second;

        if(!Use[Vecin])
        {
            if(Vecin>Node) D[Vecin]=D[Node]+Dist;
            else D[Vecin]=D[Node]-Dist;
            DFS(Vecin);
        }
    }
}

void Print()
{
    DFS(X);
    fout<<D[Y]<<" \n";
}

int main()
{
    Read();  Print(); return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

struct pereche
{
    int info;
    int cost;
};
vector <pereche> nod[30005];
queue <int> C;
int n, m, start, finish;
int distanta[30005];

void citire()
{
    fin>>n>>m>>start>>finish;
    int x, y, cost;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y>>cost;
        nod[x].push_back({y,cost});
        nod[y].push_back({x,-cost});
    }
}
void bfs()
{
    C.push(start);
    int last, vecin;
    while(!C.empty())
    {
        last=C.front();
        C.pop();
        for(int i=0;i<nod[last].size();i++)
        {
            vecin=nod[last][i].info;
            if(distanta[vecin]==0)
            {
                distanta[vecin]=distanta[last]+nod[last][i].cost;
                C.push(vecin);
            }
        }
    }
}
int main()
{
    citire();
    bfs();
    fout<<distanta[finish];
    return 0;
}

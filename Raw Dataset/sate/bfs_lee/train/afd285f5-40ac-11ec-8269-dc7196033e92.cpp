#include <iostream>
#include <fstream>
#include <vector>
#define Dmax 30005
using namespace std;

int n,m,x,y,d[Dmax];
bool viz[Dmax];
ifstream f("sate.in");
ofstream g("sate.out");

vector < pair <int,int> > Muchii[Dmax];

void citire()
{
    f>>n>>m>>x>>y;
    if(x>y)
    {
        int aux;
        aux=x;
        x=y;
        y=aux;
    }


    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        f>>a>>b>>c;
        Muchii[a].push_back(make_pair(b,c));
        Muchii[b].push_back(make_pair(a,c));
    }



}
void BFS(int v)
{
    int coada[Dmax],inc=1,sf=1;
    viz[x]=true;coada[sf]=v;d[v]=0;
    while(inc<=sf)
    {
        v=coada[inc];
        for(unsigned int i=0; i < Muchii[v].size(); i++)
        {
            int Vecin = Muchii[v][i].first;
            if(!viz[Vecin])
            {
                coada[++sf]=Vecin;
                viz[Vecin]= true;
                if(v>Vecin)
                    d[Vecin]=d[v]-Muchii[v][i].second;
                else
                    d[Vecin]=d[v]+Muchii[v][i].second;
            }
        }
        inc++;
    }




}

int main()
{
        citire();
        BFS(x);
            g<<d[y];
            f.close();
            g.close();
return 0;
}

#include <fstream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");



inline double modul(double x)

{

    if(x<0) return -x;

    return x;

}



struct muchie

{

    int nod;

    double cost;

} aux;



vector < muchie > G[1502];

queue <int> Q;

double z;

int n, m, i, nrd[1502];

double dmin[1502];

bool viz[1502];



void citire()

{

    int x, y;

    double z;

    double cost;

    f>>n>>m;

    for (i=1;i<=m;i++)

    {

        f>>x>>y>>cost;

        z=log(cost);

        aux.nod=y;

        aux.cost=z;

        G[x].push_back(aux);

        aux.nod=x;

        G[y].push_back(aux);

    }

    nrd[1]=1;

    for (i=2;i<=n;i++)

        dmin[i]=1000001;

}



void bellmanFord()

{

    int x, vecin;

    double cost;

    int i;

    Q.push(1);

    viz[1]=1;

    while (!Q.empty())

    {

        x=Q.front();

        Q.pop();

        for (i=0;i<G[x].size();i++)

        {

            vecin=G[x][i].nod;

            cost=G[x][i].cost;

             if(dmin[vecin]-1e-8>dmin[x]+cost)

            {

                dmin[vecin]=dmin[x]+cost;

                nrd[vecin]=nrd[x];

                if(!viz[vecin]) Q.push(vecin), viz[vecin]=1;

            }

            else if(modul(dmin[vecin]-dmin[x]-cost)<=1e-8)

            {

                nrd[vecin]=(nrd[vecin]+nrd[x])%104659;

            }

        }



    }

}



int main()

{

    citire();

    bellmanFord();

    for(i=2;i<=n;++i) g<<nrd[i]<<' ';

    return 0;

}

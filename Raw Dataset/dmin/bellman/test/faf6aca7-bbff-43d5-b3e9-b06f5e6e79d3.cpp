#include <bits/stdc++.h>
using namespace std;

ifstream f("dmin.in"); ofstream g("dmin.out");

inline double modul(double x)

{ if(x<0) return -x;

    return x;

}

vector < pair < int,double > >G[1502];

queue <int> Q;

int n, m, nrd[1502];

double dmin[1502];

bool viz[1502];

void bellmanFord()

{ int x, vecin;

    double cost;

    Q.push(1);

    viz[1]=1;

    while (!Q.empty())

    { x=Q.front();

        Q.pop();

        for (int i=0;i<G[x].size();i++)

        { vecin=G[x][i].first;

            cost=G[x][i].second;

            if(dmin[vecin]-1e-8>dmin[x]+cost)

            { dmin[vecin]=dmin[x]+cost;

                nrd[vecin]=nrd[x];

                if(!viz[vecin])

                { Q.push(vecin); viz[vecin]=1; }

            }

            else if(modul(dmin[vecin]-dmin[x]-cost)<=1e-8) nrd[vecin]=(nrd[vecin]+nrd[x])%104659;

        }

    }

}

int main()

{ double z,cost;

    f>>n>>m;

    for (int x,y,i=1;i<=m;i++)

    { f>>x>>y>>cost;

        z=log(cost);

        G[x].push_back(make_pair(y,z));

        G[y].push_back(make_pair(x,z));

    }

    nrd[1]=1;

    for (int i=2;i<=n;i++) dmin[i]=1000001;

    bellmanFord();

    for(int i=2;i<=n;++i) g<<nrd[i]<<' ';

    return 0;

}

#include<bits/stdc++.h>






using namespace std;

ifstream f("dmin.in");

ofstream g("dmin.out");

int n,m,a,b,di;

bool mat[1505][1505];

int dist[1505][1505];

vector<int>nod[1505];

vector<int>cost[1505];

double lg[1505];

int nrways[1505];

bool viz[1505];

deque<int>d;

void dijkstra()

{

    while(!d.empty())

    {

        int ro=d[0];

        for(int j=0;j<nod[ro].size();++j)

        {

            double zi=lg[ro]+log10(cost[ro][j]);

            if(!viz[nod[ro][j]])

            {

                viz[nod[ro][j]]=1;

                lg[nod[ro][j]]=zi;

                d.push_back(nod[ro][j]);

            }

            else

                if(lg[nod[ro][j]]-zi>1e-8)

                {

                    lg[nod[ro][j]]=zi;

                    d.push_back(nod[ro][j]);

                }

        }

        d.pop_front();

    }

}

int main()

{

    f>>n>>m;

    for(int i=1;i<=m;++i)

    {

        f>>a>>b>>di;

        nod[a].push_back(b);

        nod[b].push_back(a);

        mat[a][b]=mat[b][a]=1;

        dist[b][a]=dist[a][b]=di;

        cost[a].push_back(di);

        cost[b].push_back(di);

    }

    viz[1]=1;

    nrways[1]=1;

    d.push_back(1);

    dijkstra();

    for(int i=2;i<=n;++i)

        for(int j=1;j<=n;++j)

            if(mat[i][j]==1)

                if(abs(lg[i]-(lg[j]+log10(dist[i][j])))<=1e-8)

                    nrways[i]=(nrways[i]+nrways[j])%104659;

    for(int i=2;i<=n;++i)

        g<<nrways[i]<<" ";

    return 0;

}

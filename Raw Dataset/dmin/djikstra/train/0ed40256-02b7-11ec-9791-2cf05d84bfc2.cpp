#include <iostream>
#include<fstream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

const int mod=104659;

const double eps=1e-9;

set< pair<double,int> >s;

vector<int> v[1505];

vector<double> c[1505];

int modes[1505],a,b,i,n,m,x,node;

double cost[1505],d,dist,costul;

void dijkstra()

{

    s.insert(make_pair(0,1));

    while(!s.empty())

    {

        d=(*s.begin()).first;

        x=(*s.begin()).second;

        s.erase(*s.begin());

        for(i=0;i<v[x].size();i++)

        {

            node=v[x][i];dist=c[x][i];

            if(fabs(cost[node]-(d+dist))<eps)

            {

                modes[node]+=modes[x];

                if(modes[node]>=mod) modes[node]-=mod;

            }

            else

            {

                if(d+dist<cost[node])

                {

                    cost[node]=d+dist;

                    modes[node]=modes[x];

                    s.insert(make_pair(cost[node],node));

                }

            }

        }

    }

}

int main()

{

    ifstream f("dmin.in");

    ofstream g("dmin.out");

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>a>>b>>costul;

        v[a].push_back(b);

        c[a].push_back(log(costul));

        v[b].push_back(a);

        c[b].push_back(log(costul));

    }

    for(i=1;i<=n;i++)

        cost[i]=20000;

    cost[1]=0;modes[1]=1;

    dijkstra();

    for(i=2;i<=n;i++)

        {g<<modes[i]<<' ';}

    return 0;

}

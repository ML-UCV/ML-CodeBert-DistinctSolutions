#include<bits/stdc++.h>
using namespace std;

ifstream fin("dmin.in");

ofstream fout("dmin.out");



const double mini = 1e-6;



const int MOD = 104659;



long long n,m,ans[1505];

double dist[1505];



struct elem

{

    long long vecin;

    double cost;

    bool operator<(const elem &other)const

    {

        return cost>other.cost;

    }

};



priority_queue<elem>pq;

vector<elem>g[1505];



void dijkstra(int nod)

{

    pq.push({1,0.0});

    ans[1]=1;

    dist[1]=0;

    while(pq.size())

    {

        int nod=pq.top().vecin;

        double distanta=pq.top().cost;

        pq.pop();

        if(dist[nod]==distanta)

        {

            for(int i=0; i<g[nod].size(); i++)

            {

                long long vec=g[nod][i].vecin;

                double val=g[nod][i].cost;

                if(dist[vec]-(distanta+val)>mini)

                {

                    dist[vec]=distanta+val;

                    pq.push({vec,distanta+val});

                    ans[vec]=ans[nod];

                }

                else if(abs(dist[vec]-(distanta+val))<=mini)

                {

                    ans[vec]=(ans[vec]+ans[nod])%MOD;

                }

            }

        }

    }

}



int main()

{

    long long x,y,z;

    fin>>n>>m;

    for(int i=1; i<=n; i++)

    {

        dist[i]=INT_MAX;

    }

    for(int i=1; i<=m; i++)

    {

        fin>>x>>y>>z;

        g[x].push_back({y,log2((double)z)});

        g[y].push_back({x,log2((double)z)});

    }

    dijkstra(1);

    for(int i=2; i<=n; i++)

        fout<<ans[i]<<" ";

}

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <iterator>
#include <functional>
#include <climits>
#include <cmath>




using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");

vector <pair<double,int> > adj[1510];

int n,m;

int best[1510];

double err=1e-8,INF=1000000000.0;

struct cmp {

    bool operator()(pair<double,int> a,pair<double,int> b){

        if(fabs(a.first-b.first)<err)

            return 0;

        return a.first>b.first+err;

    }

};

priority_queue <pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > pb;

double dist[1510];



void dijktras(int v)

{

    int u;

    double cost2,cost1;

    dist[v]=0;

    pb.push(make_pair(0,v));

    while(!pb.empty())

    {

        v=pb.top().second;

        cost1=pb.top().first;

        pb.pop();

        for(vector<pair<double,int> >::iterator it=adj[v].begin();it!=adj[v].end();it++)

        {

            u=it->second;

            cost2=it->first;

            if(fabs(cost1+cost2-dist[u])<=err){





                best[u]+=best[v];

                best[u]=best[u]%104659;

            }

            else if(dist[u]-err>=cost1+cost2)

                {

                    best[u]=best[v];

                    best[u]=best[v]%104659;

                    dist[u]=cost2+cost1;

                    pb.push(make_pair(dist[u],u));

                }

        }

    }



}



int main()

{

    f >> n >> m;

    for(int i=0;i<m;i++)

    {

        int x,y,c;

        f >> x >> y >> c;

        adj[x].push_back(make_pair(log10(c),y));

        adj[y].push_back(make_pair(log10(c),x));

    }



    for(int i=1;i<=n;i++){

        dist[i]=INF;

    }

    best[1]=1;

    dijktras(1);



    for(int i=2;i<=n;i++)

        g << best[i] << " ";



    return 0;

}

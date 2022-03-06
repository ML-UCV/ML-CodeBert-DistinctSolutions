#include <fstream>
#include <math.h>
#include <limits.h>
#include <vector>
using namespace std;

ifstream fin("dmin.in");

ofstream fout("dmin.out");

int d[1501], heap[1501], poz[1501], node, n, m, vecin, k;

double dist[1501], cost;

vector<pair<int, double> > G[1501];

void upDate(int pozi)

{

    int po;

    while(pozi/2>0)

    {

        po=pozi/2;

        if(dist[heap[pozi]]<dist[heap[po]])

        {

            swap(poz[heap[pozi]], poz[heap[po]]);

            swap(heap[pozi], heap[po]);

            pozi=po;

        }

        else

            break;

    }

}

void downDate(int pozi)

{

    int po;

    while(pozi*2<=k)

    {

        po=pozi*2;

        if(po+1<=k && dist[heap[po]]>dist[heap[po+1]])

            po++;

        if(dist[heap[po]]<dist[heap[pozi]])

        {

            swap(poz[heap[pozi]], poz[heap[po]]);

            swap(heap[pozi], heap[po]);

            pozi=po;

        }

        else

            break;

    }

}

void read()

{

    fin>>n>>m;

    int a, b;

    double c;

    for(int i=1;i<=m;i++)

    {

        fin>>a>>b>>c;

        c=log(c);

        G[a].push_back(make_pair(b, c));

        G[b].push_back(make_pair(a, c));

    }

    for(int i=2;i<=n;i++)

        dist[i]=INT_MAX;

    d[1]=1;

}

void dijkstra()

{

    heap[++k]=1;

    poz[1]=k;

    while(k!=0)

    {

        node=heap[1];

        swap(poz[heap[1]], poz[heap[k]]);

        swap(heap[1], heap[k--]);

        downDate(1);

        for(vector<pair<int, double> >::iterator it=G[node].begin();it!=G[node].end();it++)

        {

            vecin=it->first;

            cost=it->second;

            if(dist[vecin]-dist[node]-cost>0.0000000001)

            {

                dist[vecin]=dist[node]+cost;

                d[vecin]=d[node];

                if(poz[vecin]==0)

                {

                    heap[++k]=vecin;

                    poz[vecin]=k;

                }

                upDate(poz[vecin]);

            }

            else

                if(max(dist[vecin]-dist[node]-cost, dist[node]+cost-dist[vecin])<=0.0000000001)

                    d[vecin]=(d[vecin]+d[node])%104659;

        }

    }

}

void write()

{

    for(int i=2;i<=n;i++)

        fout<<d[i]<<" ";

}

int main()

{

    read();

    dijkstra();

    write();

    return 0;

}

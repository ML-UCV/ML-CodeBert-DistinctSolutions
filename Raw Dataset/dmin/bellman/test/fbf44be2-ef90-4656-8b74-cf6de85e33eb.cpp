#include <fstream>
#include <cmath>
#include <queue>
#include <vector>
#include <climits>
using namespace std;







ifstream fin("dmin.in");

ofstream fout("dmin.out");

vector <pair<int, double> > g[1501];

int n, nrd[1501];

double d[1501];

void citire()

{

    int m, i, j;

    double c;

    fin>>n>>m;

    while(m)

    {

        m--;

        fin>>i>>j>>c;

        c=log(c);

        g[i].push_back(make_pair(j, c));

        g[j].push_back(make_pair(i, c));

    }

    fin.close();

}

void bellmanFord()

{

    int i, k;

    bool viz[1501]={0};

    queue <int> q;

    vector <pair<int, double> > :: iterator it;

    for(i=2; i<=n; i++)

        d[i]=INT_MAX;

    nrd[1]=1;

    viz[1]=1;

    q.push(1);

    while(!q.empty())

    {

        k=q.front();

        q.pop();

        for(it=g[k].begin(); it!=g[k].end(); it++)

            if(d[it->first]-1e-8>d[k]+it->second)

            {

                d[it->first]=d[k]+it->second;

                nrd[it->first]=nrd[k];

                if(!viz[it->first])

                    q.push(it->first), viz[it->first]=1;

            }

            else if(abs(d[it->first]-d[k]-it->second)<=1e-8)

                nrd[it->first]=(nrd[it->first]+nrd[k])%104659;

    }

}

int main()

{

    citire();

    bellmanFord();

    for(int i=2; i<=n; i++)

        fout<<nrd[i]<<' ';

    return 0;

}

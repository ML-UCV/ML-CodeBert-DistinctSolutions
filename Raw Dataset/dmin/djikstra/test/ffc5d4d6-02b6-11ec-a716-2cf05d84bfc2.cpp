#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>






using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");





vector<pair<int, double> > graf[1505];

int n, m;

bool inQ[1505];

double d[1505];

int nrD[1505];

priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > Q;



void read()

{

    f>>n>>m;

    int x, y;

    double c;

    for(int i = 0; i<m; i++)

    {

        f>>x>>y>>c;

        graf[x].push_back({y, log(c)});

        graf[y].push_back({x, log(c)});

    }

}



void init()

{

    for(int i = 2; i<=n; i++)

    {

        d[i] = 0x3F3F3F3F;

    }

    d[1] = log(1);

    nrD[1] = 1;

}



void dijkstra()

{

    Q.push({d[1], 1});

    inQ[1] = true;

    while(!Q.empty())

    {

        int node = Q.top().second;

        double dd = Q.top().first;

        if(abs(d[node] - Q.top().first) > 0.000001)

        {

            Q.pop();

            continue;

        }

        Q.pop();

        for(auto &p : graf[node])

        {

            if(d[node] + p.second - d[p.first] < -0.000001)

            {

                d[p.first] = d[node] + p.second;

                nrD[p.first] = nrD[node];

                Q.push({d[p.first], p.first});

            }

            else if(abs(d[node] + p.second - d[p.first]) < 0.000001)

            {

                nrD[p.first] = (nrD[p.first] + nrD[node])%104659;

            }

        }

    }

}



int main()

{

    read();

    init();

    dijkstra();

    for(int i = 2; i<=n; i++)

    {

        if(d[i] != 0x3F3F3F3F)

            g<<nrD[i]<<" ";

        else

            g<<"0 ";

    }

    return 0;

}

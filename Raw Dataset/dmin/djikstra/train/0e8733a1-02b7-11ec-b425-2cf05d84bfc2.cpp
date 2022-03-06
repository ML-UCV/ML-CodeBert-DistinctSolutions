#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <queue>






using namespace std;



bool viz[1505];

int n, m, nrdrumuri[1505];

double dmin[1505];

vector <pair <int, double> > G[1505];



priority_queue <int, vector<double>, greater<int> > q;



void read()

{

    ifstream f("dmin.in");

    f >> n >> m; double c;

    for(int i=0, x, y; i<m; ++i)

    {

        f >> x >> y >> c;

        G[x].push_back(make_pair(y,log(c)));

        G[y].push_back(make_pair(x,log(c)));

    }

    f.close();

}



void dijkstra()

{

    int vfmin;

    for(int i=2; i<=n; ++i) dmin[i]=2000000001;

    q.push(1); nrdrumuri[1]=1;

    while(!q.empty())

    {

        vfmin=q.top(); q.pop();

        if(viz[vfmin]) continue;

        viz[vfmin]=1;

        for(int i=0; i<G[vfmin].size(); ++i)

        {

            if(dmin[G[vfmin][i].first] -1e-9 > dmin[vfmin] + G[vfmin][i].second)

            {

                dmin[G[vfmin][i].first] = dmin[vfmin] + G[vfmin][i].second;

                nrdrumuri[G[vfmin][i].first]=nrdrumuri[vfmin];

                q.push(G[vfmin][i].first);

            }

            else

            if(abs(dmin[G[vfmin][i].first] - dmin[vfmin] - G[vfmin][i].second) <1e-9)

            {

                nrdrumuri[G[vfmin][i].first] = nrdrumuri[G[vfmin][i].first] + nrdrumuri[vfmin];

                if(nrdrumuri[G[vfmin][i].first] >= 104659)

                nrdrumuri[G[vfmin][i].first] -= 104659;

            }

        }

    }

}



void out()

{

    ofstream g("dmin.out");

    for(int i=2; i<=n; ++i)

        g << nrdrumuri[i] <<' ';

    g << '\n';

    g.close();

}



int main()

{

    read();

    dijkstra();

    out();

    return 0;

}

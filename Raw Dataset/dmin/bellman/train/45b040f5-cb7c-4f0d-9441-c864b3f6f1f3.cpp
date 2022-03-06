#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
ifstream f("dmin.in");

ofstream g("dmin.out");



int n,m;

vector < pair < int , double > > G[1501];

vector < int > used;

vector < double > d;

vector < int > drmin;





void read()

{

    f >> n >> m;

    used = vector < int > (n+1);

    drmin = vector < int > (n+1,0);

    for ( ; m-- ; )

    {

        int x,y,z;

        f >> x >> y >> z;

        double cst = log(z);

        G[x].push_back(make_pair(y,cst));

        G[y].push_back(make_pair(x,cst));

    }

}



void bellman ( int i )

{

    queue < int > q;

    d = vector < double > (n+1);

    for ( int k = 1; k <= n ; k++ )

        d[k] = 10000000.0;

    d[i] = 0.0;

    q.push(i);

    drmin[i] = 1;

    used[i] = 1;

    while ( !q.empty() )

    {

        int nod = q.front();

        q.pop();

        for ( vector < pair < int , double > > ::iterator j = G[nod].begin(); j != G[nod].end(); j++ )

        {

            int x = (*j).first;

            double cost = (*j).second;

            if( abs( d[x] - d[nod] - cost ) <= 0.0000001 )

            {

                drmin[x] = (drmin[x] + drmin[nod])%104659;

            }

            if ( d[x] - d[nod] - cost > 0.0000001 )

            {

                d[x] = d[nod] + cost;

                drmin[x] = drmin[nod];

                if ( !used[x] )

                {

                    q.push(x);

                    used[x] = 1;

                }

            }

        }

    }

    for ( i = 2; i <= n ; i++ )

        g << drmin[i]%104659 << " ";

}



int main()

{

    read();

    bellman(1);

    return 0;

}

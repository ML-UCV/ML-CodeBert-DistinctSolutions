#include <queue>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;



ifstream f("dmin.in");

ofstream g("dmin.out");



vector < pair < int, double > > graf[1510];

queue < int > q;

double c[1510];

int sol[1510], n, m, viz[1510];



inline double modul(double x)

{

    if(x < 0) return -x;

    return x;

}



int main()

{

    double cost;

    int x, y, cs ,nod, nod2;

    f >> n >> m;

    for(int i = 1; i <= m; ++i)

    {

        f >> x >> y >> cs;

        double z = log(cs);

        graf[x].push_back(make_pair(y, z));

        graf[y].push_back(make_pair(x, z));

    }

    c[1] = 0;

    for(int i = 2; i <= n; ++i) c[i] = 0x3f3f3f3f;

    q.push(1);

    sol[1] = 1;

    viz[1] = 1;

    while(!q.empty())

    {

        nod = q.front();

        q.pop();

        for(int i = 0; i < graf[nod].size(); ++i)

        {

            nod2 = graf[nod][i].first;

            cost = graf[nod][i].second;

            if(c[nod2] - 1e-8 > c[nod] + cost)

            {

                c[nod2] = c[nod] + cost;

                sol[nod2] = sol[nod];

                if(!viz[nod2]) q.push(nod2), viz[nod2] = 1;

            }

            else if( modul( c[nod2] - c[nod] - cost ) <= 1e-8 )

            {

                sol[nod2] = (sol[nod2] + sol[nod]) % 104659;

            }

        }

    }

    for(int i = 2; i <= n; ++i) g << sol[i] << ' ';

}

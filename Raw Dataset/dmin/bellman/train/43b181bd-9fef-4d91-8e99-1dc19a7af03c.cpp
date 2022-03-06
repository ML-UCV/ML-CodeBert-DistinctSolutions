#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <string.h>


using namespace std;



fstream f("dmin.in", ios::in);

fstream g("dmin.out", ios::out);



const int nmax = 1505;

const double INF = 100000.0;

const double eps = 0.00001;

const int modulo = 104659;



vector < pair<int, double> > a[nmax];



double c, cost;

double d[nmax];

int cnt[nmax], viz[nmax];

int n, m, x, y, i;



void read()

{

    f >> n >> m;

    for (i = 1; i <= m; i++)

    {

        f >> x >> y >> c;

        cost = log(c);

        a[x].push_back(make_pair(y, cost));

        a[y].push_back(make_pair(x, cost));

    }

}



void bellman()

{

    queue <int> q;

    double dist;

    int nc;

    for (i = 2; i <= n; i++) d[i] = INF;

    q.push(1);

    d[1] = 0;

    viz[1] = 1;

    cnt[1] = 1;

    while (!q.empty())

    {

        nc = q.front(); q.pop();

        dist = d[nc];

        viz[nc] = 0;

        for (vector< pair<int, double> >::iterator it = a[nc].begin(); it != a[nc].end(); ++it)

        {

            if (fabs(dist + it->second - d[it->first]) < eps)

            {

                cnt[it->first] = (cnt[it->first] + cnt[nc]) % modulo;

                if (!viz[it->first])

                {

                    q.push(it->first);

                    viz[it->first] = 1;

                }

            }

            else if (dist + it->second < d[it->first])

            {

                d[it->first] = dist + it->second;

                cnt[it->first] = cnt[nc];

                if (!viz[it->first])

                {

                    q.push(it->first);

                    viz[it->first] = 1;

                }

            }

        }

    }

}



int main()

{

    read();

    bellman();

    for (i = 2; i <= n; i++) g << cnt[i] << " ";

    return 0;

}

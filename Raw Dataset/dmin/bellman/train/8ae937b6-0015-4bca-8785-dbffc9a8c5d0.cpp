#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

const int NMAX = 1505;
const double eps = 1e-10;
const double inf = 100000.0;
const int MOD = 104659;

using namespace std;

ifstream f("dmin.in");
ofstream g("dmin.out");

double Dmin[NMAX];
int N,M,x,y,c;
int d[NMAX];
vector < pair<int,double> > v[NMAX];
queue <int> Q;
bool inQueue[NMAX];

void bellmanford()
{
    for (int i = 1; i <= N; ++i)
    {
        Dmin[i] = inf;
    }

    Q.push(1);
    d[1] = 1;
    Dmin[1] = 0.0;
    inQueue[1] = true;

    while(!Q.empty())
    {
        int nod = Q.front();
        for (int i = 0; i < v[nod].size(); ++i)
        {
            int vecin = v[nod][i].first;
            double costEnergie = v[nod][i].second;

            if (Dmin[nod] + costEnergie - Dmin[vecin] < -eps)
            {
                d[vecin] = d[nod];
                Dmin[vecin] = Dmin[nod] + costEnergie;
                if (!inQueue[vecin])
                {
                    Q.push(vecin);
                    inQueue[vecin] = true;
                }
            }
            else
            {
                if (fabs(Dmin[nod] + costEnergie - Dmin[vecin]) <= eps)
                {
                    d[vecin] = (d[vecin] + d[nod]) % MOD;
                    if (!inQueue[vecin])
                    {
                        Q.push(vecin);
                        inQueue[vecin] = true;
                    }
                }
            }
        }

        Q.pop();
        inQueue[nod] = false;
    }
}

int main()
{
    f >> N >> M;

    for (int i = 1; i <= M; ++i)
    {
        f >> x >> y >> c;
        double newc = log(c);
        v[x].push_back(make_pair(y,newc));
        v[y].push_back(make_pair(x,newc));
    }

    bellmanford();

    for (int i = 2; i <= N; ++i)
    {
        g << d[i] << " ";
    }

    f.close();
    g.close();
    return 0;
}

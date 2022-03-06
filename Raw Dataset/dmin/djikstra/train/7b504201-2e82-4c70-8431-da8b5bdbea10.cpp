#include <fstream>
#include <cmath>
#include <queue>
#include <vector>
#include <limits>
using namespace std;



const int MAXN = 1502;

const int MODULO = 104659;

const double EPSILON = 1e-10;



ifstream in("dmin.in");

ofstream out("dmin.out");



int n;

vector<int> vecini[MAXN];

vector<double> cost[MAXN];





struct nod_dijk

{

    int nod;

    double dist;

    bool operator < (const nod_dijk b) const

    {

        return dist > b.dist;

    }

};



priority_queue<nod_dijk> heap;



void citire()

{

    int m;

    in >> n >> m;

    for (int i = 1;i <= m;++i)

    {

        int a, b, c;

        in >> a >> b >> c;



        vecini[a].push_back(b);

        cost[a].push_back(log((double)c));





        vecini[b].push_back(a);

        cost[b].push_back(log((double)c));

    }

}



double d[MAXN];

int p[MAXN];



void dijkstra()

{

    for (int i = 0;i < MAXN;++i)

    {

        d[i] = numeric_limits<double>::max();

        p[i] = 0;

    }

    heap.push((nod_dijk){1,0});

    d[1] = 0;

    p[1] = 1;

    while(!heap.empty())

    {

        int nod = heap.top().nod;

        double dist = heap.top().dist;

        heap.pop();

        if(abs(d[nod] - dist) > EPSILON)

            continue;

        p[nod] = 0;

        for(unsigned int i = 0;i < vecini[nod].size();++i)

        {

            int vecin = vecini[nod][i];

            double c = cost[nod][i];

            if (d[vecin] == numeric_limits<double>::max())

                continue;

            if (abs(d[vecin] + c - d[nod]) <= EPSILON)

                p[nod] += p[vecin];

        }

        if(p[nod] == 0)

            p[nod] = 1;

        p[nod] %= MODULO;



        for(unsigned int i = 0;i < vecini[nod].size();++i)

        {

            int vecin = vecini[nod][i];

            double c = cost[nod][i];

            if (d[nod] + c < d[vecin])

            {

                d[vecin] = d[nod] + c;

                heap.push((nod_dijk){vecin, d[vecin]});

            }

        }

    }

}



int main()

{

    citire();

    dijkstra();

    for (int i = 2;i <= n;++i)

        out << p[i] << ' ';

    out << '\n';

    return 0;

}

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;



const int NMAX = 400000;



struct muchie

{

    int u, v, c, pus;

};



muchie x[NMAX + 5];

int t[200005], h[200005];



int varf(int x)

{

    while(t[x] != x)

        x = t[x];

    return x;

}



void unire(int x, int y)

{

    if(h[x] > h[y])

        t[y] = x;

    else

    {

        if(h[x] < h[y])

            t[x] = y;

        else

        {

            t[y] = x;

            ++h[x];

        }

    }

}



bool cmp(muchie a, muchie b)

{

    return a.c<b.c;

}

int main()

{

    ifstream fin("apm.in");

    ofstream fout("apm.out");

    int n, m, cost, i;

    fin>>n>>m;

    for(i = 1; i <= n; ++i)

        t[i] = i, h[i] = 1;

    for(i = 1; i <= m; ++i)

        fin>>x[i].u >> x[i].v>>x[i].c;

    cost = 0;

    sort(x + 1, x + m + 1, cmp);

    int rx, ry, ms;

    for(ms = 0, i = 1; ms < n-1 && i <= m; ++i)

    {

        rx = varf(x[i].u);

        ry = varf(x[i].v);

        if(rx != ry)

        {

            unire(rx, ry);

            x[i].pus = 1;

            cost = cost + x[i].c;

            ++ms;

        }

    }

    fout<<cost<<'\n';

    fout<<ms<<'\n';

    for(i = 1; i <= m; ++i)

    {

        if(x[i].pus)

            fout<<x[i].u<<' '<<x[i].v<<'\n';

    }

    return 0;

}

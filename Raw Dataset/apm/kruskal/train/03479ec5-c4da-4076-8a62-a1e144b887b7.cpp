#include <iostream>
#include <algorithm>
#include <fstream>


using namespace std;

ifstream f("apm.in");

ofstream g("apm.out");



const int N_MAX = 400010;

int n, m, i, TOTAL = 0, TOP = 0, T[N_MAX], RG[N_MAX];

pair<int, int> SOL[N_MAX];

struct pct

{

    int x, y, cost;

} V[N_MAX];



bool Compara(pct a, pct b)

{

    return a.cost < b.cost;

}



int Find(int nod)

{

    while (nod != T[nod])

        nod = T[nod];

    return nod;

}



void Unire(int x, int y)

{

    if (RG[x] < RG[y])

        T[x] = y;

    else

    if (RG[x] > RG[y])

        T[y] = x;

    else

    if (RG[x] == RG[y])

    {

        T[x] = y;

        ++RG[y];

    }

}



void Rezolvare()

{

    for (int i = 1; i <= m; ++i)

    {

        int tatal_x = Find(V[i].x);

        int tatal_y = Find(V[i].y);

        if (tatal_x != tatal_y)

        {

            Unire(tatal_x, tatal_y);

            SOL[++TOP].first = V[i].x;

            SOL[TOP].second = V[i].y;

            TOTAL += V[i].cost;

        }

    }

}



int main()

{

    f >> n >> m;

    for (i = 1; i <= m; ++i)

        f >> V[i].x >> V[i].y >> V[i].cost;

    sort(V + 1, V + m + 1, Compara);

    for (i = 1; i <= n; ++i)

        T[i] = i;

    Rezolvare();

    g << TOTAL << '\n' << TOP << '\n';

    for (i = 1; i <= TOP; ++i)

        g << SOL[i].first << " " << SOL[i].second << '\n';

    return 0;

}

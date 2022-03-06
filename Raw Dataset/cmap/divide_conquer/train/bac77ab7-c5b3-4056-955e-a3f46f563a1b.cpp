#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const int NMAX = 100001;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct punct

{

    int x, y;

};



punct v[NMAX], Tmp[NMAX];

int N;



bool compx(const punct &A, const punct &B)

{

    return A.x < B.x;

}



bool compy(const punct &A, const punct &B)

{

    return A.y < B.y;

}



inline long long patrat(long long x)

{

    return x * x;

}



long long dist2(const punct &A, const punct &B)

{

    return patrat(A.x - B.x) + patrat(A.y - B.y);

}



long long distMin(int p, int u)

{

    long long dmin = 0x7FFFFFFFFFFFFFFFLL;

    for(int i = p; i < u; i++)

        for(int j = i + 1; j <= u; j++)

        {

            long long dij = dist2(v[i], v[j]);

            if(dmin > dij)dmin = dij;

        }

    return dmin;

}



long long calcdist(int p, int u)

{

    if(u - p < 3)

        return distMin(p, u);

    int m = (p + u) / 2;

    long long d1 = calcdist(p, m);

    long long d2 = calcdist(m, u);

    long long dd = min(d1, d2);

    int k = 0;

    for(int i = p; i <= u; i++)

        if(patrat(v[i].x - v[m].x) < dd)

            Tmp[++k] = v[i];

    sort(Tmp + 1, Tmp + k + 1, compy);

    for(int i = 1; i < k; i++)

        for(int j = i + 1; j <= k && patrat(Tmp[j].y - Tmp[i].y) < dd; j++)

        {

            d1 = dist2(Tmp[i], Tmp[j]);

            if(dd > d1)dd = d1;

        }

    return dd;

}



int main()

{

    f >> N;

    for(int i = 1; i <= N; i++)

        f >> v[i].x >> v[i].y;

    sort(v + 1, v + N + 1, compx);

    g << fixed << setprecision(6) << sqrt(calcdist(1, N));

    return 0;

}

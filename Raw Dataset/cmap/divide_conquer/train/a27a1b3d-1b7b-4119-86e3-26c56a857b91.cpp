#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

const int NMAX = 100001;

const long long INF = 0x7FFFFFFFFFFFFFFFLL;



struct punct

{

    int x, y;

};



punct P[NMAX], tmp[NMAX];

int N;



bool compx(const punct& P1, const punct& P2)

{

    return P1.x < P2.x;

}



bool compy(const punct& P1, const punct& P2)

{

    return P1.y < P2.y;

}



inline long long sqr(const long long& x)

{

    return x * x;

}



inline long long dist2(const punct& P1, const punct& P2)

{

    return sqr(P1.x - P2.x) + sqr(P1.y - P2.y);

}



long long distmin(int st, int dr)

{

    long long dmin = INF;

    for(int i = st; i < dr; i++)

        for(int j = i + 1; j <= dr; j++)

        {

            long long dij = dist2(P[i], P[j]);

            if(dij < dmin)

                dmin = dij;

        }

    return dmin;

}



void interclas(const int& st, const int& M, const int& dr)

{

    int i = st;

    int j = M + 1;

    int k = st;

    for(; i <= M && j <= dr; k++)

        if(compy(P[i], P[j]))

            tmp[k] = P[i++];

        else

            tmp[k] = P[j++];

    while(i <= M)

        tmp[k++] = P[i++];

    while(j <= dr)

        tmp[k++] = P[j++];

}



long long calcDmin(int st, int dr)

{

    if(dr - st < 4)

    {

        sort(P + st, P + dr + 1, compy);

        return distmin(st, dr);

    }

    int M = (st + dr) / 2;

    int x = P[M].x;

    long long d = min(calcDmin(st, M), calcDmin(M, dr));

    interclas(st, M, dr);

    int k = 0;

    for(int i = st; i <= dr; i++)

    {

        P[i] = tmp[i];

        if(sqr(P[i].x - x) < d)

            tmp[++k] = P[i];

    }

    for(int i = 1; i < k; i++)

        for(int j = i + 1; j <= k && sqr(tmp[j].y - tmp[i].y) < d; j++)

        {

            long long dc = dist2(tmp[i], tmp[j]);

            if(dc < d)

                d = dc;

        }

    return d;

}



int main()

{

    f >> N;

    for(int i = 1; i <= N; i++)

        f >> P[i].x >> P[i].y;

    sort(P + 1, P + N + 1, compx);

    g << fixed << setprecision(6) << sqrt(calcDmin(1, N));

    return 0;

}

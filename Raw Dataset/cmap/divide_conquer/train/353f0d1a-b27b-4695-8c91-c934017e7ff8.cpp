#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

const long long INF = 0x7FFFFFFFFFFFFFFFLL;

struct punct

{

    int x, y;

} P[100001], Tmp[100001];

int N;

bool compx(const punct &A, const punct &B)

{

    return A.x < B.x;

}

bool compy(const punct &A, const punct &B)

{

    return A.y < B.y;

}

inline long long sqr(long long v)

{

    return v * v;

}

long long dist2(const punct&A, const punct&B)

{

    return sqr(A.x - B.x) + sqr(A.y - B.y);

}

long long distmin(int p, int u)

{

    long long dmin = INF;

    for(int i = p; i < u; i++)

        for(int j = i + 1; j <= u; j++)

        {

            long long d = dist2(P[i], P[j]);

            dmin = max(d, dmin);

        }

    return dmin;

}

long long calcdmin(int p, int u)

{

    if(u - p < 3)

        return distmin(p, u);

    int m = p + (u - p) / 2;

    long long d = min(calcdmin(p, m), calcdmin(m, u));

    int k = 0;

    for(int i = p; i <= u; i++)

        if(sqr(P[i].x - P[m].x) < d)

            Tmp[++k] = P[i];

    sort(Tmp + 1, Tmp + k + 1, compy);

    for(int i = 1; i < k; i++)

        for(int j = i + 1; j <= k && sqr(Tmp[j].y - Tmp[i].y) < d; j++)

        {

            long long dc = dist2(Tmp[i], Tmp[j]);

            d = min(dc, d);

        }

    return d;

}

int main()

{

    f >> N;

    for(int i = 1; i <= N; i++)

        f >> P[i].x >> P[i].y;

    sort(P + 1, P + N + 1, compx);

    g << fixed << setprecision(6) << sqrt(calcdmin(1, N));



    return 0;

}

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

            dmin = min(d, dmin);

        }

    return dmin;

}

void interclasare(int p, int m, int u)

{

    int k = p, i = p, j = m + 1;

    while(i <= m && j <= u)

        if(P[i].y < P[j].y)

            Tmp[k++] = P[i++];

        else

            Tmp[k++] = P[j++];

    while(i <= m)

        Tmp[k++] = P[i++];

    while(j <= u)

        Tmp[k++] = P[j++];

}

long long calcdmin(int p, int u)

{

    if(u - p < 3)

    {

        sort(P + p, P + u + 1, compy);

        return distmin(p, u);

    }

    int m = p + (u - p) / 2;

    int x = P[m].x;

    long long d = min(calcdmin(p, m), calcdmin(m, u));

    interclasare(p, m, u);

    int k = 0;

    for(int i = p; i <= u; i++)

    {

        P[i] = Tmp[i];

        if(sqr(P[i].x - x) < d)

            Tmp[++k] = P[i];



    }



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

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;



const int NMAX = 100001;

const long long INF = 0x7FFFFFFFFFFFFFFLL;

struct punct {

    int x, y;

};

punct P[NMAX], tmp[NMAX];

int N;

bool compX(const punct &A, const punct &B) {

    return A.x < B.x;

}



bool compY(const punct &A, const punct &B) {

    return A.y < B.y;

}



inline long long sqr(long long v) {

    return v*v;

}



long long dist(const punct &A, const punct &B) {

    return sqr(A.x - B.x) + sqr(A.y - B.y);

}



long long distMin(int p, int u) {

    long long dMin = INF;

    for(int i = p; i < u; i++)

        for(int j = i+1; j <= u; j++) {

            long long d = dist(P[i], P[j]);

            if(dMin > d) dMin = d;

        }

    return dMin;

}



long long calcDmin(int p, int u) {

    if(u-p < 4) {

        sort(P+p, P+u+1, compY);

        return distMin(p, u);

    }

    int m = (p+u) / 2,

        x = P[m].x;

    long long d = min(calcDmin(p, m), calcDmin(m, u));

    merge(P+p, P+m+1, P+m+1, P+u+1, tmp+p, compY);

    int k = 0;

    for(int i = p; i <= u; i++) {

        P[i] = tmp[i];

        if(sqr(P[i].x - x) < d)

            tmp[++k] = P[i];

    }

    for(int i = 1; i < k; i++)

        for(int j = i+1; j <= k && sqr(tmp[j].y - tmp[i].y) < d; j++) {

            long long d1 = dist(tmp[i], tmp[j]);

            if(d > d1) d = d1;

        }

    return d;

}



int main()

{

    freopen("cmap.in", "r", stdin);

    freopen("cmap.out", "w", stdout);



    scanf("%i", &N);

    for(int i = 1; i <= N; i++)

        scanf("%i%i", &P[i].x, &P[i].y);

    sort(P+1, P+N+1, compX);

    printf("%.6f", sqrt(calcDmin(1, N)));

    return 0;

}

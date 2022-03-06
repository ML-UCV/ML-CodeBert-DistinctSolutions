#include <bits/stdc++.h>
using namespace std;

typedef long long i64;



const i64 INF = 1LL << 62;

const int NMAX = 100005;



struct PII {

    int x, y;



    inline PII() { }

    inline PII(int _x, int _y) {

        x = _x;

        y = _y;

    }

};



vector<PII> vx, vy;

PII aux[NMAX];



bool cmp_x(const PII &a, const PII &b) {

    return (a.x==b.x) ? (a.y < b.y) : (a.x < b.x);

}



bool cmp_y(const PII &a, const PII &b) {

    return (a.y==b.y) ? (a.x < b.x) : (a.y < b.y);

}



inline i64 dist(const PII &a, const PII &b) {

    return i64(a.x - b.x) * (a.x - b.x) + i64(a.y - b.y) * (a.y - b.y);

}



i64 ant(int st, int dr) {

    if(dr==st) {

        return INF;

    }

    if(dr-st<=2) {

        i64 ant = INF;



        for(int i=st; i<=dr; ++i)

        for(int j=i+1; j<=dr; ++j)

            ant = min(ant, dist(vx[i], vx[j]));



        sort(vy.begin()+st, vy.begin()+dr+1, cmp_y);



        return ant;

    }



    int med, puf;

    i64 ans;



    puf = 0;

    med = (st + dr) / 2;

    ans = min(ant(st, med), ant(med+1, dr));



    merge(vy.begin()+st, vy.begin()+med+1, vy.begin()+med+1, vy.begin()+dr+1, aux, cmp_y);

    for(int i=st; i<=dr; ++i)

        vy[i] = aux[i - st];



    for(int i=st; i<=dr; ++i)

        if(i64(vx[med].x-vy[i].x)*i64(vx[med].x-vy[i].x)<=ans)

            aux[puf++] = vy[i];



    for(int i=0; i<puf; ++i)

    for(int j=i+1; j<puf && j-i<8; ++j)

        ans = min(ans, dist(aux[i], aux[j]));



    return ans;

}



int main(void) {

    freopen("cmap.in", "r", stdin);

    freopen("cmap.out", "w", stdout);

    int n;



    scanf("%d", &n);

    vx.resize(n);

    for(int i=0; i<n; ++i)

        scanf("%d%d", &vx[i].x, &vx[i].y);



    sort(vx.begin(), vx.end(), cmp_x);

    vy = vx;



    printf("%.6f\n",sqrt(1.*ant(0, n-1)));



    fclose(stdin);

    fclose(stdout);

    return 0;

}

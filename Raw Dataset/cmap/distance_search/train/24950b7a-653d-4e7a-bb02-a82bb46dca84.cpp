#include <bits/stdc++.h>




using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");



const int NMax = 100001;

const long double INF = 10000000000;



struct point{

    long double x,y;

};



point a[NMax];

int n;



bool cmp(point x, point y){

    return (x.x < y.x);

}

long double dist(point a, point b){

    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

}

int main()

{

    f >> n;

    for(int i = 1; i <= n; ++i)

        f >> a[i].x >> a[i].y;

    sort(a + 1, a + 1 + n,cmp);



    long double t = INF;



    for(int i = 1; i <= n; ++i){

        for(int j = i + 1; j <= n; ++j){

            if(a[j].x - a[i].x > t)

                break;

            t = min(t,dist(a[i],a[j]));

        }

    }

    g << fixed << setprecision(6) << t << '\n';

    return 0;

}

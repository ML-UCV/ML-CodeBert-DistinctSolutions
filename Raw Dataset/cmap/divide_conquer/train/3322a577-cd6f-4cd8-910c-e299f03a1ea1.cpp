#include <bits/stdc++.h>


using namespace std;



const int Nmax = 1e5+5;



int n,i;

struct Point

{

    int x, y;

};

Point a[Nmax], aux[Nmax];



long long dist(Point a, Point b)

{

    return 1LL * (a.x-b.x) * (a.x-b.x) + 1LL * (a.y-b.y) * (a.y-b.y);

}



bool cmp_x(Point a, Point b)

{

    if(a.x==b.x) return a.y<b.y;

    return a.x<b.x;

}



bool cmp_y(Point a, Point b)

{

    if(a.y==b.y) return a.x<b.x;

    return a.y<b.y;

}



long long solve(int st, int dr)

{

    long long ans = LLONG_MAX;

    int mid = (st+dr)/2, l = a[mid].x, i, j;



    if(dr-st<=2)

    {

         sort(a+st, a+dr+1, cmp_y);



        for(i=st; i<=dr; ++i)

        for(j=i+1; j<=dr; ++j)

        ans = min(ans, dist(a[i], a[j]));



        return ans;

    }



    ans = min(solve(st, mid), solve(mid+1, dr));

    merge(a+st, a+mid+1, a+mid+1, a+dr+1, aux, cmp_y);



    int nr = 0;

    for(i=st; i<=dr; ++i)

    {

        a[i] = aux[i-st];

        if( 1LL * (l - a[i].x) * (l - a[i].x) <= ans ) aux[nr++] = a[i];

    }



    for(i=0; i<nr; ++i)

    for(j=i+1; j<=i+7 && j<nr; ++j)

        ans = min(ans, dist(aux[i], aux[j]));



    return ans;

}



int main()

{

    freopen("cmap.in", "r", stdin);

    freopen("cmap.out", "w", stdout);



    scanf("%d", &n);



    for(i=1; i<=n; ++i)

        scanf("%d%d", &a[i].x, &a[i].y);



    sort(a+1, a+n+1, cmp_x);



    printf("%.6f\n", sqrt(solve(1,n)));



    return 0;

}

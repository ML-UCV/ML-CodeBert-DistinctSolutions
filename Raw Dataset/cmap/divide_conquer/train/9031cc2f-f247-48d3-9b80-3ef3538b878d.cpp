#include <bits/stdc++.h>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");





struct point {int x,y;} v[100010], v1[100010];



int cmp1 (point a, point b)

{

    return a.x < b.x;

}



int cmp2 (point a, point b)

{

    return a.y < b.y;

}



long long sqr (int x)

{

    return 1LL*x*x;

}



long long dist (point a, point b)

{

    return 1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y);

}



long long solve (int st, int dr)

{

    if (st>=dr) return 1e18;;

    if (st+1==dr)

    {

        if (v[dr].y < v[st].y) swap (v[st],v[dr]);

        return dist (v[st], v[dr]);

    }



    int mid=(st+dr)/2, midx=v[mid].x;

    long long sol = min (solve (st,mid), solve (mid+1,dr));

    merge (v+st, v+mid+1, v+mid+1, v+dr+1, v1+st, cmp2);

    int nr=0;

    for (int i=st; i<=dr; i++)

    {

        v[i]=v1[i];

        if (1LL*(v1[i].x-midx)*(v1[i].x-midx) <= sol) v1[++nr]=v1[i];

    }

    for (int i=1; i<=nr; i++)

        for (int j=i+1; j<=nr && 1LL*(v1[i].y-v1[j].y)*(v1[i].y-v1[j].y)<=sol; j++)

            sol = min (sol, dist(v1[i],v1[j]));

    return sol;

}



int main()

{

    int n;

    fin>>n;

    for (int i=1; i<=n; i++) fin>>v[i].x>>v[i].y;

    sort (v+1, v+1+n, cmp1);

    fout<<setprecision(8)<<fixed<<sqrt(solve(1,n));



    fin.close();

    fout.close();

    return 0;

}

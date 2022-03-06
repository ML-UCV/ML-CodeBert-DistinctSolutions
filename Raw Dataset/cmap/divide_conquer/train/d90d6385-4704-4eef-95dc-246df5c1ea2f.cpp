#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;



ofstream g("cmap.out");



int n, i, j;

double s[100005], mn=2e9;

struct point{

    double x, y;

}v[100001];



bool comp(point a,point b)

{

    if (a.x==b.x)

        return a.y<b.y;

    return a.x<b.x;

}





double dist(point a,point b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}



bool comp2(point a,point b)

{

    if (a.y == b.y)

        return a.x < b.x;

    return a.y < b.y;

}



double Min(int st,int dr)

{

    if (dr==st)

        return 2e9;

    if (dr==st+1)

        return dist(v[st],v[dr]);



    vector <point> A, B;

    int i = (st+dr)/2;

    double d1, d2;

    d1 = Min(st, i);

    d2 = Min(i, dr);

    mn = min(d1,min(mn, d2));



    int sav = i-1;

    double m = v[i].x;

    while (abs(m - v[sav].x) < mn && sav > 0)

    {

        A.push_back(v[sav]);

        sav--;

    }



    sav = i;

    while (abs(v[sav].x - m) < mn && sav <= n)

    {

        B.push_back(v[sav]);

        sav++;

    }



    sort (A.begin(),A.end(),comp2);

    sort (B.begin(),B.end(),comp2);



    int j = 0;

    if (B.size() != 0 && A.size() != 0)

    {

        for (i = 0; i < A.size(); i++)

        {

            for (j; j + 1 < B.size() && B[j+1].y + mn < A[i].y; ++j);



            sav = j;

            while (sav >= 0 && abs(B[sav].y-A[i].y) < mn)

                mn = min(dist(B[sav--],A[i]), mn);



            while (j + 1 < B.size() && abs(B[j+1].y-A[i].y) < mn)

                mn = min(dist(B[++j],A[i]), mn);

        }

    }



    return mn;

}



int main()

{

    freopen("cmap.in","r",stdin);

    scanf("%d",&n);

    for (int i=1;i<=n;i++)

        scanf("%lf%lf", &v[i].x, &v[i].y);



    sort(v+1,v+n+1,comp);



    g<<fixed;

    g<<setprecision(6)<<Min(1,n);





    return 0;

}

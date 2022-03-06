#include <fstream>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;



ofstream xout("cmap.out");



int n,i;





int p,q;

struct punct{

long long x,y;

}a[100001],aux[100001];



bool cmp(punct a, punct b)

{

    return a.x<b.x;

}

bool cmp2(punct a, punct b)

{

    return a.y<b.y;

}



double dist(punct a, punct b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}



double solutie(int l, int r)

{

    double mini=1000000000;



    if(r-l<3)

    {

        for(int i=l;i<r;++i)

            for(int j=i+1;j<=r;++j)

        {

            double d=dist(a[i],a[j]);

            if(d<mini) mini=d;

        }



        return mini;

    }



    double st=solutie(l,(l+r)/2);

    double dr=solutie((l+r)/2+1, r);



    double mid=(a[(l+r)/2].x+a[(l+r)/2+1].x)/2.0;



    int nr=0;



    for(int i=l;i<=r;++i)

    {

        if(fabs(a[i].x-mid)<=min(st,dr)) aux[++nr]=a[i];

    }



    sort(aux+1,aux+nr+1,cmp2);



    double sol=min(st,dr);



    for(int i=1;i<nr;++i)

        for(int j=i+1;j<=min(nr,i+7);++j)

            sol=min(sol,dist(aux[i],aux[j]));





    return sol;

}

int main()

{

    freopen("cmap.in","r",stdin);





        scanf("%d", &n);

    for(i=1;i<=n;++i)

    {

        scanf("%d", &p);

        scanf("%d", &q);

        a[i].x=p;

        a[i].y=q;

    }



    sort(a+1,a+n+1,cmp);



    xout<<setprecision(6)<<fixed<<solutie(1,n);



    return 0;

}

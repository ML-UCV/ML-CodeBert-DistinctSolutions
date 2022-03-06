#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct punct{long long x, y;};

punct a[100002],b[100002];



int n,i,j;



bool compy(punct a,punct b)

{

    if(a.y<b.y)

        return 1;

    if(a.y==b.y)

    {

        if(a.x<b.x)

            return 1;

    }

    return 0;

}



long double dist(punct v1[], int x, punct v2[], int y)

{

    long long x1=v1[x].x;

    long long x2=v2[y].x;

    long long y1=v1[x].y;

    long long y2=v2[y].y;

    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}



long double cmap(int st,int dr)

{



    if(dr-st<3)

    {

        long double S=1000000000.0;

        for(int m=st;m<=dr;m++)

        {

            for(int p=m+1;p<=dr;p++)

            {

                long double d=dist(a,p,a,m);

                if(d<S)

                {

                    S=d;

                }

            }

        }



        return S;

    }

    int mij=(st+dr)/2;

    int vert=a[mij].x;

    long double Smin=0.0;

    Smin=cmap(st,mij);

    Smin=min(Smin,cmap(mij+1,dr));

    int ps,pd;

    for(ps=mij;ps>=st;ps--)

    {

        if(vert-a[ps].x>=Smin)

        {

            break;

        }

    }

    ps++;

    for(pd=mij;pd<=dr;pd++)

    {

        if(a[pd].x-vert>=Smin)

        {

            break;

        }

    }

    pd--;

    for(int i=mij+1;i<=pd;i++)

    {

        b[i]=a[i];

    }

    sort(b+mij+1,b+pd+1,compy);

    for(int i=ps;i<=mij;i++)

    {

        int poz;

        poz=upper_bound(b+mij+1,b+pd+1,a[i],compy)-b;

        if(poz<=pd)

        {

            Smin=min(Smin,dist(a,i,b,poz));

            for(int j=poz+1;j<=pd;j++)

            {

                if(abs(a[i].y-b[j].y)>Smin)

                    break;

                if(dist(a,i,b,j)<Smin)

                {

                    Smin=dist(a,i,b,j);

                }

            }

            for(int j=poz-1;j>=mij+1;j--)

            {

                if(abs(a[i].y-b[j].y)>Smin)

                    break;

                if(dist(a,i,b,j)<Smin)

                {

                    Smin=dist(a,i,b,j);

                }

            }

        }
    }

    return Smin;

}
bool compx(punct a,punct b)

{

    if(a.x<b.x)

        return 1;

    if(a.x==b.x)

    {

        if(a.y<b.y)

            return 1;

    }

    return 0;

}







int main()

{

    in >> n;

    for(i=0;i<n;i++)

    {

        in >> a[i].x >> a[i].y;

    }



    sort(a,a+n,compx);

    long double l=cmap(0,n-1);

    out << fixed << setprecision(6) << l;

}

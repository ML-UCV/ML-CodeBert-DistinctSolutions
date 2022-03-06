#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>


using namespace std;

fstream f1("cmap.in", ios::in);

fstream f2("cmap.out", ios::out);

struct punct

{

    double x, y;

}p[100005], aux, strip[100005];

int n, nrpct;

double dist (punct p1, punct p2)

{

    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+ (p1.y-p2.y)*(p1.y-p2.y));

}

void quick(int inf, int sup)

{

  int i, j;

  punct p;

  i = inf;

  j = sup;

  p = strip[(i + j) / 2];

  do

  {

    while ( (i < sup) && (strip[i].x< p.x) ) i++;

    while ( (j > inf) && (strip[j].x> p.x) ) j--;

    if (i<= j)

    {

      aux=strip[i]; strip[i]=strip[j]; strip[j]=aux;

      i++;

      j--;

    }

  } while (i <= j);



  if (inf < j) quick(inf, j);

  if (i < sup) quick(i, sup);

}

double minim(double a, double b)

{

    return (a> b ? b: a);

}

double brute_force(int st, int dr)

{

    if(st==dr) return 0;

    else if(st+1==dr) return dist(p[st], p[dr]);

         else return minim(dist(p[st], p[st+1]), minim(dist(p[st], p[dr]), dist(p[st+1], p[dr]) ));

}

void cre_sort_strip(int st, int dr, int val, double dmin)

{

    int i;

     nrpct=0;

    for(i=st; i<=dr; i++)

        if(fabs(p[i].x- val)<= dmin) {nrpct++; strip[nrpct]=p[i];}
    quick(1, nrpct);

}

double dist_strip(double d)

{

    double dis=d, temp;

    int i,j;

    for(i=1; i<nrpct; i++)

        for(j=i+1; j<=nrpct; j++)

    {

        temp=dist(strip[i], strip[j]);

        if(temp< dis) dis=temp;

    }

    return dis;

}

double distmin(int st, int dr)

{

    if(dr-st<=3) return brute_force(st, dr);

    else

    {

        double ds, dd, d;

        int mijl=(st+dr)/2;

        ds=distmin(st, mijl);

        dd=distmin(mijl+1, dr);

        d=minim(dd, ds);



        cre_sort_strip(st, dr, p[mijl].x, d);

        return dist_strip(d);

    }

}

void citire()

{

    int i, gap, j;

    f1>>n;

    for(i=1; i<=n; i++)

        f1>>p[i].x>>p[i].y;

    for(gap=n/2; gap>=1; gap/=2)

        for(i=1+gap; i<=n; i++)

    {

        aux=p[i];

        for(j=i-gap; (j>=1)&&((p[j].x> aux.x)||((p[j].x== aux.x)&&(p[j].y> aux.y))); j-=gap)

            p[j+gap]=p[j];

        p[j+gap]=aux;

    }

}

int main()

{

   citire();

   f2<<fixed<<setprecision(6)<<distmin(1, n);

   return 0;

}

#include <iostream>
#include <fstream>
# include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");



struct elem {

    double x, y;

}a[100005], aux[100005];



bool cmp (elem x, elem y) {

    return x.x < y.x;

}

int i,j,n,m;

double sol;



double dist (elem x, elem y) {

    return sqrt((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y));

}

double divide (int ci, int cs) {

    if (cs-ci<=3) {

        double minn=dist(a[ci], a[ci+1]);

        for (int i=ci; i<=cs; ++i)

            for (int j=i+1; j<=cs; ++j)

                minn=min(minn, dist(a[i], a[j]));



        for (int i=ci; i<=cs; ++i)

            for (int j=i+1; j<=cs; ++j)

                if (a[i].y < a[j].y) swap(a[i], a[j]);



        return minn;

    }



    int k=0, mij=(ci + cs)/2;

    double DR=a[mij].x;

    double minn=divide(ci, mij);

    minn=min(minn, divide(mij+1, cs));





    int I=ci, J=mij+1, VV=0;

    while (I<=mij && J<=cs) {

        if (a[I].y > a[J].y) aux[++k]=a[I++];

                        else aux[++k]=a[J++];

    }

    while (I<=mij) aux[++k]=a[I++];

    while (J<=cs) aux[++k]=a[J++];





    for (int i=ci; i<=cs; ++i)

        a[i]=aux[i-ci+1];



    for (int i=1; i<=k; ++i) {

        if (abs(aux[i].x - DR)<=minn)

            aux[++VV]=aux[i];

    }



    for (int i=1; i<=VV; ++i)

        for (int j=i+1; j<=i+7 && j<=VV; ++j)

            minn=min(minn, dist(aux[i], aux[j]));



    return minn;

}

int main ()

{

    f>>n;

    for (i=0; i<n; ++i)

        f>>a[i].x>>a[i].y;





    sort (a, a+n, cmp);



    g<<fixed<<setprecision(6)<<divide (0, n-1)<<"\n";





    return 0;

}

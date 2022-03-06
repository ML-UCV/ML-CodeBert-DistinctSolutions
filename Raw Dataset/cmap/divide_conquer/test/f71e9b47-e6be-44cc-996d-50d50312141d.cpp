#include <cstdio>
#include <fstream>#include <math.h>
#include <algorithm>
#include <iomanip>






using namespace std;



ifstream f("cmap.in");

ofstream o("cmap.out");



const int nmx = 100002;

const double inf = 3000000000;



int n;

pair <double,double> v[nmx];



void citire()

{

    f >> n;

    for(int i = 1; i <= n; ++i)

        f >> v[i].first >> v[i].second;

}



inline double dist(const pair <double,double> p1, const pair <double,double> p2)

{

    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);

}



double divide(const int st, const int dr)

{

    if(dr - st + 1 > 3)

    {

        int mij = (st + dr) / 2;

        double minim = min(divide(st,mij),divide(mij+1,dr));



        int st1 = max(st-7,1), dr1 = min(dr+7,n);



        for(int i = st1; i <= dr1; ++i)

            for(int j = i + 1; j <= i + 7 && j <= dr1; ++j)

                minim = min(minim,dist(v[i],v[j]));



        return minim;

    }

    else

    {

        double minim = dist(v[st],v[st+1]);

        for(int i = st; i < dr; ++i)

            for(int j = i + 1; j <= dr; ++j)

                minim = min(minim,dist(v[i],v[j]));



        return minim;

    }

}



int main()

{

    citire();

    sort(v + 1, v + n + 1);

    o << fixed << setprecision(6) << sqrt(divide(1,n)) << "\n";

    return 0;

}

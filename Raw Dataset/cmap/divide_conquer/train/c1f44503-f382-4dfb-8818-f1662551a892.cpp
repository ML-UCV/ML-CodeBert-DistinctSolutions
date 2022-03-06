#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;



struct punct{

    int x, y;

};



bool cmpx(punct p1, punct p2)

{

    return (p1.x < p2.x);

}



bool cmpy(punct p1, punct p2)

{

    return (p1.y < p2.y);

}



double dist(punct p1, punct p2)

{

    double dist = sqrt( pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2) );

    return dist;

}



double f1(punct p[], int n)

{

    int i, j;

    double d = 99999999;



    if(n <= 3)

    {

        for(i = 0; i < n; i++)

            for(j = i+1; j < n; j++)

                if(dist(p[i], p[j]) < d)

                    d = dist(p[i], p[j]);

        return d;

    }



    int m = (n/2);

    double rs = f1(p, m);

    double rd = f1(p + m, n - m);



    if(rs < rd)

        d = rs;

    else

        d = rd;



    punct Y[n];

    j = 0;

    for (i = 0; i < n; i++)

        if (abs(p[i].x - p[m].x) < d)

        {

            Y[j] = p[i];

            j++;

        }

    sort(Y, Y+j, cmpy);



    for(i = 0; i < j; i++)

        for(int k = i+1; k < j && ((Y[k].y - Y[i].y) < d); k++)

            if(dist(Y[i], Y[k]) < d)

                d = dist(Y[i], Y[k]);



    return d;

}



int main()

{

    ifstream f("cmap.in");

    ofstream g("cmap.out");

    int n;

    f>>n;

    punct p[n];

    for(int i = 0; i < n; i++)

        f >> p[i].x >> p[i].y;



    sort(p, p+n, cmpx);



    double r = f1(p, n);



    g<<fixed<<setprecision(6)<<r;



    return 0;

}

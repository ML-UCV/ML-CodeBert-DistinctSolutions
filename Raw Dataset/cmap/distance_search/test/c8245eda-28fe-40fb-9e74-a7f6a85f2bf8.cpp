#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>


using namespace std;



ifstream f1("cmap.in");

ofstream f2("cmap.out");



struct pt

{

    long long x,y;

};



vector <pt> a;

double s;



void read()

{

    int n;

    f1 >> n;

    a.resize(n);

    for (int i=0; i<a.size(); i++)

    {

        f1 >> a[i].x >> a[i].y;

    }

}



bool xx(pt a, pt b)

{

    return a.x<b.x;

}



double dist(pt a, pt b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}



void solve()

{

    double q;

    for (int i=0; i<a.size(); i++)

    {

        for (int j=i+1; j<a.size(); j++)

        {

            q=dist(a[i],a[j]);

            if (q<s) s=q;

            if (a[j].x-a[i].x>s) break;

        }

    }

}



main()

{

    read();

    sort(a.begin(),a.end(),xx);

    s=dist(a[0],a[1]);

    solve();

    f2 << fixed << setprecision(10) << s;

}

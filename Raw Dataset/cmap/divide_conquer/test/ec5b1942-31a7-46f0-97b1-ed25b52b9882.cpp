#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>


using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



const long long INF = 4e18;



struct point

{

    int x, y;

};



int n;



vector < point > p;



bool cmp(point a, point b)

{

    if (a.x < b.x)

        return true;



    if (a.x == b.x && a.y < b.y)

        return true;



    return false;

}



bool cmpAux(point a, point b)

{

    if (a.y < b.y)

        return true;



    if (a.y == b.y && a.x < b.x)

        return true;



    return false;

}



double dist(point a, point b)

{

    long long dx = a.x - b.x;

    long long dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);

}



double distMin(vector < point > &p, int st, int dr)

{

    if (dr - st <= 2)

    {

        double dmin = INF;



        for (int i=st; i<dr; i++)

            for (int j=i+1; j<=dr; j++)

                dmin = min(dmin, dist(p[i], p[j]));



        return dmin;

    }



    int mij = (st + dr) / 2;



    double dmin = min(distMin(p, st, mij), distMin(p, mij+1, dr));

    double D = (p[mij].x + p[mij+1].x) / 2.0;



    vector < point > aux;



    for (int i=st; i<=dr; i++)

        if (abs(D - p[i].x) <= dmin)

            aux.push_back(p[i]);



    sort(aux.begin(), aux.end(), cmpAux);



    int n = aux.size();

    for (int i=0; i<n-1; i++)

        for (int j=i+1; j<i+8 && j<n; j++)

            dmin = min(dmin, dist(aux[i], aux[j]));



    return dmin;

}



int main()

{

    f >> n;



    p.resize(n);



    for (int i=0; i<n; i++)

        f >> p[i].x >> p[i].y;



    sort(p.begin(), p.end(), cmp);



    g << fixed << setprecision(6) << distMin(p, 0, n - 1);



    return 0;

}

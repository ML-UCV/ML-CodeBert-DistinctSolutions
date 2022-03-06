#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;



ifstream fin ("cmap.in");

ofstream fout ("cmap.out");



struct point

{

    double x, y;

};



bool CMP (point a, point b);

double DIST (point a, point b);



unsigned int n;

point v[100001];



double D;

unsigned int i, j;



double sol;



int main ()

{

    fin >> n;

    for (i=1; i<=n; i++)

        fin >> v[i].x >> v[i].y;

    sort(v+1,v+n+1,CMP);

    sol = DIST(v[1],v[2]);

    for (i=3; i<=n; i++)

    {

        j = i - 1;

        while (v[i].x-v[j].x < sol && j >= 1)

        {

            D = DIST(v[i],v[j]);

            if (D < sol)

                sol = D;

            j -= 1;

        }

    }

    fout << fixed << setprecision(6) << sol;

    return 0;

}



bool CMP (point a, point b)

{

    if (a.x < b.x)

        return 1;

    return 0;

}



double DIST (point a, point b)

{

    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));

}

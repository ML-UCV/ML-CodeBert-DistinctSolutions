#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;



ifstream f("cmap.in");

ofstream g("cmap.out");



const int nmax = 100005;

const double f_mare = 6e15;

int n, i, j;

struct pct {

    double x, y;

}v[nmax];

double dist, sol = f_mare;



bool cmp(const pct &a, const pct &b) {

    return a.x < b.x;

}



double fc(const pct &a, const pct &b) {

    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));

}



int main() {

    f >> n;

    for (i = 1; i <= n; i++)

        f >> v[i].x >> v[i].y;



    sort(v+1, v+n+1, cmp);

    sol = fc(v[1],v[2]);

    for (i = 1; i <= n; i++) {

        for (j = i-1; j >= 1 && v[i].x - v[j].x < sol; j--) {

            dist = fc(v[j], v[i]);

            if (sol>dist) sol = dist;

        }

    }

    g << fixed<<setprecision(6)<<sol;

}

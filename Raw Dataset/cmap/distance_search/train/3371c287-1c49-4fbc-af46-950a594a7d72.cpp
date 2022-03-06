#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>






using namespace std;



ifstream fin ("cmap.in");

ofstream fout ("cmap.out");



const int NM = 100100;



int n, i, j;

double d;



vector< pair<double, double> > v(NM);



double dist(int a, int b) {

    return sqrt( (v[a].first - v[b].first) * (v[a].first - v[b].first) + (v[a].second - v[b].second) * (v[a].second - v[b].second) );

}



int main() {

    fin >> n;

    for (i = 1; i <= n; ++i) {

        fin >> v[i].first >> v[i].second;

    }

    sort(v.begin() + 1, v.begin() + n + 1);

    d = dist(1, n);

    for (i = 1; i <= n; ++i) {

        for(j = i + 1; j <= n; ++j) {

            if (v[j].first - v[i].first > d) {

                break;

            }

            if (dist(i, j) < d) {

                d = dist(i, j);

            }

        }

    }

    fout << fixed << setprecision(6) << d;

    return 0;

}

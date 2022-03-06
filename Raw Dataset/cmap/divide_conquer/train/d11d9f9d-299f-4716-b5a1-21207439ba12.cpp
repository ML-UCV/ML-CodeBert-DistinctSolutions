#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>


using namespace std;



ifstream fin("cmap.in");

ofstream fout("cmap.out");



const int Nmax = 100000;

const long long inf = 1000000000000000000;



pair <int, int> p[Nmax + 5], p2[Nmax + 5];

int n;



void Read(){

    fin >> n;

    for (int i = 1; i <= n; i++)

        fin >> p[i].first >> p[i].second;

}



long long Distance(pair <int, int> x, pair <int, int> y){

    return 1LL * (x.first - y.first) * (x.first - y.first) + 1LL * (x.second - y.second) * (x.second - y.second);

}



long long DEI(int l, int r){

    if (l == r)

        return inf;

    if (r - l == 1)

        return Distance(p[l], p[r]);

    int mid = (l + r) >> 1;

    long long d = min(DEI(l, mid), DEI(mid + 1, r));

    int ind = 0;

    for (int i = l; i <= r; i++)

        if (abs(p[i].first - p[mid].first) <= d){

            ind++;

            p2[ind].first = p[i].second;

            p2[ind].second = p[i].first;

        }

    sort(p2 + 1, p2 + ind + 1);

    for (int i = 1; i <= ind; i++)

        for (int j = i + 1; j <= i + 7 && j <= ind; j++)

            d = min(d, Distance(p2[i], p2[j]));

    return d;

}



int main(){

    Read();

    sort(p + 1, p + n + 1);

    fout << fixed << setprecision(6) << sqrt(DEI(1, n)) << '\n';

    return 0;

}

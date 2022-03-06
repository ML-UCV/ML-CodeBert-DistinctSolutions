#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>


using namespace std;



ifstream in("cmap.in");

ofstream out("cmap.out");



struct pct {

    int x, y;

    pct(int a = 0, int b = 0): x(a), y(b) {};



    bool operator<(const pct &X) {

        if (x == X.x)

            return y < X.y;

        return x < X.x;

    }

};



double dist(pct &A, pct &B) {

    return sqrt(1ll * (A.x - B.x) * (A.x - B.x) + 1ll *(A.y - B.y) * (A.y - B.y));

}



double divide(vector <pct> &p, vector <pct> &py, int l, int r) {

    if (l >= r) {

        return dist(p[0], p[1]);

    }

    if (r - l == 1) {

        if (py[r] < py[l]) {

            swap(py[l], py[r]);

        }

        return dist(p[r], p[l]);

    }

    int m = l + (r - l) / 2;

    double d1, d2;

    d1 = divide(p, py, l, m);

    d2 = divide(p, py, m + 1, r);

    double d = min(d1, d2);



    vector <pct> P(r - l + 1);

    merge(py.begin() + l, py.begin() + m + 1, py.begin() + m + 1, py.begin() + r + 1, P.begin());

    copy(P.begin(), P.begin() + (r - l + 1), py.begin() + l);



    int in_band = 0;

    for (int i = l; i <= r; i++) {

        if (abs(py[i].y - p[m].x) < d1)

            P[in_band++] = py[i];

    }



    for (int i = 0; i < in_band; i++) {

        for (int j = i + 1; j < in_band && j - i <= 8; j++) {

            d = min(d, dist(P[i], P[j]));

        }

    }



    return d;

}



int main() {

    int n;

    in >> n;

    vector <pct> p(n), py(n);



    for (int i = 0; i < n; i++) {

        in >> p[i].x >> p[i].y;

    }



    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++) {

        py[i].x = p[i].y;

        py[i].y = p[i].x;

    }



    out << fixed << setprecision(6) << divide(p, py, 0, n - 1);

    return 0;

}

#include <bits/stdc++.h>




using namespace std;

const string problem("inversmodular");

ifstream fin(problem + ".in");

ofstream fout(problem + ".out");

inline int Euclid(int a, int b, int& x, int& y) {

    if (!b) {

        x = 1, y = 0;

        return a;

    }

    int x0, y0, d = Euclid(b, a % b, x0, y0);

    x = y0, y = x0 - (a / b) * y0;

    return d;

}

int a, n, x, y;

int main() {

    ios_base::sync_with_stdio(false); fin.tie(0); fout.tie(0);

    fin >> a >> n;

    Euclid(a, n, x, y);

    while (x > n)

        x -= n;

    while (x < 0)

        x += n;

    fout << x;

    fin.close(); fout.close(); return 0;

}

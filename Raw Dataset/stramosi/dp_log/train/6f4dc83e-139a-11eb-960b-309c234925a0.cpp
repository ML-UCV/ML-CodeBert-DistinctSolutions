#include <bits/stdc++.h>

using namespace std;

ifstream in("stramosi.in");
ofstream out("stramosi.out");

const int Nmax = 25e4;

int stramos[20][Nmax + 10];

int main() {
    ios::sync_with_stdio(false); in.tie(0); out.tie(0);

    int n, m; in >> n >> m;

    for(int i = 1; i <= n; ++i) {
        in >> stramos[0][i];
    }

    for(int i = 1; (1 << i) <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            stramos[i][j] = stramos[i - 1][stramos[i - 1][j]];
        }
    }

    while(m--) {
        int q, p; in >> q >> p;

        for(int i = 0; (1 << i) <= n && q; ++i) {
            if((p >> i) % 2 == 1) {
                q = stramos[i][q];
            }
        }

        out << q << '\n';
    }

    in.close(); out.close();

    return 0;
}

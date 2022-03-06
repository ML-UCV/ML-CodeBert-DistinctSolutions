#include <bits/stdc++.h>

using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");



int n, m, dp[19][250005], q, p, r, rez;

int main() {
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> dp[0][i];
    for(int j = 1; j <= 18; ++j)
        for(int i = 1; i <= n; ++i)
            dp[j][i] = dp[j - 1][dp[j - 1][i]];

    for(int i = 1; i <= m; ++i) {
        fin >> q >> p;
        r = 0; rez = q;

        while(p) {
            if(p % 2) rez = dp[r][rez];
            p >>= 1; ++r;
        }

        fout << rez << '\n';
    }
}

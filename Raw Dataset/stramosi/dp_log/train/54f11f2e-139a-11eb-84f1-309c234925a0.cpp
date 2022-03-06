#include <bits/stdc++.h>
using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



const int NMAX = 250005;

const int PMAX = 19;

int dp[PMAX][NMAX], n, q, x, k, b;



int main()

{

    f >> n >> q;

    for(int i = 1; i <= n; i++) {

        f >> dp[0][i];

    }

    for(int i = 1; (1 << i) <= n; i++) {

        for(int j = 1; j <= n; j++) {

            dp[i][j] = dp[i - 1][dp[i - 1][j]];

        }

    }

    while(q--) {

        f >> x >> k;

        b = 0;

        while(k) {

            if(k % 2) {

                x = dp[b][x];

            }

            b++;

            k /= 2;

        }

        g << x << '\n';

    }

    return 0;

}

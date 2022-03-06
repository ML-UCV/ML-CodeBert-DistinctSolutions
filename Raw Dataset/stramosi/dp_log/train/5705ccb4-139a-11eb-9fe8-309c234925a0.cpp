#include <bits/stdc++.h>


using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n, m, dp[19][250010], q, p, r, rez;



int main() {

    f>>n>>m;

    for(int i = 1; i <= n; i++)

        f>>dp[0][i];

    for(int j = 1; j <= 18; j++)

        for(int i = 1; i <= n; i++)

            dp[j][i] = dp[j - 1][dp[j - 1][i]];



    for(int i = 1; i <= m; i++) {

        f>>q>>p;

        r = 0;

        rez = q;



        while(p != 0) {

            if(p % 2 != 0)

                rez = dp[r][rez];

            p = p >> 1;

            r++;

        }

        g<<rez<<'\n';

    }

}

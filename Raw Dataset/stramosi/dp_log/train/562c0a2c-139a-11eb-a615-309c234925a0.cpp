#include <iostream>
#include <fstream>
using namespace std;



int n, m, dp[19][250010], q, p, r, rez;



int main()

{

    ifstream f("stramosi.in");

    ofstream g("stramosi.out");

    f>>n>>m;

    int i, j;

    for(i=1; i<=n; i++)

        f>>dp[0][i];

    for(j=1; j<=18; j++)

        for(i = 1; i <= n; i++)

            dp[j][i] = dp[j - 1][dp[j - 1][i]];

    for(int i=1; i<=m; i++)

    {

        f>>q>>p;

        r = 0;

        rez = q;

        while(p != 0)

        {

            if(p % 2 != 0)

                rez = dp[r][rez];

            p = p >> 1;

            r++;

        }

        g<<rez<<'\n';

    }

}

#include <bits/stdc++.h>
using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");

int n,m,p[250005],dp[19][250005];

int main()

{int i,j,q,P,p_2,stramos;

    in >> n >> m;

    for (i = 1; i <= n; i++) in >> dp[0][i];



    for (j = 1; j <= 18; j++)

        for (i = 1; i <= n; i++)

            dp[j][i] = dp[j - 1][dp[j - 1][i]];



    for (i = 1; i <= m; i++)

    {

        in >> q >> P;

        p_2 = 0;

        stramos = q;

        while (P)

        {

            if (P % 2 == 1)

                stramos = dp[p_2][stramos];

            P >>= 1;

            p_2++;

        }

        out << stramos << "\n";

    }

    return 0;

}

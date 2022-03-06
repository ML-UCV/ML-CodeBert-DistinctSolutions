#include <bits/stdc++.h>






using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n, Q;

int tt[250005];

int p, q;



int dp[19][250005];



inline void read()

{

    fin >> n >> Q;

    for (int i = 1; i <= n; i++)

        fin >> dp[0][i];

}



inline void build()

{

    int ok = 1;

    for (int k = 1; ok ; k++)

    {

        ok = 0;

        for (int i = 1; i <= n; i++)

        {

            dp[k][i] = dp[k-1][dp[k-1][i]];

            if (dp[k][i])

                ok = 1;

        }

    }

}



inline void solve()

{

    int k = 0;

    while (q != 0)

    {



        if (q % 2 == 1)

            p = dp[k][p];

        k++;

        q /= 2;

    }

    fout << p << "\n";

}



int main()

{

    read();

    build();

    while (Q--)

    {

        fin >> p >> q;

        solve();

    }

    return 0;

}

#include <bits/stdc++.h>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int n, m, dp[50][250005];



int main()

{

    fin >> n >> m;

    for(int i = 1; i <= n; i++)

        fin >> dp[0][i];



    for(int i = 1; (1<<i) <= n; i++)

        for(int j = 1; j <= n; j++)

        {

            int k = dp[i-1][j];

            dp[i][j] = dp[i-1][k];

        }

    while(m--)

    {

        int p, q;

        fin >> q >> p;



        int x = q;

        for(int i = 0; (1<<i) <= p; i++)

            if((1<<i)&p)

                x = dp[i][x];



        fout << x << '\n';

    }

    return 0;

}

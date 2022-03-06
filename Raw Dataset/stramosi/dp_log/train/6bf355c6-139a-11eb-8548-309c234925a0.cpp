#include <bits/stdc++.h>


using namespace std;

int n , m , i , dp[40][250005] , p , t , x ,str;

int main()

{

    ifstream fin("stramosi.in");

    ofstream fout("stramosi.out");

    fin >> n >> m;

    for(i = 1; i <= n; i++)

    {

        fin >> dp[0][i];

    }

    for(p = 1; (1 << p) <= n; p++)

    {

        for(i = 1; i <= n; i++)

        {

            dp[p][i] = dp[p-1][dp[p-1][i]];

        }

    }

    for(t = 1; t <= m; t++)

    {

        fin >> x >> str;

        for(i = 0; i <= 25; i++)

            if(str & (1 << i))x = dp[i][x];

        fout << x << "\n";

    }

    return 0;

}

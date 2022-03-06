#include <bits/stdc++.h>


using namespace std;

ifstream in("stramosi.in");

ofstream out("stramosi.out");

const int N = 250005;

const int L = 20;

int dp[L][N],lg[N];

int main()

{

    int n,m;

    in >> n >> m;

    for (int i = 2; i<=n; i++)

        lg[i] = lg[i/2]+1;

    for (int i = 1; i<=n; i++)

    {

        in >> dp[0][i];

        for (int j = 1; j<=lg[n]; j++)

            dp[j][i] = dp[j-1][dp[j-1][i]];

    }

    for (int i = 1; i<=m; i++)

    {

        int x,p;

        in >> x >> p;

        while (p)

        {

            x = dp[lg[p]][x];

            p = p-(1<<lg[p]);

        }

        out << x << "\n";

    }

}

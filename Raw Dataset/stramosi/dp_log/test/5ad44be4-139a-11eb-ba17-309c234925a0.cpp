#include <iostream>
#include <fstream>




using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n, m, x, y;

int tt[250005];

int dp[20][250005];



int main()

{

    f >> n >> m;

    for (int i = 1; i <= n; i++)

    {

        f >> dp[0][i];

    }



    for (int i = 1; i <= 18; i++)

    {

        for (int j = 1; j <= n; j++)

            dp[i][j]=dp[i-1][dp[i-1][j]];

    }



    while (m--)

    {

        f >> x >> y;



        for (int i = 0; i <= 18; i++)

            if (y&(1<<i)) x=dp[i][x];

        g << x << '\n';

    }



    return 0;

}

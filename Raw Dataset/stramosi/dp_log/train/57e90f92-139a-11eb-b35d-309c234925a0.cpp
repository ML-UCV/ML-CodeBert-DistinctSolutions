#include <bits/stdc++.h>


using namespace std;



ifstream in("stramosi.in");

ofstream out("stramosi.out");



const int MAX = 250001;



int dp[18][MAX];

int n, m, x, y;



int main()

{

    in >> n >> m;

    for(int i = 1; i <= n; i++)

    {

        in >> dp[0][i];

    }

    for(int i = 1; i < 18; i++)

    {

        for(int j = 1; j <= n; j++)

        {

            dp[i][j] = dp[i - 1][dp[i - 1][j]];

        }

    }

    while(m--)

    {

        in >> x >> y;

        int j = 0;

        while(y)

        {

            if(y % 2 != 0)

            {

                x = dp[j][x];

            }

            y /= 2;

            j++;

        }

        out << x << "\n";

    }

    return 0;

}

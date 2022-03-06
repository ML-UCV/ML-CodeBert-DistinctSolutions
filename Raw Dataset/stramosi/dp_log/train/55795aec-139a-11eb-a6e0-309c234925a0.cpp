#include <fstream>


using namespace std;

ifstream cin ("stramosi.in");

ofstream cout ("stramosi.out");

int dp[20][250000];

int main()

{

    int n, m, i, j;

    cin >> n >> m;

    for (i = 1; i <= n; i++)

        cin >> dp[0][i];

    for (i = 1; (1 << i) <= n; i++)

        for (j = 1; j <= n; j++)

            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    for (i = 1; i <= m; i++)

    {

        int p, q;

        cin >> q >> p;

        int bit = 0;

        while (p)

        {

            if (p % 2 == 1)

                q = dp[bit][q];

            bit++;

            p /= 2;

        }

        cout << q << '\n';

    }

    return 0;

}

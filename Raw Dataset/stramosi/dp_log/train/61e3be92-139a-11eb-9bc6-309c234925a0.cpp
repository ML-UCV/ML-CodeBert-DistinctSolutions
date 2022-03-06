#include <fstream>
using namespace std;

ifstream cin("stramosi.in");

ofstream cout("stramosi.out");

int n, m, DP[22][300005];

int main()

{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)

        cin >> DP[0][i];

    for (int i = 1; i <= n; i++)

         for (int j = 1; j <= 20; j++)

              DP[j][i] = DP[j - 1][DP[j - 1][i]];

    while (m--)

    {

        int x, y;

        cin >> x >> y;

        for (int i = 20; i >= 0; i--)

            if (y & (1 << i))

            x = DP[i][x];

        cout << x << "\n";

    }

    return 0;

}

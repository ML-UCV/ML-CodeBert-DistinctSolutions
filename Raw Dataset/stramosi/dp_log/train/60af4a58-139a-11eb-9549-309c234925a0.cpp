#include <fstream>
using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int t[250010], n, m, nod, k, dp[20][250010];



int stramos(int nod, int k) {

    if(!nod || !k)

        return nod;

    else {

        int x = 0;

        while(1 << x <= k)

            x++;

        x--;

        return stramos(dp[x][nod], k-(1<<x));

    }

}



int main() {

    f >> n >> m;

    for(int i = 1; i <= n; i++)

        f >> t[i];



    for(int i = 1; i <= n; i++) {

        dp[0][i] = t[i];

        for(int j = 1; (1 << j) <= 250000; j++) {

            dp[j][i] = dp[j-1][dp[j-1][i]];

            if(!dp[j][i])

                break;

        }

    }



    for(int i = 1; i <= m; i++) {

        f >> nod >> k;

        g << stramos(nod, k) << '\n';

    }



}

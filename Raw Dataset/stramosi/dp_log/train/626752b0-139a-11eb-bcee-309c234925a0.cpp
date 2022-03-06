#include <array>
#include <fstream>




std::ifstream fin("stramosi.in");

std::ofstream fout("stramosi.out");



int n, q;

std::array<std::array<int, 250010>, 19> dp;



int main() {

    fin >> n >> q;

    for (int i = 1; i <= n; i++)

        fin >> dp[0][i];



    for (int j = 1; (1 << j) <= n; j++)

        for (int i = 1; i <= n; i++)

            dp[j][i] = dp[j - 1][dp[j - 1][i]];



    for (int it = 0; it < q; it++) {

        int q, p; fin >> q >> p;

        int ancestor = q;

        for (int i = 18; i >= 0; i--)

            if (p & (1 << i))

                ancestor = dp[i][ancestor];

        fout << ancestor << '\n';

    }



    fout.close();

    return 0;

}

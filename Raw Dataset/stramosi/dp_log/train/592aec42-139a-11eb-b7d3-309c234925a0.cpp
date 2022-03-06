#include <fstream>
#include <iostream>


using namespace std;



const int N = 250005;



int dp[21][N], n;



void Read ()

{

    ifstream fin ("stramosi.in");

    int q;

    fin >> n >> q;

    for (int i = 1; i <= n; i++)

        fin >> dp[0][i];

    for (int i = 1; (1 << i) <= n; i++)

        for (int j = 1; j <= n; j++)

            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    ofstream fout ("stramosi.out");

    while (q--)

    {

        int q, p, x;

        fin >> q >> p;

        x = q;

        for (int i = 0; (1 << i) <= p; i++)

            if ((1 << i) & p)

                x = dp[i][x];

        fout << x << "\n";

    }

    fout.close();

}





int main()

{

    Read();

    return 0;

}

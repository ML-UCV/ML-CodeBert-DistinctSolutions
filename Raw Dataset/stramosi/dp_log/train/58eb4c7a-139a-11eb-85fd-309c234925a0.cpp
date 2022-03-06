#include <fstream>


using namespace std;



const int N = 250005;



int dp[21][N], n, exp[N];



void Read ()

{

    ifstream fin ("stramosi.in");

    int q;

    fin >> n >> q;

    for (int i = 1; i <= n; i++)

        fin >> dp[0][i];

    for (int i = 1; (1 << i) <= n; i++)

        exp[(1 << i)] = i;

    for (int i = 1; (1 << i) <= n; i++)

        for (int j = 1; j <= n; j++)

            dp[i][j] = dp[i - 1][dp[i - 1][j]];

    ofstream fout ("stramosi.out");

    while (q--)

    {

        int q, p, x;

        fin >> q >> p;

        while (p > 0)

        {

            x = exp[p & (-p)];

            q = dp[x][q];

            p -= (p & (-p));

        }

        fout << q << "\n";

    }

    fout.close();

}





int main()

{

    Read();

    return 0;

}

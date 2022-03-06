#include <fstream>


using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n, m, i, j, k, s, sol, stramos[20][250005];



int main()

{

    f >> n >> m;

    for(i = 1; i <= n; i++)

        f >> stramos[0][i];

    for(i = 1; (1 << i) < n; i++)

        for(j = 1; j <= n; j++)

            stramos[i][j] = stramos[i - 1][stramos[i - 1][j]];



    while(m)

    {

        f >> k >> s;



        sol = k;

        for(i = 17; i >= 0; i--)

            if((1 << i) <= s)

            {

                sol = stramos[i][sol];

                s -= (1 << i);

            }



        g << sol << '\n';



        m--;

    }



    f.close();

    g.close();



    return 0;

}

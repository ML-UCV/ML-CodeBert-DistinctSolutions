#include <iostream>
#include <fstream>
#include <vector>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



vector <int> g[250005];

int d[250005][22];



int main()

{

    int n, m;

    fin >> n >> m;

    for (int i = 1; i <= n; i++)

    {

        int tata;

        fin >> tata;

        d[i][0] = tata;

    }

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= 18; j++)

            d[i][j] = d[d[i][j - 1]][j - 1];

    for (int i = 1; i <= m; i++)

    {

        int p, q;

        fin >> q >> p;



        for (int j = 18; j >= 0; j--)

            if (p & (1 << j))

                q = d[q][j];

        fout << q << '\n';

    }

    return 0;

}

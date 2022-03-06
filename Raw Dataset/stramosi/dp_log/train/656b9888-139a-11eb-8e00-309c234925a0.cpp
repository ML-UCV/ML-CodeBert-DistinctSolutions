#include <iostream>
#include <fstream>
using namespace std;



ifstream f("stramosi.in");

ofstream g("stramosi.out");



int n, m, a[21][250001];



int main()

{

    f >> n >> m;

    for(int i = 1; i <= n; ++i)

    {

        int x; f >> x;

        a[0][i] = x;

    }

    for(int i = 1; (1<<i) <= n; ++i)

        for(int j = 1; j <= n; ++j)

        if(a[i-1][j])

            a[i][j] = a[i-1][a[i-1][j]];

    for(int i = 1; i <= m; ++i)

    {

        int x, y;

        f >> x >> y;

        for (int i = 0; i <= 18; ++i) {

            if ((1<<i) & y)

                 x = a[i][x];

        }

        g << x << "\n";

    }

}

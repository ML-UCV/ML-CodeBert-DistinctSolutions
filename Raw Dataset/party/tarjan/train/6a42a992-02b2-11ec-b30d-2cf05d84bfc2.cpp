#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

ifstream f("party.in");

ofstream g("party.out");





int n, m, sol;

bool val[105];



struct party

{

    int x, y, z;

    bool ok;

    void makeok()

    {

        if (z == 0)

            ok = val[x] || val[y];

        if (z == 1)

            ok = val[x] || !val[y];

        if (z == 2)

            ok = !val[x] || val[y];

        if (z == 3)

            ok = !val[x] || !val[y];

    }

} p[1005];



bool valid()

{

    for (int i = 0; i < m; i ++)

    {

        p[i].makeok();

        if (!p[i].ok)

        {

            bool loto = rand() % 2;

            if (loto)

                val[p[i].x] = !val[p[i].x];

            else

                val[p[i].y] = !val[p[i].y];

            return false;

        }

    }

    return true;

}



int main()

{

    f >> n >> m;

    for (int i = 0; i < m; i ++)

        f >> p[i].x >> p[i].y >> p[i].z;

    for (int i = 1; i <= n; i ++)

        val[i] = rand() % 2;

    while (!valid());

    for (int i = 1; i <= n; i ++)

        sol += val[i];

    g << sol << '\n';

    for (int i = 1; i <= n; i ++)

        if (val[i])

            g << i << '\n';



    f.close();

    g.close();

    return 0;



}

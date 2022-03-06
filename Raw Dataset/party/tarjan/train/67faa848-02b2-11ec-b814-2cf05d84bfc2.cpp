#include <fstream>
#include <iostream>


using namespace std;



const int MAX_N = 105;



ifstream f("party.in");

ofstream g("party.out");



int n, m, sol;

bool val[MAX_N];



struct party

{

    int x, y, z;

    bool ok;



    void check ()

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

} v[1005];



bool valid()

{

    for (int i = 0; i < m; i ++)

    {

        v[i].check();

        if (!v[i].ok)

        {

            bool verif = rand() % 2;

            if (verif)

                val[v[i].x] = !val[v[i].x];

            else

                val[v[i].y] = !val[v[i].y];

            return false;

        }

    }

    return true;

}



int main()

{

    f >> n >> m;

    for (int i = 0; i < m; i ++)

        f >> v[i].x >> v[i].y >> v[i].z;



    for (int i = 1; i <= n; i ++)

        val[i] = rand() % 2;



    while (!valid());

        for (int i = 1; i <= n; i ++)

            sol += val[i];



    g << sol << "\n";

    for (int i = 1; i <= n; i ++)

        if (val[i])

            g << i << "\n";



    f.close();

    g.close();

    return 0;



}

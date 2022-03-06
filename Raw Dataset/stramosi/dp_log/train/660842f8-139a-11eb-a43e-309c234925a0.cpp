#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream f("stramosi.in");
ofstream g("stramosi.out");

int n,m, parinti[250005][20];

int main() {
    ios::sync_with_stdio(false);
    int nod, nivel_neam;
    f >> n >> m;

    for (int i=1; i<=n; i++)
    {
        f >> parinti[i][0];
    }
    for (int i=1; i<=n; i++)
    {
    for (int j=1; j<=18; ++j)
    {

            parinti[i][j]=parinti[parinti[i][j-1]][j-1];
        }
    }
    for (int query=1; query<=m; query++)
    {
        int nr=0;
        f >> nod >> nivel_neam;
        while (nivel_neam)
        {
            if (nivel_neam&1)
            {
                nod=parinti[nod][nr];

            }
            nr++;
            nivel_neam>>=1;
        }
        g << nod << '\n';
    }
    return 0;
}

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;



ifstream fin ("party.in");

ofstream fout ("party.out");



const int Zero = 105, N = 210;



int sol[N], m, n;

vector <int> g[N], gT[N], o;

vector <bool> viz (N, 0);



void dfs(int x) {

    viz[x] = 1;

    for (vector <int> :: iterator it = g[x].begin(); it != g[x].end(); ++it)

        if (!viz[*it])

            dfs (*it);

    o.push_back (x);

}



void dfsT(int x) {

    viz[x] = 0;

    sol[x] = 1;

    sol[Zero * 2 - x] = 0;

    for (vector <int> :: iterator it = gT[x].begin(); it != gT[x].end(); ++it)

        if (viz[*it])

            dfsT(*it);

}



int main() {

    fin >> n >> m;

    for (int x, y, t, i = 0; i < m; ++i) {

        fin >> x >> y >> t;

        if (t & 1)

            y = -y;

        if (t & 2)

            x = -x;

        g[Zero - x].push_back (Zero + y);

        gT[Zero + y].push_back (Zero - x);

        g[Zero - y].push_back (Zero + x);

        gT[Zero + x].push_back (Zero - y);

    }

    for (int i = Zero + 1; i <= Zero + n; ++i)

        if (!viz[i])

            dfs(i);

    for (int i = Zero - 1; i >= Zero - n; --i)

        if (!viz[i])

            dfs(i);

    for (vector <int> :: reverse_iterator it = o.rbegin(); it != o.rend(); ++it)

        if (viz[*it])

            dfsT(*it);

    int nr = 0;

    for (int i = 1; i <= n; ++i)

        if (sol[Zero + i])

            nr++;

    fout << nr << "\n";

    for (int i = 1; i <= n; ++i)

        if (sol[Zero + i])

            fout << i << "\n";

}

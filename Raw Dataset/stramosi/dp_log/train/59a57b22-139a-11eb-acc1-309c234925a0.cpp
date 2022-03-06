#include <bits/stdc++.h>




using namespace std;

using VI = vector<int>;

using VVI = vector<VI>;

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");

int n, q, x, k, res;

VVI t;

int main()

{

    ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);

    fin >> n >> q;

    t = VVI(20, VI(n + 2));

    for (int i = 1; i <= n; ++i)

        fin >> t[0][i];

    for (int p = 1; p <= 18; ++p)

        for (int i = 1; i <= n; ++i)

            t[p][i] = t[p-1][t[p-1][i]];

    while (q--)

    {

        fin >> x >> k;

        res = x;

        for (int p = 18; p >= 0 && k; --p)

            if ((1 << p) <= k)

            {

                k -= (1 << p);

                res = t[p][res];

            }

        fout << res << '\n';

    }

    fin.close(); fout.close(); return 0;

}

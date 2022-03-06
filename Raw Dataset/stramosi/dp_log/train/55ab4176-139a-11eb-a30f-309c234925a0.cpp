#include <fstream>
using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");

int rmq[19][250001];


inline int lsb(int x)
{
    return x&(-x);
}

inline int log(int x)
{
    int nr = 0;
    while (x > 1)
    {
        x = x>>1;
        nr++;
    }
    return nr;
}

int main()
{
    int n, i, m, q, p, j;
    fin >> n >> m;
    for (i = 1; i<=n; i++)
        fin >> rmq[0][i];
    for (i = 1; (1<<i)<n; i++)
        for (j = 1; j<=n; j++)
            rmq[i][j] = rmq[i-1][rmq[i-1][j]];
    for (i = 1; i<=m; i++)
    {
        fin >> q >> p;

        if (p == 0)
        {
            fout << q << '\n';
            continue;
        }
        while (p > 0)
        {
            q = rmq[log(lsb(p))][q];
            p = p - lsb(p);
        }
        fout << q << '\n';
    }
    return 0;
}

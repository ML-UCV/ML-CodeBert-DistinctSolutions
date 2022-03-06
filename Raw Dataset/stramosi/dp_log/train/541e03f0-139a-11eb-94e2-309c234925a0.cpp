#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("stramosi.in");
ofstream fout("stramosi.out");

const int N = 250005;
const int LOG = 18;

int n, q;
int anc[LOG][N];

void precompute()
{
    for(int lvl = 1; (1 << lvl) <= n; lvl++)
        for(int i = 1; i <= n; i++)
            anc[lvl][i] = anc[lvl-1][anc[lvl-1][i]];
}

int solveQuery(int p, int q)
{
    int ans = q;
    for(int bit = 0; bit < LOG; bit++)
        if(p & (1 << bit))
            ans = anc[bit][ans];
    return ans;
}

int main()
{
 fin >> n >> q;
    for(int i = 1; i <= n; i++)
        fin >> anc[0][i];

    precompute();
    while(q--)
    {
        int p, q;
        fin >> q >> p;
        fout << solveQuery(p, q) << '\n';
    }
    return 0;
}

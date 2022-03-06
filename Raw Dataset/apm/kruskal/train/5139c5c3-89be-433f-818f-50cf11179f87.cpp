#include <fstream>
#include <algorithm>
using namespace std;



ifstream fin("apm.in");
ofstream fout("apm.out");

struct much
{
    int a, b, c;
} v[400001];

bool comp(much a, much b)
{
    return a.c < b.c;
}

bool ok[400001];

int h[200001], t[200001];

void comb(int x, int y)
{
    if (h[x] < h[y])
        t[x] = y;
    else
    {
        t[y] = x;
        if (h[x] == h[y])
            h[x]++;
    }
}

int find(int x)
{
    int r, y;
    r = x;
    while (t[r])
        r = t[r];
    while (x != r)
    {
        y = t[x];
        t[x] = r;
        x = y;
    }
    return r;
}

int main()
{
    int n, m, i, x, y;
    int nrmuch = 0;
    int cost = 0;
    fin >> n >> m;
    for (i = 1; i<=m; i++)
        fin >> v[i].a >> v[i].b >> v[i].c;
    sort(v+1, v+m+1, comp);
    for (i = 1; nrmuch < n-1; i++)
    {
        x = find(v[i].a);
        y = find(v[i].b);
        if (x != y)
        {
            ok[i] = 1;
            cost += v[i].c;
            nrmuch++;
            comb(x, y);
        }
    }
    fout << cost << '\n' << n-1 << '\n';
    for (i = 1; i<=m; i++)
        if (ok[i])
            fout << v[i].a << ' ' << v[i].b << '\n';
    return 0;
}

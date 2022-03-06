#include <algorithm>
#include <fstream>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



struct MUCHIE

{

    int x, y, c;

    bool s;

};



MUCHIE v[400005];

int t[200005], h[200005];

int n, m, x, y, c, vfx, vfy, ms, cost, i;



bool cmp(MUCHIE a, MUCHIE b)

{

    return a.c < b.c;

}



int varf(int x)

{

    while (x != t[x])

        x = t[x];

    return x;

}



void unire(int x, int y)

{

    if (h[x] > h[y])

        t[y] = x;

    else if (h[y] > h[x])

        t[x] = y;

    else

    {

        t[y] = x;

        ++h[x];

    }

}



int main()

{

    fin >> n >> m;

    for (i = 1; i <= n; ++i)

        t[i] = i, h[i] = 1;

    for (i = 1; i <= m; ++i)

    {

        fin >> x >> y >> c;

        v[i].x = x;

        v[i].y = y;

        v[i].c = c;

    }

    sort(v + 1, v + m + 1, cmp);

    for (ms = 0, i = 1; ms < n - 1 && i <= m; ++i)

    {

        vfx = varf(v[i].x);

        vfy = varf(v[i].y);

        if (vfx != vfy)

        {

            unire(vfx, vfy);

            v[i].s = true;

            cost += v[i].c;

            ++ms;

        }

    }

    fout << cost << '\n'<< ms << '\n';

    for (i = 1; i <= m; ++i)

        if (v[i].s)

            fout << v[i].x << ' ' << v[i].y << '\n';

    return 0;

}

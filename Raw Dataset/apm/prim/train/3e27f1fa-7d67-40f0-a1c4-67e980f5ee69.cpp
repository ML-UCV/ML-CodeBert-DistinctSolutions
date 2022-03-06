#include <bits/stdc++.h>


using namespace std;

ifstream fin("apm.in");

ofstream fout("apm.out");

const int nmax = 2e5 + 1;

int a[nmax];

struct Graf

{

    int x, y, cost;

};

Graf v[nmax], rasp[nmax];

bool compare(Graf a, Graf b)

{

    return a.cost < b.cost;

}

int uwu(int i)

{

    if(a[i] == i)

        return i;

    return a[i] = uwu(a[i]);

}

int i;

int main()

{

    int n, m, cnt = 0, k = 0;

    fin>> n >> m;

    for( i = 1; i <= m; ++i)fin>> v[i].x >> v[i].y >> v[i].cost;

    for( i = 1; i <= n; ++i)a[i]=i;

    sort(v + 1, v + m + 1, compare);

    for( i = 1; i <= m; ++i)

    {

        if(uwu(v[i].x) != uwu(v[i].y))

        {

            a[uwu(v[i].y)] = v[i].x;

            cnt += v[i].cost;

            rasp[++k].x = v[i].x;

            rasp[k].y = v[i].y;

        }

    }

    fout<<cnt<<'\n';

    fout<<k<<'\n';

    for( i = 1; i <= k; ++i) fout<<rasp[i].x<<" "<<rasp[i].y<<'\n';

    return 0;

}

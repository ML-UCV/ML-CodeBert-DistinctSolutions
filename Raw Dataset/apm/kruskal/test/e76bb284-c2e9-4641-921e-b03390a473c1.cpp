#include <cstdio>
#include <algorithm>
using namespace std;

const int MMAX = 400000;

const int NMAX = 200000;

struct muchie

{

    int x, y, c, viz;

    muchie(int tx = 0, int ty = 0, int tc = 0, int tviz = 0)

    {

        x = tx;

        y = ty;

        c = tc;

        viz = tviz;

    }

};

muchie v[MMAX + 5];

int t[NMAX + 5], h[NMAX + 5];

bool cmp(muchie a, muchie b)

{

    return a.c < b.c;

}

int findMD(int x)

{

    while(x != t[x])

        x = t[x];

    return x;

}

void unionMD(int x, int y)

{

    if(h[x] > h[y])

        t[y] = x;

    else if(h[x] < h[y])

        t[x] = y;

    else

    {

        t[y] = x;

        h[x] ++;

    }

}

int main()

{

    freopen("apm.in", "r", stdin);

    freopen("apm.out", "w", stdout);

    int n, m, x, y, c, cnt, i;

    scanf("%d%d", &n, &m);

    for(i = 1 ; i <= m ; i ++)

    {

        scanf("%d%d%d", &x, &y, &c);

        v[i] = {x, y, c};

    }

    for(i = 1 ; i <= n ; i ++)

        t[i] = i, h[i] = 1;

    sort(v + 1, v + m + 1, cmp);

    c = 0;

    for(i = 1, cnt = 0 ; i <= m && cnt < n - 1 ; i ++)

    {

        x = findMD(v[i].x);

        y = findMD(v[i].y);

        if(x != y)

        {

            unionMD(x, y);

            cnt ++;

            c += v[i].c;

            v[i].viz = 1;

        }

    }

    printf("%d\n%d\n", c, n - 1);

    for(i = 1 ; i <= m ; i ++)

        if(v[i].viz)

            printf("%d %d\n", v[i].x, v[i].y);

    return 0;

}

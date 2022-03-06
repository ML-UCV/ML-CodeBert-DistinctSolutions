#include <bits/stdc++.h>



using namespace std;



const int nMax = 4e5 + 7;



int n, m, cost, p[nMax];

vector <pair <int, int> > sol;



struct edge

{

    int a, b, d;

} v[nMax];



bool comp(edge x, edge y)

{

    return x.d < y.d;

}



int Find(int x)

{

    int r = x;

    for (; r != p[r]; r = p[r]);

    while (p[x] != r)

    {

        int cop = p[x];

        p[x] = r;

        x = cop;

    }

    return r;

}



void Solve(edge x)

{

    int ra = Find(x.a);

    int rb = Find(x.b);

    if (ra != rb)

    {

        cost += x.d;

        p[ra] = rb;

        sol.push_back({x.b, x.a});

    }

}



main()

{

    freopen("apm.in", "rt", stdin);

    freopen("apm.out", "wt", stdout);



    scanf("%d%d", &n, &m);



    for (int i = 1; i <= m; ++i)

        scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].d);



    sort(v + 1, v + m + 1, comp);



    for (int i = 1; i <= n; ++i)

        p[i] = i;



    for (int i = 1; sol.size() < (n-1); ++i)

        Solve(v[i]);



    printf("%d\n%d\n", cost, n - 1);

    for (auto i : sol)

        printf("%d %d\n", i.first, i.second);



    return 0;

}

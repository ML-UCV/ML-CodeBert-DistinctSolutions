#include <bits/stdc++.h>


using namespace std;



ifstream fin("apm.in");

ofstream fout("apm.out");



const int mmax = 400005;

const int nmax = 200005;

int n, m;

int rang[nmax], tt[nmax];



struct ed

{

    int x, y, c;

}edge[mmax];



inline void read()

{

    fin >> n >> m;

    for (int i = 1; i <= m; i++)

        fin >> edge[i].x >> edge[i].y >> edge[i].c;

}



bool cmp(ed a, ed b)

{

    return a.c < b.c;

}



vector <pair <int, int> >sol;



inline int findset(int x)

{

    if (x != tt[x])

        tt[x] = findset(tt[x]);

    return tt[x];

}



inline void unite(int a, int b)

{

    if (rang[a] < rang[b])

        tt[a] = b;

    else if (rang[a] > rang[b])

        tt[b] = a;

    else

        tt[a] = b, rang[a]++;

}



inline void apm()

{

    sort(edge + 1, edge + m + 1, cmp);

    for (int i = 1; i <= n; i++)

        rang[i] = 1, tt[i] = i;

    int ans = 0;

    for (int i = 1; i <= m; i++)

    {

        int a = findset(edge[i].x);

        int b = findset(edge[i].y);

        if (a == b)

            continue;

        ans += edge[i].c;

        unite(a, b);

        sol.push_back({edge[i].x, edge[i].y});

    }

    fout << ans << "\n" << n-1 << "\n";

    for (int i = 1; i < n; i++)

        fout << sol[i-1].first << " " << sol[i-1].second << "\n";

}



int main()

{

    read();

    apm();

    return 0;

}

#include <bits/stdc++.h>






using namespace std;

int n, m, v[50002], aib[50002], occ[50002], ans, p[26 + 2];

char s1[50002], s2[50002];

short int sum(int x)

{

    int i;

    short int s = 0;

    for (int i = x; i >= 1; i -= i & (-i))

        s += aib[i];

    return s;

}

void add(int x)

{

    for (int i = x; i <= n; i += i & (-i))

        ++ aib[i];

}

void read()

{

    freopen("swap.in", "r", stdin);

    scanf("%s\n%s\n", s1 + 1, s2 + 1);

    n = strlen(s1 + 1);

}

void solve()

{

    int i;

    for (i = 1; i <= n; ++ i)

    {

        ++ occ[s1[i] - 'a'];

        -- occ[s2[i] - 'a'];

    }

    for (i = 0; i < 26; ++ i)

        if (occ[i])

        {

            ans = -1;

            return ;

        }

    for (i = 1; i <= n; ++ i)

    {

        while (s2[p[s1[i] - 'a']] != s1[i])

            ++ p[s1[i] - 'a'];

        v[i] = p[s1[i] - 'a'] ++;

    }

    for (i = 1; i <= n; ++ i)

    {

        ans += i - sum(v[i]) - 1;

        add(v[i]);

    }

}

void write()

{

    freopen("swap.out", "w", stdout);

    printf("%d\n", ans);

}

int main()

{

    read();

    solve();

    write();

    return 0;

}

#include <bits/stdc++.h>


using namespace std;

int n, m, vis[205], f[205], inv[205], ans;

vector < int > V[205], v[205];

int Not(int x)

{

    if (x <= n)

        return x + n;

    return x - n;

}

void dfs(int x)

{

    vis[x] = 1;

    int i, l = V[x].size();

    for (i = 0; i < l; ++ i)

        if (!vis[V[x][i]])

            dfs(V[x][i]);



    f[++ f[0]] = x;

}

void DFS(int x)

{

    vis[x] = 0;

    if (!inv[Not(x)] && x > n)

        ++ ans;

    inv[Not(x)] = 1;

    int i, l = v[x].size();

    for (i = 0; i < l; ++ i)

        if (vis[v[x][i]])

            DFS(v[x][i]);

}

void add_edge(int x, int y)

{



    V[Not(x)].push_back(y);

    v[y].push_back(Not(x));

    V[Not(y)].push_back(x);

    v[x].push_back(Not(y));

}

void read()

{

    freopen("party.in", "r", stdin);

    scanf("%d %d\n", &n, &m);

    while (m --)

    {

        int x, y, op;

        scanf("%d %d %d\n", &x, &y, &op);

        if (!op)

            add_edge(x, y);

        else if (op == 1)

            add_edge(x, Not(y));

        else if (op == 2)

            add_edge(Not(x), y);

        else

            add_edge(Not(x), Not(y));

    }

}

void solve()

{

    int i;

    for (i = 1; i <= 2 * n; ++ i)

        if (!vis[i])

            dfs(i);

    for (i = f[0]; i >= 1; -- i)

        if (vis[f[i]] && vis[Not(f[i])])

            DFS(f[i]);

}

void write()

{

    int i;

    freopen("party.out", "w", stdout);

    printf("%d\n", ans);

    for (i = 1; i <= n; ++ i)

        if (inv[i])

            printf("%d\n", i);

    if (!ans)

        printf("%d\n%d\n", 1, 1);

}

int main()

{

    read();

    solve();

    write();

    return 0;

}

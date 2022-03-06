# include <bits/stdc++.h>
using namespace std;

ifstream fi("party.in");

ofstream fo("party.out");

vector < int > g[1111];

vector < int > gr[1111];

vector < int > order;

int b[1111];

int sol[1111];

void dfs1(int node)

{

    b[node] = 1;

    for (auto it : g[node])

        if (!b[it])

            dfs1(it);

    order.push_back(node);

}

void dfs2(int node)

{

    b[node] = 0;

    sol[node] = 0;

    sol[node^1] = 1;

    for (auto it : gr[node])

        if (b[it])

            dfs2(it);

}

int main(void)

{

    int n,m;

    fi>>n>>m;

    int x,y,z;

    while (m --)

    {

        fi>>x>>y>>z;

        x <<= 1;y <<= 1;

        if (!z)

            g[x^1].push_back(y),

            g[y^1].push_back(x),

            gr[x].push_back(y^1),

            gr[y].push_back(x^1);

        else

        if (z == 1)

            g[y].push_back(x),

            gr[x].push_back(y);

        else

        if (z == 2)

            g[x].push_back(y),

            gr[y].push_back(x);

        else

        if (z == 3)

            g[x].push_back(y^1),

            g[y].push_back(x^1),

            gr[x^1].push_back(y),

            gr[y^1].push_back(x);

    }

    for (int i = 2;i <= n+n;i += 2)

        if (!b[i]) dfs1(i);

    for (int i = 3;i <= n+n+1;i += 2)

        if (!b[i]) dfs1(i);

    for (int i = n+n-1;i+1;--i)

        if (b[order[i]] && b[order[i]^1])

            dfs2(order[i]);

    vector < int > ans;

    for (int i = 1;i <= n;++i)

        if (sol[i<<1])

            ans.push_back(i);

    fo << ans.size() << '\n';

    for (auto it : ans)

        fo << it << '\n';

    return 0;

}

#include <bits/stdc++.h>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

const int N=100009;

int n,m,nr;

int d[N];

vector <int> v1[N],v2[N],sol[N];

stack <int> sk;

void dfs(int nod)

{

    d[nod]=1;

    for(int i=0;i<v1[nod].size();i++)

        if(!d[v1[nod][i]])

            dfs(v1[nod][i]);

    sk.push(nod);



}

void dfs2(int nod,int nr)

{

    sol[nr].push_back(nod);

    d[nod]=1;

    for(int i=0;i<v2[nod].size();i++)

        if(!d[v2[nod][i]])

            dfs2(v2[nod][i],nr);

}

void solve()

{

    for(int i=1;i<=n;i++)

        if(!d[i])

            dfs(i);

    memset(d,0,sizeof(d));

    for(int i=1;i<=n;i++)

    {

        int x=sk.top();

        if(!d[sk.top()])

        {

            nr++;

            dfs2(sk.top(),nr);

        }

        sk.pop();

    }

    g<<nr<<'\n';

    for(int i=1;i<=nr;i++)

    {

        for(int j=0;j<sol[i].size();j++)

            g<<sol[i][j]<<" ";

        g<<'\n';

    }

}

int main()

{

    f>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int x,y;

        f>>x>>y;

        v1[x].push_back(y);

        v2[y].push_back(x);

    }

    solve();

    return 0;

}

#include <bits/stdc++.h>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

int sel[100005],nrgrupe,nr,of[100005],n,m,i,x,y,j;

vector <int> v[100005],v2[100005],inv[100005];

void sorttop(int x)

{

    sel[x]=1;

    for (int i=0;i<v[x].size();i++)

    {

        int nod=v[x][i];

        if (sel[nod]==0)

        {

            sorttop(nod);

        }

    }

    of[++nr]=x;

}

void dfs(int x)

{

    sel[x]=1;

    for (int i=0;i<inv[x].size();i++)

    {

        int nod=inv[x][i];

        if (sel[nod]==0)

        {

            dfs(nod);

        }

    }

    v2[nrgrupe].push_back(x);

}

int main()

{

    f>>n>>m;

    for (i=1;i<=m;i++)

    {

        f>>x>>y;

        v[x].push_back(y);

        inv[y].push_back(x);

    }

    for (i=1;i<=n;i++)

    {

        if (sel[i]==0)

        {

            sorttop(i);

        }

    }

    memset(sel,0,sizeof(sel));

    reverse(of+1,of+nr+1);

    for (i=1;i<=n;i++)

    {

        if (sel[of[i]]==0)

        {

            nrgrupe++;

            dfs(of[i]);

        }

    }

    g<<nrgrupe<<'\n';

    for (i=1;i<=nrgrupe;i++)

    {

        for (j=0;j<v2[i].size();j++)

        {

            g<<v2[i][j]<<" ";

        }

        g<<'\n';

    }

    return 0;

}

#include <bits/stdc++.h>


using namespace std;

ifstream fin ("ctc.in");

ofstream fout ("ctc.out");



vector <int> v[100005], vt[100005], c[100005];

int viz[100005], a[100005], k, n, m;



void dfs1(int x)

{

    viz[x]=1;

    for(auto it:v[x])

        if(viz[it]==0)

            dfs1(it);

    a[++k]=x;

}

void dfs2(int x)

{

    viz[x]=1;

    for(auto it:vt[x])

        if(viz[it]==0)

            dfs2(it);

    c[k].push_back(x);

}

int main()

{

    fin >> n >> m;

    for(int i=1;i<=m;i++)

        {

            int x, y;

            fin >> x >> y;

            v[x].push_back(y);

            vt[y].push_back(x);

        }

    for(int i=1;i<=n;i++)

        if(!viz[i])

            dfs1(i);

    memset(viz, 0, sizeof(viz));

    k=0;

    for(int i=n;i>=1;i--)

        if(!viz[a[i]])

        {

            k++;

            dfs2(a[i]);

        }

    fout << k << '\n';

    for(int i=1;i<=k;i++)

    {

        for(auto it:c[i])

            fout << it << ' ';

        fout << '\n';

    }

    return 0;

}

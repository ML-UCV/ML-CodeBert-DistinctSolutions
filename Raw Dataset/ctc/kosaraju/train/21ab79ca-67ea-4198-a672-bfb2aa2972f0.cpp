#include <bits/stdc++.h>


using namespace std;

ifstream fin ("ctc.in");

ofstream fout ("ctc.out");

int n, m, cc;

vector<int> cp[100005];

vector<int> v[100005], in[100005];

vector<int> sf;

bitset<100005> viz;

void dfs1(int nod)

{

    viz[nod] = 1;

    for(auto it:v[nod])

        if(!viz[it])

            dfs1(it);

    sf.push_back(nod);

}

void dfs2(int nod)

{

    viz[nod] = 1;

    for(auto it:in[nod])

        if(!viz[it])

            dfs2(it);

    cp[cc].push_back(nod);

}

void read();

int main()

{

    read();

    for(int i=1; i<=n; i++)

        if(!viz[i])

            dfs1(i);

    viz.reset();

    for(int i=n-1; i>=0; i--)

        if(!viz[sf[i]])

        {

            ++cc;

            dfs2(sf[i]);

        }

    fout << cc << '\n';

    for(int i=1; i<=cc; i++)

    {

        sort(cp[i].begin(), cp[i].end());

        for(auto it:cp[i])

            fout << it << ' ';

        fout << '\n';

    }

    return 0;

}

void read()

{

    fin >> n >> m;

    for(int i=1; i<=m; i++)

    {

        int x, y;

        fin >> x >> y;

        v[x].push_back(y);

        in[y].push_back(x);

    }

}

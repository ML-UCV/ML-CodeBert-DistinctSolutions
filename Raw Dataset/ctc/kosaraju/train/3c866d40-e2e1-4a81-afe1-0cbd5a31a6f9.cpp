#include<bits/stdc++.h>






using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

int n, m, nr;

vector<int>lst, lst2;

vector<int>v[100001], tr[100001], ctc[100001];

bool viz[200001], viz2[100001];

void dfs(int nod)

{

    viz[nod]=1;

    for(int i=0; i<v[nod].size(); i++)

    {

        if(!viz[v[nod][i]])

            dfs(v[nod][i]);

    }

    lst.push_back(nod);

}

void dfs2(int nod)

{

    viz2[nod]=1;

    ctc[nr].push_back(nod);

    for(int i=0; i<tr[nod].size(); i++)

        if(!viz2[tr[nod][i]])

            dfs2(tr[nod][i]);

}

int main()

{

    f>>n>>m;

    for(int i=1; i<=m; i++)

    {

        int x, y;

        f>>x>>y;

        v[x].push_back(y);

        tr[y].push_back(x);

    }

    for(int i=1; i<=n; i++)

        if(!viz[i])

        dfs(i);

    while(!lst.empty())

    {

        int nod=lst.back();

        lst.pop_back();

        if(!viz2[nod])

        {

            nr++;

            dfs2(nod);

        }

    }

    g<<nr<<'\n';

    for(int i=1; i<=nr;g<<'\n', i++)

        for(int j=0; j<ctc[i].size(); j++)

            g<<ctc[i][j]<<' ';

    return 0;

}

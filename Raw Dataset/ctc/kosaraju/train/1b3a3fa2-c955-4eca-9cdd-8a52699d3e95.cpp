#include <bits/stdc++.h>




using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");



int n, m, x, y, conex, k, S[100001];

bool viz[100001];

vector<int> G[100001], GT[100001], cx[100001];



void dfs(int nod)

{

    viz[nod]=1;

    for(auto i:G[nod])

        if(!viz[i])

            dfs(i);

    S[++k]=nod;

}



void dfsgt(int nod)

{

    viz[nod]=1;

    cx[conex].push_back(nod);

    for(auto i:GT[nod])

        if(!viz[i])

            dfsgt(i);

}



int main()

{

    fin >> n >> m;

    while(m--)

    {

        fin >> x >> y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    for(int i=1; i<=n; i++)

        if(!viz[i])

            dfs(i);

    for(int i=1; i<=n; i++)

        viz[i]=0;

    for(int i=k; i>=1; i--)

        if(!viz[S[i]])

    {

        conex++;

        dfsgt(S[i]);

    }

    fout << conex << "\n";

    for(int i=1; i<=conex; i++)

    {

        sort(cx[i].begin(), cx[i].end());

        for(auto j:cx[i])

            fout << j << " ";

        fout << "\n";

    }

    return 0;

}

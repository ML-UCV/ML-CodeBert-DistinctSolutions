#include <bits/stdc++.h>
using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

typedef long long ll;

int node,ctc,n,m,x,y,use[2*50005];

vector <int> g[2*50005],gt[2*50005],ans[2*50005];

stack <int> s;

void dfs(int nod)

{

    use[nod]=1;

    for(auto it : g[nod])

        if(!use[it])

            dfs(it);

    s.push(nod);

}

void dfs1(int nod)

{

    use[nod]=2;

    ans[ctc].push_back(nod);

    for(auto it : gt[nod])

        if(use[it]==1)

            dfs1(it);

}

int main()

{

    fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        fin>>x>>y;

        g[x].push_back(y);

        gt[y].push_back(x);

    }

    for(int i=1;i<=n;i++)

        if(!use[i])

            dfs(i);

    while(!s.empty())

    {

        node=s.top();

        if(use[node]==1)

        {

            ctc++;

            dfs1(node);

        }

        s.pop();

    }

    fout<<ctc<<'\n';

    for(int i=1;i<=ctc;i++,fout<<'\n')

        for(auto it : ans[i])

            fout<<it<<' ';

    return 0;

}

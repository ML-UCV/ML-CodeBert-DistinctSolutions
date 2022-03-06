#include <bits/stdc++.h>
using namespace std;

ifstream f("party.in");

ofstream g("party.out");

int n,m,x,y,tip,cur=1,viz[203];

vector <int> Sol,O,G[203],Q[203];

void add(int x,int y)

{

    G[x].push_back(y);

    Q[y].push_back(x);

}

void dfs(int x)

{

    viz[x]=1;

    for(int i=0;i<(int)G[x].size();++i)

        if(!viz[G[x][i]]) dfs(G[x][i]);

    O.push_back(x);

}

void DFS(int x)

{

    viz[x]=cur;

    for(int i=0;i<(int)Q[x].size();++i)

        if(viz[Q[x][i]]==1) DFS(Q[x][i]);

}

int main()

{

    f>>n>>m;

    while(m--)

    {

        f>>x>>y>>tip;

        if(!tip) add(x+n,y),add(y+n,x);

        else if(tip==1) add(x+n,y+n),add(y,x);

        else if(tip==2) add(y+n,x+n),add(x,y);

        else add(x,y+n),add(y,x+n);

    }

    for(int i=1;i<=2*n;++i)

        if(!viz[i]) dfs(i);

    for(int i=O.size()-1;i>=0;--i)

        if(viz[O[i]]==1)

        {

            cur++;

            DFS(O[i]);

        }

    for(int i=1;i<=n;++i)

        if(viz[i]>viz[i+n]) Sol.push_back(i);

    g<<Sol.size()<<'\n';

    for(int i=0;i<(int)Sol.size();++i) g<<Sol[i]<<'\n';

    return 0;

}

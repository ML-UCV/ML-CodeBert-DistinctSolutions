#include <bits/stdc++.h>
using namespace std;



ifstream f("ctc.in");

ofstream g("ctc.out");



const int nmax=1e5+3;



int n,m,a,b,viz[nmax],p,k,actual,viz2[nmax],nod;

vector <int> x[nmax],y[nmax],sol[nmax];

stack <int> stiva;



void dfs1(int nod)

{

    viz[nod]=1;

    for(int i=0;i<x[nod].size();++i)

    {

        if(viz[x[nod][i]]) continue;

        dfs1(x[nod][i]);

    }

    stiva.push(nod);

}

void dfs2(int nod)

{

    viz2[nod]=p;

    for(int i=0;i<y[nod].size();++i)

    {

        if(viz2[y[nod][i]]) continue;

        dfs2(y[nod][i]);

    }

    sol[p].push_back(nod);

}

int main()

{

    f>>n>>m;

    while(m--)

    {

        f>>a>>b;

        x[a].push_back(b);

        y[b].push_back(a);

    }

    for(int i=1;i<=n;++i) if(!viz[i]) dfs1(i);

    while(!stiva.empty())

    {

        nod=stiva.top();

        stiva.pop();

        if(viz2[nod]) continue;

        ++p;

        actual=viz[nod];

        dfs2(nod);

    }

    g<<p<<'\n';

    for(int i=1;i<=p;++i)

    {

        for(int j=0;j<sol[i].size();++j) g<<sol[i][j]<<' ';

        g<<'\n';

    }

    return 0;

}

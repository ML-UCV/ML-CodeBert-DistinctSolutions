#include <bits/stdc++.h>


using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

const int nmax=100005;

vector <int>G[nmax],Gt[nmax],sol[nmax];

stack <int>s;

bool viz[nmax];

int n,m,i,j,x,y,k;

void dfs(int nod)

{

    viz[nod]=1;

    for(auto i:G[nod])

        if(!viz[i])

            dfs(i);

    s.push(nod);

}

void dfs2(int nod)

{

    viz[nod]=1;

    sol[k].push_back(nod);

    for(auto i:Gt[nod])

        if(!viz[i])

            dfs2(i);

}

int main()

{

    f>>n>>m;

    for(i=1; i<=m; i++)

    {

        f>>x>>y;

        G[x].push_back(y);

        Gt[y].push_back(x);

    }

    for(i=1; i<=n; i++)

        if(!viz[i])

            dfs(i);

    for(i=1; i<=n; i++)

        viz[i]=0;

    while(!s.empty())

    {

        while(!s.empty()&&viz[s.top()])

            s.pop();

        if(s.empty())break;

        k++;

        dfs2(s.top());



    }

    g<<k<<'\n';

    for(i=1; i<=k; i++)

    {

        for(auto j:sol[i])

            g<<j<<' ';

        g<<'\n';

    }

    return 0;

}

#include <bits/stdc++.h>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

vector<int> adj[100005];

int n,m,low_link[100005],idx[100005],cnt=0,ctc=0;

bool viz[100005],instack[100005];

vector<int> sol[100005];

stack<int> s;

void dfs(int node)

{

    s.push(node);

    instack[node]=true;

    idx[node]=low_link[node]=++cnt;

    for(auto x:adj[node])

    {

        if(idx[x]==0) {dfs(x);}

        if(instack[x]==1)

        {

            low_link[node]=min(low_link[node],low_link[x]);

        }

    }

    if(idx[node]==low_link[node])

    {

        ctc++;

        int x=node;

        do

        {

            x=s.top();

            low_link[x]=idx[node];

            sol[ctc].push_back(x);

            instack[x]=0;

            s.pop();

        }

        while(x!=node);

    }







}

int main()

{

    f>>n>>m;

    for(int i=1; i<=m; i++)

    {

        int x,y;

        f>>x>>y;

        adj[x].push_back(y);

    }

    for(int i=1; i<=n; i++)

    {

        if(idx[i]==0)

        {

            dfs(i);

        }

    }

    g<<ctc<<'\n';

    for(int i=1;i<=ctc;i++)

    {

        for(auto x:sol[i])

        {

            g<<x<<" ";

        }

        g<<'\n';

    }

}

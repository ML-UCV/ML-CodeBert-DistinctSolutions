#include <bits/stdc++.h>
using namespace std;

int viz[100001],v[100001];

vector <int> G[100001],GT[100001],L[100001];

int mn[100001];

int loc;

int nrc;

int DFS(int x)

{

    viz[x]=1;

    for(auto i:G[x])

        if(viz[i]==0) DFS(i);

    loc++;

    v[loc]=x;

}

int DFS2(int x)

{

    viz[x]=nrc;

    L[nrc-1].push_back(x);

    for(auto i:GT[x])

        if(viz[i]==1) DFS2(i);

}



int main()

{

    int n,m,i,x,y,mini,j,ok;

    loc=0;

    ifstream f("ctc.in");

    ofstream g("ctc.out");

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    for(i=1;i<=n;i++)

        if(viz[i]==0)

    {

        DFS(i);

    }

    nrc=1;

    for(i=loc;i>=1;i--)

        if(viz[v[i]]==1)

    {

        nrc++;

        DFS2(v[i]);

    }

    nrc--;

    g<<nrc<<'\n';

    for(i=1;i<=nrc;i++)

        {

            for(auto j:L[i])

                g<<j<<" ";

            g<<'\n';

        }

    loc=0;



}

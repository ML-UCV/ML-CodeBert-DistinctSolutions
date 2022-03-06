#include<bits/stdc++.h>
using namespace std;

ifstream f("party.in");

ofstream g("party.out");

vector<int>a[202],inv[202];

int n,k,kk[202],ctc[202],sol[102];

bool viz[202];



int neg(int x)

{

    if(x>n)

        return x-n;

    return x+n;

}



void dfs(int x)

{

    viz[x]=1;

    for(auto y:a[x])

    if(viz[y]==0)

        dfs(y);

    kk[++k]=x;

}



void dfs_inv(int x)

{

    viz[x]=1;

    ctc[x]=k;

    for(auto y:inv[x])

    if(viz[y]==0)

        dfs_inv(y);

}



void kosaraju()

{

    int i;

    for(i=1;i<=2*n;i++)

    if(viz[i]==0)

        dfs(i);

    for(i=1;i<=2*n;i++)

        viz[i]=0;

    k=0;

    for(i=2*n;i>=1;i--)

    if(viz[kk[i]]==0)

    {

        k++;

        dfs_inv(kk[i]);

    }

}



int main()

{

    int m,i,x,y,p;

    f>>n>>m;

    for(i=1;i<=m;i++)

    {

        f>>x>>y>>p;

        if(p==0)

        {

            a[neg(x)].push_back(y);

            a[neg(y)].push_back(x);

            inv[y].push_back(neg(x));

            inv[x].push_back(neg(y));

        }

        else

        if(p==1)

        {

            a[neg(x)].push_back(neg(y));

            a[y].push_back(x);

            inv[neg(y)].push_back(neg(x));

            inv[x].push_back(y);

        }

        else

        if(p==2)

        {

            a[neg(y)].push_back(neg(x));

            a[x].push_back(y);

            inv[neg(x)].push_back(neg(y));

            inv[y].push_back(x);

        }

        else

        if(p==3)

        {

            a[x].push_back(neg(y));

            a[y].push_back(neg(x));

            inv[neg(y)].push_back(x);

            inv[neg(x)].push_back(y);

        }

    }

    kosaraju();

    k=0;

    for(i=1;i<=n;i++)

    if(ctc[i]>ctc[i+n])

        sol[++k]=i;

    g<<k<<'\n';

    for(i=1;i<=k;i++)

        g<<sol[i]<<'\n';

    return 0;

}

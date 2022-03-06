#include <bits/stdc++.h>


using namespace std;



const int N=100005;



ifstream f("ctc.in");

ofstream g("ctc.out");



int n,m,x,y;

vector<int> vecini[N];

int id[N],low[N],a[N],k,inq[N],s;

int nrctc,nodes[N],ctcsize[N];



void dfs(int x)

{

    ++k; ++s;

    low[x]=id[x]=k; a[s]=x; inq[x]=1;

    for(int i=0;i<vecini[x].size();++i)

    {

        if(!id[vecini[x][i]])

        {

            dfs(vecini[x][i]);

            low[x]=min(low[x],low[vecini[x][i]]);

        }

        else if(inq[vecini[x][i]]) low[x]=min(low[x],id[vecini[x][i]]);

    }



    if(low[x]==id[x])

    {

        nrctc++;

        ctcsize[nrctc]=ctcsize[nrctc-1];

        while(inq[x]==1)

        {

            inq[a[s]]=0;

            ctcsize[nrctc]++;

            nodes[ctcsize[nrctc]]=a[s];

            --s;

        }

    }

}



int main()

{

    f>>n>>m;

    for(int i=1;i<=m;++i) f>>x>>y, vecini[x].push_back(y);

    for(int i=1;i<=n;++i) if(!id[i])

    {

        k=0; s=0;

        dfs(i);

    }

    g<<nrctc<<'\n';

    for(int i=1;i<=nrctc;++i)

    {

        for(int j=ctcsize[i-1]+1;j<=ctcsize[i];++j) g<<nodes[j]<<' ';

        g<<'\n';

    }

    return 0;

}

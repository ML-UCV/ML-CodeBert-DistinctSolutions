#include <bits/stdc++.h>


using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

int n,m,low[100005],idx[100005],nrc,x,y,t,st[100005],k,ap[100005];

vector<int> comp[100005];

vector<int> v[100005];

void dfs(int nod)

{

    low[nod]=t;

    idx[nod]=t;

    ++t;

    st[++k]=nod;

    ap[nod]=1;

    for(auto it:v[nod])

        if(idx[it]==0)

        {

          dfs(it);

          low[nod]=min(low[it],low[nod]);

        }

        else if(ap[it]) low[nod]=min(low[nod],idx[it]);

    if(low[nod]==idx[nod])

    {

        nrc++;

        while(st[k]!=nod)

        {

            comp[nrc].push_back(st[k]);

            ap[st[k]]=0;

            k--;

        }

        comp[nrc].push_back(st[k]);

        ap[st[k]]=0;

        k--;

    }

}

int main()

{

    in>>n>>m;

    for(int i=1;i<=m;i++)

    {

        in>>x>>y;

        v[x].push_back(y);

    }

    for(int i=1;i<=n;i++)

        if(idx[i]==0)

        {

          t=1;

          k=0;

          dfs(i);

        }

    out<<nrc<<'\n';

    for(int i=1;i<=nrc;i++)

    {

        for(auto it:comp[i]) out<<it<<" ";

        out<<'\n';

    }

    return 0;

}

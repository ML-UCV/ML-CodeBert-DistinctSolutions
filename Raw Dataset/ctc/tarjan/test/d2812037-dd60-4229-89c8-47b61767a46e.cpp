#include <bits/stdc++.h>


using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

int n,m,x,y,st[100100],idx[100100],low[100100],top,c,ap[100100],t;

vector<int> v[100100];

vector<int> comp[100100];

void tarjan(int nod)

{

    idx[nod]=t;

    low[nod]=t;

    t++;

    st[++top]=nod;

    ap[nod]=1;

    for(auto it:v[nod])

    {

        if(idx[it]==-1) {

            tarjan(it);

            low[nod]=min(low[nod],low[it]);

        }

        else if(ap[it]) low[nod]=min(low[nod],idx[it]);

    }

    if(low[nod]==idx[nod])

    {

        c++;

        do

        {

            x=st[top--];

            ap[x]=0;

            comp[c].push_back(x);

        }while(x!=nod);

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

    for(int i=1;i<=n;i++) idx[i]=-1;

    for(int i=1;i<=n;i++)

    {

        if(idx[i]==-1)

        {

            t=0;

            top=0;

            tarjan(i);

        }

    }

    out<<c<<'\n';

    for(int i=1;i<=c;i++)

    {

        for(auto it:comp[i]) out<<it<<" ";

        out<<'\n';

    }

    return 0;

}

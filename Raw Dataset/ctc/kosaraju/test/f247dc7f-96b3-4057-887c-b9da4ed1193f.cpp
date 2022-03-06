#include<bits/stdc++.h>
using namespace std;

ifstream f("ctc.in");

ofstream g("ctc.out");

int n,m1,m[100001],p[100001],i,j,nrc,y,x;

stack <int> st;

vector <int>G[100001],GT[100001],ctc[100001];

void dfs1(int nod)

{

    p[nod]=1;

    for(int i=0;i<G[nod].size();i++)

        if(!p[G[nod][i]])

        dfs1(G[nod][i]);

    st.push(nod);

}

void dfs2(int nod)

{

    m[nod]=nrc;

    for(int i=0;i<GT[nod].size();i++)

        if(!m[GT[nod][i]])

        dfs2(GT[nod][i]);

}

int main()

{

    f>>n>>m1;

    for(i=1;i<=m1;i++)

    {

        f>>x>>y;

        G[x].push_back(y);

        GT[y].push_back(x);

    }

    for(i=1;i<=n;i++)

    {

        if(p[i]==0)

            dfs1(i);

    }

    while(!st.empty())

    {

        int k=st.top();



        st.pop();

        if(m[k]==0)

        {

            nrc++;

            dfs2(k);

        }

    }

    for(i=1;i<=n;i++)

        ctc[m[i]].push_back(i);

    g<<nrc<<'\n';

    for(i=1;i<=nrc;i++)

    {

        for(j=0;j<ctc[i].size();j++)

            g<<ctc[i][j]<<" ";

        g<<'\n';

    }

    return 0;

}

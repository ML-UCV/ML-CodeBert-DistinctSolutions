#include <bits/stdc++.h>


using namespace std;



ifstream in("ctc.in");

ofstream out("ctc.out");



int const lim = 100001;

int n,m,t;

bool ver[lim],vr[lim];

vector < int > c[lim];

vector < int > c2[lim];

vector < int > st;

vector < int > afis[lim];



void dfs(int nod)

{

    ver[nod]=1;



    for(int i=0;i<c[nod].size();i++)

      if(ver[c[nod][i]]==0)

        dfs(c[nod][i]);



    st.push_back(nod);

}



void dfs2(int nod)

{

    vr[nod]=1;

    afis[t].push_back(nod);

    for(int i=0;i<c2[nod].size();i++)

        if(vr[c2[nod][i]]==0)

         dfs2(c2[nod][i]);

}



int main()

{

    in>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int x,y;

        in>>x>>y;

        c[x].push_back(y);

        c2[y].push_back(x);

    }



    for(int i=1;i<=n;i++)

        if(ver[i]==0)

    {

        dfs(i);

    }



    for(int i=st.size()-1;i>=0;i--)

        if(vr[st[i]]==0)

    {

        t++;

        dfs2(st[i]);

    }



    out<<t<<'\n';

    for(int i=1;i<=t;i++)

    {

        for(int j=0;j<afis[i].size();j++)

            out<<afis[i][j]<<" ";

        out<<'\n';

    }

}

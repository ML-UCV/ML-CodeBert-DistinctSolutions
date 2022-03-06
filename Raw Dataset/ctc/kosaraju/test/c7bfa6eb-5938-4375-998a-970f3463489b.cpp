#include <bits/stdc++.h>


using namespace std;

ifstream in("ctc.in");

ofstream out("ctc.out");

const int Max=100005;

bool viz[Max]; int n,m,nr;

stack <int>s;

vector <int>v[Max],vt[Max],ctc[Max];

void dfs(int nod)

{

    viz[nod]=1;

    for(int j=0;j<v[nod].size();j++)

    {

        int vecin=v[nod][j];

        if(!viz[vecin])

            dfs(vecin);

    }

    s.push(nod);

}

void dfs2(int nod)

{

    viz[nod]=0;

    for(int j=0;j<vt[nod].size();j++)

    {

        int vecin=vt[nod][j];

        if(viz[vecin])

            dfs2(vecin);

    }

    ctc[nr].push_back(nod);

}

void citire()

{

   in>>n>>m;

   for(int i=1;i<=m;i++)

   {

       int x,y; in>>x>>y;

       v[x].push_back(y);

       vt[y].push_back(x);

   }

}

int main()

{

    citire();

    for(int i=1;i<=n;i++)

        if(!viz[i])

           dfs(i);

    while(!s.empty())

    {

        int nod=s.top(); s.pop();

        if(viz[nod])

        {

            nr++;

             dfs2(nod);

        }



    }

    out<<nr<<" "<<"\n";

    for(int i=1;i<=nr;i++)

    {

        for(int j=0;j<ctc[i].size();j++)

            out<<ctc[i][j]<<" ";

        out<<"\n";

    }

    return 0;

}

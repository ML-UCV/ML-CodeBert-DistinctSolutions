#include <bits/stdc++.h>


using namespace std;



ifstream Fin("ctc.in");

ofstream Fout("ctc.out");



int const limita = 100001;

int n,m,t;

bool ver[limita],vr[limita];

vector < int > vector1[limita];

vector < int > c2[limita];

vector < int > st;

vector < int > afisare[limita];



void dfs(int NOD)

{

    ver[NOD]=1;



    for(int i=0;i<vector1[NOD].size();i++)

      if(ver[vector1[NOD][i]]==0)

        dfs(vector1[NOD][i]);



    st.push_back(NOD);

}



void dfs2(int NOD)

{

    vr[NOD]=1;

    afisare[t].push_back(NOD);

    for(int i=0;i<c2[NOD].size();i++)

        if(vr[c2[NOD][i]]==0)

         dfs2(c2[NOD][i]);

}



int main()

{

    Fin>>n>>m;

    for(int i=1;i<=m;i++)

    {

        int x,y;

        Fin>>x>>y;

        vector1[x].push_back(y);

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



    Fout<<t<<'\n';

    for(int i=1;i<=t;i++)

    {

        for(int j=0;j<afisare[i].size();j++)

            Fout<<afisare[i][j]<<" ";

        Fout<<'\n';

    }

}

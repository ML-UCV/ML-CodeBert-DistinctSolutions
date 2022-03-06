#include <bits/stdc++.h>


using namespace std;

ifstream fin("ctc.in");

ofstream fout("ctc.out");

vector<int> g[100009], gt[100009], sol[100009];

stack<int> H;

int uz[100009];

int n,m;

int nrc;

void citire();

void dfs(int k);

void dfs1(int k);

void afis();



int main()

{int i;

    citire();

 for(i=1;i<=n;i++)

    if(!uz[i])

       {nrc++;dfs(i);}

 nrc=0;

 memset(uz,0,sizeof(uz));

 while(!H.empty())

    {

     int act=H.top();

     H.pop();

     if(!uz[act])

        nrc++,dfs1(act);

    }

  afis();

    return 0;

}

void citire()

{int i,x,y;

  fin>>n>>m;

  for(i=1;i<=m;i++)

    {

      fin>>x>>y;

      g[x].push_back(y);

      gt[y].push_back(x);

    }



}

void dfs1(int k)

{

  uz[k]=nrc;

  sol[nrc].push_back(k);

  for(int i=0;i<gt[k].size();i++)

    {

     int act=gt[k][i];

     if(!uz[act])

        dfs1(act);

    }

}

void dfs(int k)

{

  int i;

  uz[k]=nrc;

  for(i=0;i<g[k].size();i++)

    {

     int vec=g[k][i];

     if(!uz[vec])

     dfs(vec);

    }

  H.push(k);

}

void afis()

{int i,j;

  fout<<nrc<<'\n';

  for(i=1;i<=nrc;i++)

    {for(j=0;j< sol[i].size();j++)

       fout<<sol[i][j]<<" ";

    fout<<'\n';

    }

}

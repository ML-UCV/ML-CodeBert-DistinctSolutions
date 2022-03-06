#include <bits/stdc++.h>
using namespace std;

int viz[100009],n,m,k,nctc,SDV[100009];



vector <int> G[100009],GT[100009],CTC[100009];





void DFS(int x)

{

    int i,j;

 viz[x]=1;

 for(i=0;i<G[x].size();i++)

  {

      j=G[x][i];

      if(!viz[j])

                DFS(j);

  }

 SDV[++k]=x;

}



void DFS2(int x)

{

    int i,j;

 viz[x]=1;

 CTC[nctc].push_back(x);

 for(i=0;i<GT[x].size();i++)

  {

      j=GT[x][i];

      if(!viz[j])

                DFS2(j);

  }

}



int main()

{

 int n,m,x,y,i,j;

 ifstream f("ctc.in");

 ofstream o("ctc.out");



 f>>n>>m;

 for(i=1;i<=m;i++)

 {

  f>>x>>y;

  G[x].push_back(y);

  GT[y].push_back(x);

 }



 for(i=1;i<=n;++i)

  if(!viz[i])

            DFS(i);



 for(i=1;i<=n;i++)

        viz[i]=0;



 for(i=n;i>=1;i--)

  if(!viz[SDV[i]])

        {

            nctc++;

            DFS2(SDV[i]);

        }



 o<<nctc<<'\n';

 for(i=1;i<=nctc;i++)

 {

  for(j=0;j<CTC[i].size();j++)

   o<<CTC[i][j]<<' ';

  o<<"\n";

 }



 return 0;

}

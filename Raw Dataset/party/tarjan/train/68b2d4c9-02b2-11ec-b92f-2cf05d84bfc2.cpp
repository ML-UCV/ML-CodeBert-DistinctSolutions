#include <fstream>
#include <stdlib.h>
#include <time.h>  
using namespace std;

ifstream fi("party.in");

ofstream fo("party.out");

int N,M;

int E[2001][2];

int X[201];

int pasi,v,i;

int var;

int x,y;

int t;

int rez;

int modul(int a)

{

 if (a<0)

  return -a;

 return a;

}

int main()

{

 srand (time(NULL));

 fi>>N>>M;

 for(i=1;i<=M;i++)

 {

  fi>>x>>y>>t;

  if(t==0)

  {

   E[i][0]=x;

   E[i][1]=y;

  }

  if(t==1)

  {

   E[i][0]=x;

   E[i][1]=-y;

  }

  if(t==2)

  {

   E[i][0]=-x;

   E[i][1]=y;

  }

  if(t==3)

  {

   E[i][0]=-x;

   E[i][1]=-y;

  }

 }

 pasi=0;

 while(1)

 {



  for (i=1;i<=M;i++)

  {

   if (E[i][0]>0 && E[i][1]>0)

    v=X[E[i][0]] | X[E[i][1]];

   if (E[i][0]>0 && E[i][1]<0)

    v=X[E[i][0]] | (1-X[-E[i][1]]);

   if (E[i][0]<0 && E[i][1]>0)

    v=(1-X[-E[i][0]]) | X[E[i][1]];

   if (E[i][0]<0 && E[i][1]<0)

    v=(1-X[E[i][0]]) | (1-X[-E[i][1]]);

   if (v==0)

    break;

  }

  if (v==0)

  {

   var=rand() % 2;

   X[modul(E[i][var])]=1-X[modul(E[i][var])];

  }

  else

   break;

 }

 for (i=1;i<=N;i++)

  if(X[i]==1)

   rez++;

 fo<<rez<<"\n";

 for(i=1;i<=N;i++)

  if(X[i]==1)

   fo<<i<<"\n";

 fi.close();

 fo.close();

 return 0;

}

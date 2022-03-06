#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;



ifstream fi("party.in");

ofstream fo("party.out");

int n,m;

int P[1001][2];

int X[101];



int cauta()



{

 for (int i=1;i<=m;i++)

 {



  int a,b;

  if (P[i][0]>0)

   a=X[P[i][0]];

  else

   a=1-X[-P[i][0]];

  if (P[i][1]>0)

   b=X[P[i][1]];

  else

   b=1-X[-P[i][1]];

  if (a+b==0)

   return i;

 }

 return 0;

}



int main()

{

 srand(time(NULL));

 fi>>n>>m;

 for (int i=1;i<=m;i++)

 {

  int a,b,c;

  fi>>a>>b>>c;

  if (c==0)

  {

   P[i][0]=a;

   P[i][1]=b;

  }

  if (c==1)

  {

   P[i][0]=a;

   P[i][1]=-b;

  }

  if (c==2)

  {

   P[i][0]=-a;

   P[i][1]=b;

  }

  if (c==3)

  {

   P[i][0]=-a;

   P[i][1]=-b;

  }

 }



 for (int i=1;i<=n;i++)

  X[i]=1;



 while (1)

 {

  int poz=cauta();

  if (poz==0)

   break;

  else

  {

   int r;

   r=rand() % 2;

   int var;

   var=P[poz][r];

   if (var<0)

    var=-var;

   X[var]=1-X[var];

  }

 }

 int rez;

 rez=0;

 for (int i=1;i<=n;i++)

  rez=rez+X[i];

 fo<<rez<<"\n";

 for (int i=1;i<=n;i++)

  if (X[i]==1)

   fo<<i<<"\n";

 fi.close();

 fo.close();

 return 0;

}

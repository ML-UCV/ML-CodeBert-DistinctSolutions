#include<fstream>
using namespace std;

ifstream fi("party.in");

ofstream fo("party.out");

int N, M;

int x[1000], E[1000][2];

int i,v;

int modul(int a)

{

 if (a < 0) return - a;

 return a;

}

int main()

{

 fi >> N >> M;

 for (i = 1; i <= M; i++)

 {

  int a;

  fi >> E[i][0] >> E[i][1];

  fi >> a;

  if (a == 1) E[i][1] = -E[i][1];

  if (a == 2) E[i][0] = -E[i][0];

  if (a == 3) {E[i][1] = -E[i][1]; E[i][0] = -E[i][0];}



 }

 for (i = 1; i <= N; i++)

  x[i] = rand() % 2;

 while(1)

 {



  for (i = 1; i <= M; i++)

  {

   if (E[i][0] > 0 && E[i][1] > 0) v = x[E[i][0]] | x[E[i][1]];

   if (E[i][0] > 0 && E[i][1] < 0) v = x[E[i][0]] | (1-x[-E[i][1]]);

   if (E[i][0] < 0 && E[i][1] > 0) v = (1-x[-E[i][0]]) | x[E[i][1]];

   if (E[i][0] < 0 && E[i][1] < 0) v = (1-x[-E[i][0]]) | (1-x[-E[i][1]]);

   if (v==0) break;

  }

  int var;

  if (!v)

  {

   var = rand() % 2;

   x[modul(E[i][var])] = 1 - x[modul(E[i][var])];

  }

  else break;

 }

 int rez = 0;

 for (i = 1; i <= N; i++) rez += x[i];

 fo << rez<<'\n';

 for (i = 1; i <= N; i++) if (x[i]) fo << i << '\n';

 fi.close();

 fo.close();

 return 0;

}

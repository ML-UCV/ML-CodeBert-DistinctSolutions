#include <time.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

int n, m, x[101], nr, T=(1<<20), S[1001][2], k;



int eval(){

 int i, v1, v2;

 for(i=1; i<=m; i++){

  if(S[i][0]>0) v1 = x[S[i][0]];

  else v1 = 1-x[-S[i][0]];



  if(S[i][1]>0) v2 = x[S[i][1]];

  else v2 = 1-x[-S[i][1]];



  if(v1==0 && v2==0){

   k=i;

   return 0;

  }

 }

 return 1;

}



void schimba(){

 int pos=rand()%2,

  op=S[k][pos];

 if(op<0) x[-op]=1-x[-op];

 else x[op]=1-x[op];

}



int ok(){

 int i;

 for(i=1; i<=n; i++) if(x[i]) return 1;

 return 0;

}







int main(){

 int i, c;



 ifstream f("party.in");

 ofstream g("party.out");

 f>>n;

 f>>m;

 for(i=1; i<=m; i++) {

  f>>S[i][0]>>S[i][1]>>c;

  if(c==1) S[i][1]*=-1;

  if(c==2) S[i][0]*=-1;

  if(c==3) S[i][0]*=-1, S[i][1]*=-1;

 }



  for(i=1; i<=n; i++){

  c=rand();

  x[i] = c%2;

  }



  while(T--){

  if(eval()) break;
  else schimba();

  }

 if(T<0) while(1);

 for(i=1; i<=n; i++) if(x[i]) nr++;

 g<<nr<<"\n";

 for(i=1; i<=n; i++) if(x[i]) g<<i<<"\n";

 f.close();

 g.close();

 return 0;

}

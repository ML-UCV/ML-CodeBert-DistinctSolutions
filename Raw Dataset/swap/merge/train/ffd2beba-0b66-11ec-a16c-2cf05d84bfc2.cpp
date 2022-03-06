#include <fstream>
#include <string.h>
#include <queue>
using namespace std;

ifstream fi("swap.in");

ofstream fo("swap.out");

char A[50002],B[50002];

int FA[26],FB[26];

deque <int> POZB[26];

deque <int> :: iterator it;

int AIB[50002],naib=50000;



long long rez;



void update(int poz, int v)



{

 while (poz<=naib)

 {

  AIB[poz]+=v;

  poz=poz+(poz&(-poz));

 }

}



int f(int poz)

{

 int rez;

 rez=0;

 while (poz>=1)

 {

  rez=rez+AIB[poz];

  poz=poz-(poz&(-poz));

 }

 return rez;

}



int query(int st, int dr)

{

 return f(dr)-f(st-1);

}



int main()

{

 fi>>A+1;

 fi>>B+1;

 for (int i=1;A[i]!='\0';i++)

  FA[A[i]-'a']++;

 for (int i=1;B[i]!='\0';i++)

  FB[B[i]-'a']++;

 int t=1;

 for (int i=0;i<=25;i++)

  if (FA[i]!=FB[i])

   t=0;

 if (t==0)

  fo<<-1;

 else

 {





  for (int i=1;B[i]!='\0';i++)

   POZB[B[i]-'a'].push_back(i);

  int n=strlen(B+1);

  for (int i=1;i<=n;i++)

   update(i,1);

  rez=0;

  for (int i=1;i<=n;i++)

  {

   int c;

   c=A[i];

   int poz;

   poz=POZB[c-'a'].front();

   POZB[c-'a'].pop_front();

   update(poz,-1);

   rez=rez+query(1,poz);

  }

  fo<<rez;

 }

 fi.close();

 fo.close();

 return 0;

}

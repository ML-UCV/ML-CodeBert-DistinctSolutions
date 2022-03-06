#include <stdio.h>
#include <vector>






using namespace std;

char A[50005],B[50005];

vector <int> C[26];

inline int lit(char x)

{

 return x>='a' && x<='z';

}

int a,b,nr1[26],nr2[26],act[26],D[50005],aib[50005],rez;

void read()

{

 fgets(A+1,50005,stdin);

 fgets(B+1,50005,stdin);

 while (lit(A[a+1]))

 {

  a++;

  C[A[a]-'a'].push_back(a);

  nr1[A[a]-'a']++;

 }

 while (lit(B[b+1]))

 {

  b++;

  nr2[B[b]-'a']++;

 }

}

inline int verif()

{

 int i;

 for (i=0; i<26; i++)

  if (nr1[i]!=nr2[i])

   return 0;

 return 1;

}

int lsb(int x)

{

 return x & -x;

}

void update(int poz,int val)

{

 int i;

 for (i=poz; i<=b; i+=lsb(i))

  aib[i]+=val;

}

int query(int poz)

{

 int i,sum=0;

 for (i=poz; i>0; i-=lsb(i))

  sum+=aib[i];

 return sum;

}

void solve()

{

 int i,l;

 for (i=1; i<=b; i++)

 {

  l=B[i]-'a';

  D[i]=C[l][act[l]++];

 }

 for (i=b; i>=1; i--)

 {

  rez+=query(D[i]-1);

  update(D[i],1);

 }

}

int main()

{

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);

 read();

 if (!verif())

 {

  printf("-1\n");

  return 0;

 }

 solve();

 printf("%d\n",rez);

 return 0;

}

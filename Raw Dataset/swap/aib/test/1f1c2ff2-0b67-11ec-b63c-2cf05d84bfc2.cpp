#include<stdio.h>
#include<vector>
using namespace std;





int t[50010],n;

char a[50010],b[50010];

int lac[50010],cate[50010];

int rez;

vector<int> unde[50010];

inline int make_hash(char c)

{

 return c-'a';

}

inline int bit(int x)

{

 return (x&(x-1))^x;

}

void update(int poz)

{

 while(poz>0)

 {

  ++t[poz];

  poz-=bit(poz);

 }

}

int querry(int x)

{

 int cat=0;

 while(x<=n)

 {

  cat+=t[x];

  x+=bit(x);

 }

 return cat;

}

int main()

{

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);

 fgets(a+1,50010,stdin);

 fgets(b+1,50010,stdin);

 for(n=1; a[n]!='\n'; ++n)

 {

  int aux=make_hash(a[n]);

  ++cate[aux];

  unde[aux].push_back(n);

 }

 --n;

 for(int i=1; b[i]!='\n'; ++i)

 {

  int aux=make_hash(b[i]);

  if(lac[aux]==cate[aux])

  {

   printf("-1\n");

   return 0;

  }

  int x=unde[aux][lac[aux]++];

  rez+=x-i+querry(x);

  update(x-1);

 }

 printf("%d\n",rez);

 return 0;

}

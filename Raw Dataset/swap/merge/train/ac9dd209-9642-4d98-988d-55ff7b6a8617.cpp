#include<stdio.h>
#include<vector>
using namespace std;





char a[50010],b[50010];

int t[3*50010];

int x,y,rez;

int lac[26],cate[26],n;

vector<int> unde[26];

inline int make_hask(char c)

{

 return c-'a';

}

void update(int p,int u,int i)

{

 if(p>u)

  return;

 if(x<=p && u<=y)

 {

  ++t[i];

  return;

 }

 if(p==u)

  return;

 int mij=(p+u)>>1;

 if(x<=mij)

  update(p,mij,i<<1);

 if(mij<y)

  update(mij+1,u,(i<<1)+1);

}

void querry(int p,int u,int i)

{

 if(p>u)

  return;

 if(p==u && p==x)

 {

  y+=t[i];

  return;

 }

 if(p<=x && x<=u)

  y+=t[i];

 int mij=(p+u)>>1;

 if(x<=mij)

  querry(p,mij,i<<1);

 else

  querry(mij+1,u,(i<<1)+1);

}

int main()

{

 freopen("swap.in","r",stdin);

 freopen("swap.out","w",stdout);

 fgets(a+1,50010,stdin);

 fgets(b+1,50010,stdin);

 for(n=1; a[n]!='\n'; ++n)

 {

  int aux=make_hask(a[n]);

  unde[aux].push_back(n);

  ++cate[aux];

 }

 --n;

 for(int i=1; b[i]!='\n'; ++i)

 {

  int aux=make_hask(b[i]);

  y=0;

  if(cate[aux]==lac[aux])

  {

   printf("-1\n");

   return 0;

  }

  x=unde[aux][lac[aux]++];

  querry(1,n,1);

  rez+=x-i+y;

  y=x-1;

  x=1;

  update(1,n,1);

 }

 printf("%d\n",rez);

 return 0;

}

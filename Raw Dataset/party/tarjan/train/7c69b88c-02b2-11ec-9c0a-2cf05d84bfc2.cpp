#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<vector>
using namespace std;
int n,m,sol[102];

pair<int,int> v[1002];



inline int abs(int a){return a<0?-a:a;}



inline bool cond(int i)

{

 int x=sol[abs(v[i].first)],y=sol[abs(v[i].second)];

 if(v[i].first<0)

  x^=1;

 if(v[i].second<0)

  y^=1;

 return x|y;

}



int main()

{

 srand(time(0));

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);

 scanf("%d%d",&n,&m);

 int i,j,a,b,c;

 for(i=1;i<=m;i++)

 {

  scanf("%d%d%d",&a,&b,&c);

  if(c==1)

   b=b*-1;

  if(c==2)

   a=a*-1;

  if(c==3)

  {

   a=a*-1;

   b=b*-1;

  }

  v[i]=make_pair(a,b);

 }

 for(i=1;i<=n;i++)

  sol[i]=rand()%2;



 while(1)

 {

  for(j=1;j<=m;j++)

  {

   if(cond(j)==0)

   {

    if(rand()&1)

     sol[abs(v[j].first)]^=1;

    else

     sol[abs(v[j].second)]^=1;

    break;

   }

  }

  if(j==m+1)

  {

   int nr=0;

   for(j=1;j<=n;j++)

    nr+=sol[j];

   printf("%d\n",nr);

   for(j=1;j<=n;j++)

    if(sol[j])

     printf("%d\n",j);

   return 0;

  }

 }

 return 0;

}

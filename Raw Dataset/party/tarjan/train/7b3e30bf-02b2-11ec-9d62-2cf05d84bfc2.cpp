#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int n,m,sol[105];
struct muchie
{
 int a,b,c;
};
muchie A[1005];
void read()
{
 scanf("%d%d",&n,&m);
 int i;
 for (i=1; i<=m; i++)
  scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].c);
}
inline int eval(int tip,int x,int y)
{
 if (tip==0)

  return x | y;

 if (tip==1)

  return x | (!x && !y);

 if (tip==2)

  return y | (!x && !y);

 if (tip==3)

  return !x | !y;

 return 1;
}

inline int exista()

{

 int i;

 for (i=1; i<=n; i++)

  if (sol[i])

   return 1;

 return 0;

}
void solve()
{
 srand(time(0));
 int i,j,found,failed;
 for (i=1; i<=n; i++)
  sol[i]=rand()%2;
 for (i=1; i<=n*20; i++)
 {
  found=1; failed=1;
  for (j=1; j<=m; j++)
   if (!eval(A[j].c,sol[A[j].a],sol[A[j].b]))
   {
    found=0;
    failed=j;
    break ;
   }
  if (found)

  {

   if (exista())

    return ;
  }
  if (rand()%2==0)
   sol[A[failed].a]^=1;
  else
   sol[A[failed].b]^=1;
 }
}
void show()
{
 int i,nr=0;
 for (i=1; i<=n; i++)
  if (sol[i])
   nr++;
 printf("%d\n",nr);
 for (i=1; i<=n; i++)
  if (sol[i])
   printf("%d\n",i);
}
int main()
{
 freopen("party.in","r",stdin);
 freopen("party.out","w",stdout);
 read();
 solve();
 show();
 return 0;
}

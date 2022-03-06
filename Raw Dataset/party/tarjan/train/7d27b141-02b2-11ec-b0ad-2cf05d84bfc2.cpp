#include <cstdio>
#include <cstdlib>
#include <ctime>
int n,m,x[100000],y[100000],v[100000],rez,poz,tip,nr,sol[1000000];



inline int abs(int a) { return a>=0?a:-a; }



int verif(int i)

{

 int a,b;

 a=v[abs(x[i])];

 b=v[abs(y[i])];

 if (x[i]<0)

  a^=1;

 if (y[i]<0)

  b^=1;

 return a|b;

}



int main()

{

 int i,j;

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);



 scanf("%d %d", &n, &m);



 for (i=1;i<=m;++i)

 {

  scanf("%d %d %d", &x[i], &y[i],&tip);

  if (tip==1) y[i]=-y[i];

  if (tip==2) x[i]=-x[i];

  if (tip==3) x[i]=-x[i],y[i]=-y[i];

 }





 srand(time(0));

 for (i=1;i<=n;++i)

   v[i]=rand()%2;



 for (i=0;i<=n*25;++i)

 {

  rez=1;

  for (j=1;j<=m;++j)

  {

   rez&=verif(j);

   if (!rez)

   {

    poz=j;

    break;

   }

  }

  if (rez==1)

  {

   nr=0;

   for (j=1;j<=n;++j)

     if (v[j]) sol[++nr]=j;

   printf("%d\n", nr);

   for (j=1;j<=nr;++j) printf("%d\n", sol[j]);

   return 0;

  }

  if (rand()%2==0)

   v[abs(x[poz])]^=1;

  else

   v[abs(y[poz])]^=1;

 }



 fclose(stdin);

 fclose(stdout);



 return 0;



}

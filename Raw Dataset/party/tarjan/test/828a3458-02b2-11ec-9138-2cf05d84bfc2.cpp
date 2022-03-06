#include <cstdio>
#include <time.h>
#include <stdlib.h>




const int Nmax = 101;
const int Mmax = 1001;

int N,M,stare[Nmax],reqx[Mmax],reqy[Mmax],reqt[Mmax];

void readdata()
{
 int i;

 freopen("party.in","r",stdin);

 scanf("%d%d",&N,&M);

 for (i=1;i<=M;++i)
  scanf("%d%d%d",&reqx[i],&reqy[i],&reqt[i]);
}

void solve()
{
 int i,j,x,y,val=0,cnt=0;
 int stop;

 srand(time(0));

 for (i=1;i<=N;++i)
  if (rand()&3)
   stare[i]=1;
  else
   stare[i]=0;

 for (;;)
 {
  stop=1;

  for (i=1;i<=M;++i)
  {
   x=stare[reqx[i]];
   y=stare[reqy[i]];
   if ( reqt[i] == 0 )
    val=( x | y );
   if ( reqt[i] == 1 )
    val=( x | (y^1) );
   if ( reqt[i] == 2 )
    val=( (x^1) | y );
   if ( reqt[i] == 3 )
    val=( (x^1) | (y^1) );
   if ( val == 0 )
   {
    if (rand()&3)
     stare[reqx[i]]^=1;
    else
     stare[reqy[i]]^=1;
    stop=0;
   }
  }

  cnt=0;

  for (j=1;j<=N;++j)
   cnt+=stare[j];

  if ( stop && cnt ) break;
 }

 cnt=0;

 for ( i = 1; i <= N ; ++i )
  cnt+=stare[i];

 freopen("party.out","w",stdout);

 printf("%d\n",cnt);

 for ( i = 1; i <= N ; ++i )
  if (stare[i]) printf("%d\n",i);
}

int main()
{
 readdata();
 solve();
 return 0;
}

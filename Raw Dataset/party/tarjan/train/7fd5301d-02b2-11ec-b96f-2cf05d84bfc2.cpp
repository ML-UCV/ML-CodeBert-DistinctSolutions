#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
vector<int> G[256],TC[256];
int GR[256],INV[256],AP[256],ST[256];
int n,m,K;
int viz[256],uz[256];
int cd[256];
int poz[256];

inline int neg(int x)
{
 if (x>n) return x-K;
 return x+K;
}

void DF(int nod)
{
 viz[nod]=1;

 for (int i=0;i<G[nod].size();i++)
  if (!viz[ G[nod][i] ]) DF( G[nod][i] );
}

int main()
{
 freopen("party.in","r",stdin);
 freopen("party.out","w",stdout);

 int i,j,x,y,z,a,b,c,d,nod;

 scanf("%d %d",&n,&m);
 K=n;

 for (i=1;i<=m;i++)
 {
  scanf("%d %d %d",&x,&y,&z);

  if (z==0)
  {
   a=neg(x);b=neg(y);
   c=y;d=x;
  }

  if (z==2) swap(x,y);

  if ( (z==1) || (z==2) )
  {
   a=neg(x);b=y;
   c=neg(y);d=x;
  }

  if (z==3)
  {
   a=y;b=x;
   c=neg(x);d=neg(y);
  }

  G[a].push_back(c);
  G[b].push_back(d);
 }

 int nr=0;

 n*=2;
 for (i=1;i<=n;i++)
  if (AP[i]==0)
  {
   AP[i]=++nr;
   memset(viz,0,sizeof(viz));
   DF(i);

   for (j=1;j<=n;j++)
    uz[j]=viz[j];

   for (j=1;j<=n;j++)
    if (uz[j])
    {
     memset(viz,0,sizeof(viz));
     DF(j);
     if (viz[i]) AP[j]=AP[i];
    }
  }

 for (i=1;i<=n;i++)
 {
  x=AP[i];
  for (j=0;j<G[i].size();j++)
  {
   a=G[i][j];
   if ( AP[a]==x ) continue;
   GR[ AP[a] ]++;
   TC[x].push_back( AP[a] );
  }
  INV[ AP[i] ] = AP[ neg(i) ];
 }

 for (i=1;i<=nr;i++)
  if (!GR[i]) cd[ ++cd[0] ] = i;

 for (i=1;i<=cd[0];i++)
 {
  nod=cd[i];
  poz[nod]=i;
  for (j=0;j<TC[nod].size();j++)
  {
   GR[ TC[nod][j] ]--;
   if ( !GR[ TC[nod][j] ] ) cd[ ++cd[0] ] = TC[nod][j];
  }
 }


 vector<int> sol;



 for (i=1;i<=n/2;i++)
 {

  if ( poz[ AP[i] ]>poz[ AP[ neg(i) ] ]) sol.push_back(i);
 }

 printf("%d\n",sol.size());
 for (i=0;i<sol.size();i++)
  printf("%d\n",sol[i]);
 return 0;
}

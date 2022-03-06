#include<cstdio>
#include<math.h>
#include<vector>
#include<bitset>
using namespace std;

short int n,m,x,y,coada[1501*1501];

int z,nr[1501],rez[1501];

double d[1501];

bitset<1501> viz;

const double eps=1e-8;

const double eps1=eps*(-1);

vector<short int>a[1501],ap(1501,0);

vector<double>c[1501];

void citire()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);

 scanf("%hd%hd",&n,&m);

 for (int i=1; i<=m; ++i)

 {

  scanf("%hd%hd%d",&x,&y,&z);

  double g=log10(z);

  a[x].push_back(y);

  c[x].push_back(g);

  a[y].push_back(x);

  c[y].push_back(g);

 }

}

void bf()

{

 int p=0,u=0;

 coada[u++]=1;

 nr[1]=1;

 viz[1]=1;

 while (u!=p)

 {

  x=coada[p++];

  viz[x]=false;

  size_t g=a[x].size();

  for (size_t i=0; i!=g; ++i)

  {

   y=a[x][i];

   double aux=d[x]+c[x][i],diff=d[y]-aux;

   if (diff>=eps)

   {

    d[y]=aux;

    if (!viz[y])

    {

     viz[y]=true;

     coada[u++]=y;

    }

   }

  }

 }

}

void afis()

{

 for (int i=2; i<=n; ++i)

  printf("%d ",nr[i]);

}

void df(int x)

{

 viz[x]=1;

 size_t g=a[x].size();

 for (size_t i=0; i<g; ++i)

 {

  double diff=d[x]-d[a[x][i]]-c[x][i];

  if(diff<=eps&&diff>=eps1)

  {



   if (!viz[a[x][i]])

    df(a[x][i]);

   nr[x]+=nr[a[x][i]];

   if (nr[x]>=104659)

    nr[x]-=104659;

  }

 }

}

int main()

{

 citire();

 for (int j=2; j<=n; ++j)

  d[j]=1<<30;;

 bf();

 viz.reset();

 nr[1]=1;

 for (int i=2; i<=n; ++i)

  if (!viz[i])

   df(i);

 afis();







 return 0;

}

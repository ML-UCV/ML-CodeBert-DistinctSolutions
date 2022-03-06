#include<cstdio>
#include<vector>
#include<cmath>
#include<climits>






using namespace std;

const int N=2501,M=1000001;



int n,m,s[N],q[M],p,var[N],u;

double c[N];

bool viz[N];

struct xy{

 int to;

 double c;

};

vector <xy> v[N];



void read()

{

 int x,y,z;

 xy a;

 scanf("%d%d",&n,&m);

 for( int i=1 ; i<=m ; ++i )

 {

  scanf("%d%d%d",&x,&y,&z);

  a.c=log10((double)z);

  a.to=y;

  v[x].push_back(a);

  ++s[x];

  a.to=x;

  v[y].push_back(a);

  ++s[y];

 }

}



void ini()

{

 for( int i=2 ; i<=n ; ++i )

  c[i]=(double)INT_MAX;

}



void check( int x )

{

 for( int i=0 ; i<s[x] ; ++i )

  if( c[x]+v[x][i].c < c[v[x][i].to] )

  {

   c[v[x][i].to]=c[x]+v[x][i].c;

   q[++u]=v[x][i].to;

  }

}



void bf()

{

 p=1;

 u=1;

 q[1]=1;

 while(p<=u)

 {

  check(q[p]);

  ++p;

 }

}



inline double mod( double x )

{

 if( x<0 )

  return -x;

 return x;

}



void apel( int x )

{

 viz[x]=1;

 for( int i=0 ; i<s[x] ; ++i )

  if( mod( c[ v[x][i].to ] + v[x][i].c - c[x] ) <= 0.000000001 )

  {

   if( viz[v[x][i].to]==0 )

    apel( v[x][i].to );

   var[x]+=var[v[x][i].to];

   if(var[x]>104659)

    var[x]-=104659;

  }

}



void solve()

{

 ini();

 bf();

 var[1]=1;

 viz[1]=1;

 for( int i=2 ; i<=n ; ++i )

  if(viz[i]==0)

   apel(i);

}



void print()

{

 for( int i=2 ; i<=n ; ++i )

  printf("%d ",var[i]);

}



int main()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);

 read();

 solve();

 print();

 return 0;

}

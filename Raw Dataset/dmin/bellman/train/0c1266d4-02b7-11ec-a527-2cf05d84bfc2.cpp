#include<fstream>
#include<algorithm>
#include<cmath>


using namespace std;



typedef struct lol {

        int x,y;

        double z;

}troll;



const double EPS=1e-7;

const int MOD=104659;



int i,n,m,rs[1505];

double d[1505];

troll a[5005];



bool cmp(const troll &a,const troll &b) { return a.x<b.x; }



inline double ABS(double a) { return a>0 ? a:-a; }



int main()

{

  ifstream cin("dmin.in");

  ofstream cout("dmin.out");



  ios_base::sync_with_stdio(0);



  cin>>n>>m;



  for(i=1,m*=2;i<m;++i)

  {

    cin>>a[i].x>>a[i].y>>a[i].z; a[i].z=log(a[i++].z);

    a[i].x=a[i-1].y; a[i].y=a[i-1].x; a[i].z=a[i-1].z;

  }



  for(i=2;i<=n;++i) d[i]=-1;



  sort(a+1,a+m+1,cmp);



  for(rs[1]=i=1;i<=m;++i)

  if(d[a[i].x]!=-1 && (d[a[i].y]==-1 || d[a[i].y]-d[a[i].x]-a[i].z>EPS))

  d[a[i].y]=d[a[i].x]+a[i].z,rs[a[i].y]=rs[a[i].x];

  else if(d[a[i].x]!=-1 && ABS(d[a[i].y]-d[a[i].x]-a[i].z)<EPS) rs[a[i].y]+=rs[a[i].x],rs[a[i].y]%=MOD;



  for(i=2;i<=n;++i) cout<<rs[i]<<" \n"[i==n];



 return 0;

}

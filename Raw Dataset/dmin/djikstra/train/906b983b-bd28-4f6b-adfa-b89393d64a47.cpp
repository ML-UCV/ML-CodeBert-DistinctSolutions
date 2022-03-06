#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

ifstream f("dmin.in");

ofstream g("dmin.out");

vector<pair<int,double> > v[1510];

int x,y,n,m,i,A[1510],d,H[1510],L,P[1510];

double c,D[1510];

double ab(double x){if(x<0) return -x; return x;}

void urca(int po)

{

    while(po&&D[H[po]]<D[H[po>>1]])

    {

        swap(H[po],H[po>>1]);

        swap(P[H[po]],P[H[po>>1]]);

        po>>=1;

    }

}

void coboara(int po){

    int y=0;

    while(po!=y){

        y=po;

        if((y<<1)<=L&&D[H[y<<1]]<D[H[po]])

            po=y<<1;

        if((y<<1)+1<=L&&D[H[(y<<1)+1]]<D[H[po]])

            po=(y<<1)+1;

        swap(H[po],H[y]);

        swap(P[H[po]],P[H[y]]);

    }

}

int main ()

{

 f>>n>>m;

 for(i=1;i<=m;++i)

 {

  f>>x>>y>>c;

  v[x].push_back(make_pair(y,log(c)));

  v[y].push_back(make_pair(x,log(c)));

 }

 for(i=2;i<=n;++i)

  D[i]=1<<30;

 H[++L]=1;

 P[1]=1;

 A[1]=1;

 while(L)

 {

  x=H[1];

  H[1]=H[L--];

  coboara(1);

  for(i=0;i<v[x].size();++i)

  {

   d=v[x][i].first;

   c=v[x][i].second;

   if(ab(D[x]+c-D[d])>0.000001&&D[x]+c<D[d])

   {

    D[d]=D[x]+c;

    A[d]=A[x];

    if(!P[d])

    {

     H[++L]=d;

     P[d]=L;

     urca(L);

    }

    else

     urca(P[d]);

   }

   else

   if(ab(D[x]+c-D[d])<=0.000001)

   {

    A[d]+=A[x];

    if(A[d]>=104659)

     A[d]-=104659;

   }

  }

 }

 for(i=2;i<=n;++i)

  g<<A[i]<<" ";

 return 0;

}

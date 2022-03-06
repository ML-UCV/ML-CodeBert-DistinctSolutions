#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream f("cmap.in");

ofstream g("cmap.out");

struct Punct{

 int x,y;

};

Punct coord[100001],Banda[100001];

bool compx(const Punct &A,const Punct &B){

 return A.x<B.x;

}

bool compy(const Punct &A,const Punct &B){

 return A.y<B.y;

}

long long sqr(long long a){

 return a*a;

}



long long dist2(Punct A, Punct B){

 return sqr(A.x-B.x)+sqr(A.y-B.y);

}



long long distmin3(int p,int u){

 long long dmin=LONG_LONG_MAX,d;

 for(int i=p;i<u;i++)

  for(int j=i+1;j<=u;j++)

     if((d=dist2(coord[i],coord[j]))<dmin)dmin=d;

 return dmin;

}



long long Divide(int p,int u){

 if(u-p+1<=3) return distmin3(p,u);

 int m=(p+u)/2;

 long long ds=Divide(p,m);

 long long dd=Divide(m,u);

 long long dmin=min(ds,dd);
 int k=0;

 for(int i=p;i<=u;i++)

 if(sqr(coord[i].x-coord[m].x<dmin)){Banda[++k]=coord[i];}

 sort(Banda+1,Banda+k+1,compy);

 for(int i=1;i<k;i++)

  for(int j=i+1;j<=k && sqr(Banda[j].y-Banda[i].y)<dmin;j++)

   if((ds=dist2(Banda[i],Banda[j]))<dmin)dmin=ds;



 return dmin;

}



int main(){

 int n;

 f>>n;

 for(int i=1;i<=n;i++)

   f>>coord[i].x>>coord[i].y;

  sort(coord+1,coord+n+1,compx);

  double d=sqrt(Divide(1,n));

  g<<fixed<<setprecision(6)<<d;

}

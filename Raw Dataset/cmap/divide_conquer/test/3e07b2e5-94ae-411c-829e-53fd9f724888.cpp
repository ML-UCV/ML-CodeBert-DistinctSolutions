#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;





struct point{

int x,y;

};

int n;

point v[100005],aux[100005];

double distp(point p1, point p2){

return sqrt((double)((long long)((long long)p1.x-p2.x)*(p1.x-p2.x)+(long long)((long long)p1.y-p2.y)*(p1.y-p2.y)));}

bool cmp2(point p1, point p2){

return p1.x<p2.x;}

double dist_min(int st, int dr){

int m=(st+dr)>>1;

if(st>=dr)

return 1000000000.0;

if(st==dr-1){

if(v[st].y>v[dr].y){

point aux;

aux=v[st];

v[st]=v[dr];

v[dr]=aux;}

return distp(v[st],v[dr]);}

int mij=v[m].x;

double d1=dist_min(st,m);

double d2=dist_min(m+1,dr);

double d=min(d1,d2);

int i1=st,i2=m+1,i=st-1;

while(i1<=m && i2<=dr){

if(v[i1].y<=v[i2].y)

aux[++i]=v[i1++];

else

aux[++i]=v[i2++];}

for(;i1<=m;i1++)

aux[++i]=v[i1];

for(;i2<=dr;i2++)

aux[++i]=v[i2];

int nr=0;

for(i=st;i<=dr;i++){

v[i]=aux[i];

if(abs(v[i].x-mij)<=d)

aux[++nr]=v[i];}

double mini=1000000000.0;

int j;

for(i=1;i<=nr;i++)

for(j=i-1;j>=i-6 && j;j--)

mini=min(mini,distp(aux[i],aux[j]));

return min(mini,d);}

int main(){

freopen("cmap.in","r",stdin);

freopen("cmap.out","w",stdout);

scanf("%d",&n);

int i;

for(i=1;i<=n;i++)

scanf("%d%d",&v[i].x,&v[i].y);

sort(v+1,v+n+1,cmp2);

double sol=dist_min(1,n);

printf("%f\n",sol);

return 0;}

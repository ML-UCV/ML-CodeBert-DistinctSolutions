#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;
ifstream fin("cmap.in");
ofstream fout("cmap.out");

long long n,i,j,li,ls,rez;
struct pnct
{ int x,y; } p[100005];

bool cord(pnct x,pnct y)
{ return x.y<y.y; }
bool cabs(pnct x,pnct y)
{ return x.x<y.x; }

long long dis(pnct a,pnct b)
{
 long long x=a.x-b.x,y=a.y-b.y;
 return x*x+y*y;
}
long long cmap(long long st,long long dr)
{
 long long i,j,li,s=0,mx=0;
 if(dr-st<3)
 {
  mx=dis(p[st],p[st+1]);
  for(i=st;i<dr;i++)
   for(j=i+1;j<=dr;j++)
   {
    s=dis(p[i],p[j]);
    if(s<mx) mx=s;
   }
  return mx;
 }
 li=(st+dr)/2;
 mx=cmap(st,li);
 mx=min(mx,cmap(li+1,dr));

 pnct od[dr-st+5];
 long long dd=p[li].x,nre=0,gh=sqrt(mx);
 for(i=st;i<=dr;i++)
  if(abs(p[i].x-dd)<=gh)
  {
   nre++;
   od[nre]=p[i];
  }

 sort(od+1,od+nre+1,cord);
 for(i=1;i<nre;i++)
  for(j=i+1;j<=i+7&&j<=nre;j++)
  {
   s=dis(od[i],od[j]);
   if(s<mx) mx=s;
  }
 return mx;
}
int main () {

 fin>>n;
 for(i=1;i<=n;i++)
  fin>>p[i].x>>p[i].y;

 sort(p+1,p+n+1,cabs);

 rez=cmap(1,n);
 fout<<fixed<<setprecision(6)<<sqrt(rez)<<"\n";
}

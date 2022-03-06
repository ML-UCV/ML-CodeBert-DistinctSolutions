#include <bits/stdc++.h>

using namespace std;

ifstream in("schi.in");
ofstream out("schi.out");

int arb[120005],n,a[30005],ans[30005];

void create(int nod,int st,int dr)
{
 if(st==dr)
  arb[nod]=1;
 else
 {
  int mid=(st+dr)/2;
  create(2*nod,st,mid);
  create(2*nod+1,mid+1,dr);
  arb[nod]=arb[nod*2]+arb[nod*2+1];
 }
}

void update(int nod,int st,int dr,int k,int who)
{
 if(st==dr)
 {
  arb[nod]=0;
  ans[st]=who;
  return;
 }
 int mid=(st+dr)/2;
 if(arb[nod*2]<k)
  update(nod*2+1,mid+1,dr,k-arb[nod*2],who);
 else
  update(nod*2,st,mid,k,who);
 arb[nod]=arb[nod*2]+arb[nod*2+1];
}
int main()
{
 in>>n;
 for(int i=1;i<=n;i++)
 {
  in>>a[i];
 }


 create(1,1,n);
 for(int i=n;i>0;i--)
 {
  update(1,1,n,a[i],i);
 }
 for(int i=1;i<=n;i++)
  out<<ans[i]<<"\n";
 return 0;
}

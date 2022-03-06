#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using std::multimap;
using std::make_pair;
using std::sort;


int t[50005];

void u (int i,int v)
{
 while(i<50005)
  t[i]+=v,i+=(i&-i);
}

int g (int i)
{
 int s=0;
 while(i)
  s+=t[i],i-=(i&-i);
 return s;
}

int o[50005];
char a[50005];
char b[50005];

multimap<char, int> m;

long long r=0;

int main (void)
{
 freopen ("swap.in","r",stdin);




 fgets (a, 50001, stdin);
 fgets (b, 50001, stdin);

 int n=strlen (a);
 for(int i=0;i<n;i++)
  m.insert (make_pair (b[i],i+1));

 for(int i=0;i<n;i++){
  multimap<char, int>::iterator it=m.lower_bound (a[i]);
  if(a[i]!=it->first){
   printf ("-1");
   return 0;
  }
  o[i]=it->second;
  m.erase (it);
 }

 for(int i=0;i<n;i++){
  r+=i-g (o[i]+1);
  u (o[i]+1,1);
 }
 printf ("%lld", r);
 return 0;
}

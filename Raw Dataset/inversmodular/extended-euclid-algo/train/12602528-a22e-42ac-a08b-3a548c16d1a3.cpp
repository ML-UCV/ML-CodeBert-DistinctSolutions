#include <bits/stdc++.h>

using namespace std;

ifstream in("inversmodular.in");
ofstream out("inversmodular.out");

void euclid(long long a,long long b,long long &x,long long &y)
{
 if(b==0)
 {
  x=1;
  y=0;
 }
 else
 {
  euclid(b,a%b,x,y);
  long long aux=x;
  x=y;
  y=aux-(a/b)*y;
 }
}

int main()
{
 long long a,n,ans=0,ins;
 in>>a>>n;
 euclid(a,n,ans,ins);
 if(ans<=0)
  ans=n+(ans%n);
 out<<ans<<"\n";
 return 0;
}

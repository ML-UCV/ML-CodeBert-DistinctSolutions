#include <bits/stdc++.h>

using namespace std;
ifstream fin ("inversmodular.in");
ofstream fout ("inversmodular.out");
int gcdextins (int a,int b,int &x,int &y)
{
 if(b==0)
 {
  x=1;y=0;
  return a;
 }
 else
 {
  int x0,y0,d;
  d=gcdextins(b,a%b,x0,y0);
  x=y0;
  y=x0-(a/b)*y0;
  return d;
 }
}
int main ()
{
 int a,b,x,y,d;
 fin>>a>>b;
 d=gcdextins(a,b,x,y);
 while(x<0)
  x+=b;
 fout<<x;
}

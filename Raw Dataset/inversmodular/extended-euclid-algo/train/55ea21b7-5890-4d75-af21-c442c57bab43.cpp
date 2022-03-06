#include <iostream>
#include <fstream>

std::ifstream fin("inversmodular.in");
std::ofstream fout("inversmodular.out");

int a,n;

void euclid(int a, int b, long long &x, long long &y, long long &d)
{
  if(b==0)
  {
    d=a;
    x=1;
    y=0;
  }
  else
  {
    long long x0,y0;
    euclid(b,a%b,x0,y0,d);
    y=x0-(a/b)*y0;
    x=y0;
  }
}

int main()
{
  fin>>a>>n;
  long long x,y,d;
  euclid(a,n,x,y,d);
  if(x<0)
    x+=((-x)/n)*n;
  if(x<0)
    x+=n;
  fout<<x;
}

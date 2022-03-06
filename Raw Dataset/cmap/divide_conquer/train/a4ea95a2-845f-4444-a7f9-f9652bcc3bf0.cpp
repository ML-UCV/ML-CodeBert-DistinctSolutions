#include <bits/stdc++.h>
struct punct
{
  int x,y;
};

struct Comp1: std::binary_function<punct,punct,bool>
{
  bool operator()(punct p1, punct p2 )
  {
    if(p1.x!=p2.x)
      return p1.x<p2.x;
    return p1.y<p2.y;
  }
};
struct Comp2: std::binary_function<punct,punct,bool>
{
  bool operator()(punct p1, punct p2 )
  {
    if(p1.y!=p2.y)
      return p1.y<p2.y;
    return p1.x<p2.x;
  }
};

int n;
punct v[100500];
punct pp[100500];

long long calcD(punct p1, punct p2)
{
  long long d1=p1.x-p2.x;
  long long d2=p1.y-p2.y;
  return d1*d1+d2*d2;
}

long long dei(int f, int l)
{
  int size=l-f;
  if(size<=3)
  {
    long long prod1= calcD(v[f],v[f+1]);
    std::sort(v+f,v+l,Comp2());
    if(size==2) return prod1;
    prod1= std::max(calcD(v[f+1],v[f+2]),prod1);
    prod1= std::max(calcD(v[f+2],v[f]),prod1);
    return prod1;
  }
  int a=(f+l)/2;
  long long maxx=dei(f,a);
  maxx=std::min(maxx,dei(a,l));
  std::merge(v+f,v+a,
             v+a,v+l,
             pp+f,Comp2());
  std::copy(pp+f,pp+l,v+f);
  for(int i=f;i<l;i++)
    for(int j=i+1;j<l&&j-i<8;j++)
      maxx=std::min(maxx,calcD(v[i],v[j]));
  return maxx;
}

int main()
{
  freopen("cmap.in","r",stdin);
  freopen("cmap.out","w",stdout);
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d %d",&v[i].x,&v[i].y);
  std::sort(v,v+n,Comp1());
  std::copy(v,v+n,pp);
  printf("%llf",sqrtl(dei(0,n)));
}

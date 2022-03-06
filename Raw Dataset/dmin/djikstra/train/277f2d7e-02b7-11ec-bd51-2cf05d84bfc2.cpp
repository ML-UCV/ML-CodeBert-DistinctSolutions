#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;







const double inf=2147483647;
const double eps=1e-10;
int n,m,X;
vector< pair<int,double> > a[1510];
double d[1510];
int h[1510],nh,inheap[1510];
int nr[1510];
inline void citire()
{
 scanf("%d%d",&n,&m);
 X=1;
 int x,y,c;
 double c1;
 for(int i=0; i<m; ++i)
 {
  scanf("%d%d%d",&x,&y,&c);
  c1=log((double)c);
                a[x].push_back(make_pair(y,c1));
  a[y].push_back(make_pair(x,c1));
 }
}
inline char cmp(double x,double y)
{
 if(x+eps<y)
  return -1;
 if(y+eps<x)
  return 1;
 return 0;
}
inline int left_son(int x)
{
 return x<<1;
}
inline int right_son(int x)
{
 return (x<<1)+1;
}
inline int father(int x)
{
 return x>>1;
}
inline void upheap(int k)
{
 int key=h[k];
 while(k>1 && cmp(d[key],d[h[father(k)]])==-1)
 {
  h[k]=h[father(k)];
  inheap[h[k]]=k;
  k=father(k);
 }
 h[k]=key;
 inheap[h[k]]=k;
}
inline void downheap(int k)
{
 int son;
 do
 {
  son=0;
  if(left_son(k)<=nh)
  {
   son=left_son(k);
   if(right_son(k)<=nh && cmp(d[h[right_son(k)]],d[h[son]])==-1)
    son=right_son(k);
   if(cmp(d[h[son]],d[h[k]])!=-1)
    son=0;
  }
  if(son)
  {
   swap(h[k],h[son]);
   inheap[h[k]]=k;
   inheap[h[son]]=son;
   k=son;
  }
 }while(son);
}
inline void dijkstra()
{
 for(int i=1; i<=n; ++i)
  d[i]=inf;
        nh=1;
 nr[X]=1;
 h[1]=X;
 inheap[X]=1;
 d[X]=0;
 int next;
 double cost;
 char aux;
 while(nh>0)
 {
  int now=h[1];
  inheap[now]=0;
  h[1]=h[nh--];
  if(nh>0)
  {
   inheap[h[1]]=1;
   downheap(1);
  }
  for(size_t i=0,lim=a[now].size(); i<lim; ++i)
  {
   next=a[now][i].first;
   cost=a[now][i].second+d[now];
   aux=cmp(cost,d[next]);
   if(aux==-1)
   {
    d[next]=cost;
    nr[next]=nr[now];
    if(inheap[next]!=0)
     upheap(inheap[next]);
    else
    {
     h[++nh]=next;
     inheap[next]=nh;
     upheap(nh);
    }
   }
   else
   if(aux==0)
   {
    nr[next]+=nr[now];
    if(nr[next]>=104659)
     nr[next]-=104659;
   }
  }
 }
}
int main()
{
 freopen("dmin.in","r",stdin);
 freopen("dmin.out","w",stdout);
        citire();
        dijkstra();
        for(int i=2; i<n; ++i)
  printf("%d ",nr[i]);
 printf("%d\n",nr[n]);
 return 0;
}

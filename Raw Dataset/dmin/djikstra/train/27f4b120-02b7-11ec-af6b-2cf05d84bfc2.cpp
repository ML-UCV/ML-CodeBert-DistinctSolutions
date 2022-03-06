#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;

int nh,h[1505],inheap[1505];

int cate[1505];

double d[1505];

const double eps=0.0000000001;

const double inf=2147483647;

vector< pair<int,double> > a[1505];

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

inline double modul(double x)

{

 if(x<0)

  return -x;

 return x;

}

inline char compar(double x,double y)

{

 if(modul(x-y)<=eps)

  return 0;

 double dif=x-y;

 if(dif>0)

  return 1;

 return -1;

}

void upheap(int k)

{

 int key=h[k];

 while(k>1 && compar(d[key],d[h[father(k)]])==-1)

 {

  h[k]=h[father(k)];

  inheap[h[k]]=k;

  k=father(k);

 }

 h[k]=key;

 inheap[h[k]]=k;

}

void downheap(int k)

{

 int son;

 do

 {

  son=0;

  if(left_son(k)<=nh)

  {

   son=left_son(k);

   if(right_son(k)<=nh && compar(d[h[right_son(k)]],d[h[son]])==-1)

    son=right_son(k);

   if(compar(d[h[son]],d[h[k]])!=-1)

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

inline void citire()

{

 scanf("%d%d",&n,&m);

 int x,y,z;

 double aux;

 for(int i=0; i<m; ++i)

 {

  scanf("%d%d%d",&x,&y,&z);

  aux=(double)z;

  aux=log(aux);

  a[x].push_back(make_pair(y,aux));

  a[y].push_back(make_pair(x,aux));

 }

}

inline void dijkstra()

{

 for(int i=2; i<=n; ++i)

  d[i]=inf;

 nh=1;

 h[1]=1;

 inheap[1]=1;

 cate[1]=1;

 while(nh)

 {

  int now=h[1];

  h[1]=h[nh--];

  downheap(1);

  inheap[now]=0;

  for(int i=0,lim=a[now].size(); i<lim; ++i)

  {

   int next=a[now][i].first;

   char aux=compar(d[next],d[now]+a[now][i].second);

   if(!aux)

   {

    cate[next]+=cate[now];

    cate[next]%=104659;

   }

   else

   if(aux==1)

   {

    cate[next]=cate[now];

    d[next]=d[now]+a[now][i].second;

    if(inheap[next])

     upheap(inheap[next]);

    else

    {

     h[++nh]=next;

     inheap[next]=nh;

     upheap(nh);

    }

   }

  }

 }

}

inline void scrie()

{

 for(int i=2; i<n; ++i)

  printf("%d ",cate[i]);

 printf("%d\n",cate[n]);

}

int main()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);

 citire();

 dijkstra();

 scrie();

 return 0;

}

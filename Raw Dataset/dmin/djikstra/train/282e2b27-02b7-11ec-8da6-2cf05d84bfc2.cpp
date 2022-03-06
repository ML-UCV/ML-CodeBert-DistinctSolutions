#include<cstdio>
#include<math.h>
using namespace std;
int N, M;

int H[1504];

int poz[1504];

double d[1504];

int nr[1504];

int L;

struct Nod

{

 Nod *urm;

 int vf;

 double cst;

};

Nod *G[1504];

inline void insert(int x, int y, double cst)

{

 Nod *q = new Nod;

 q->vf = y; q->cst = cst;

 q->urm = G[x];

 G[x] = q;

}

void read()

{

 freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);

 scanf("%d%d",&N,&M);

 int i,x,y,cost;

 double c;

 for(i=1;i<=M;++i)

 {

  scanf("%d%d%d",&x,&y,&cost);

  c = log2(cost);

  insert(x,y,c); insert(y,x,c);

 }

}

inline void swap(int t, int f)

{

 int aux;

 aux = poz[H[t]]; poz[H[t]] = poz[H[f]]; poz[H[f]] = aux;

 aux = H[t]; H[t] = H[f]; H[f] = aux;

}

inline int cmp(double x, double y)

{

 if(x+1e-8 < y) return 1;

 if(y+1e-8 < x) return -1;

 return 0;

}

inline void upheap(int f)

{

 int t = f / 2;

 while(t && cmp(d[H[t]] , d[H[f]])==-1)

 {

  swap(t,f);

  f = f / 2; t = t / 2;

 }

}

inline void downheap(int t)

{

 int f;

 do

 {

  f = 0;

  if(2*t <= L) f = 2*t;

  if(2*t+1<=L && cmp(d[H[2*t+1]] , d[H[2*t]])==1 ) f = 2*t+1;

  if(f && cmp(d[H[f]] , d[H[t]])<=0) f = 0;

  if(f)

  {

   swap(t,f);

   t = f;

  }

 }

 while(f);

}

void preparing()

{

 int i;

 for(i=1;i<=N;++i)

 {

  H[++L] = i;

  poz[i] = L;

  d[i] = 2140000000;

 }

 d[1] = log2(1); nr[1] = 1;

}

void dijkstra()

{

 int x,y;

 Nod *q;

 while(L && d[H[1]] != 2140000000)

 {

  x = H[1];

  H[1] = H[L];

  poz[H[L]] = 1; poz[x] = -1;

  --L;

  downheap(1);

  for(q = G[x];q;q=q->urm)

  {

   y = q->vf;

   if(cmp(d[y] , d[x] + q->cst)==-1)

   {

    nr[y] = nr[x];

    d[y] = d[x] + q->cst;

    upheap(poz[y]);

   }

   else if(!cmp(d[y], d[x] + q->cst))

   {

    nr[y] += nr[x];

    if(nr[y] >= 104659) nr[y] -= 104659;

   }

  }

 }

}

void print()

{

 int i;

 for(i=2;i<=N;++i) printf("%d ",nr[i]);

 printf("\n");

}

int main()

{

 read();

 preparing();

 dijkstra();

 print();

 return 0;

}

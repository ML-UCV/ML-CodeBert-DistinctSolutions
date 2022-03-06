#include <cmath>
#include <cstdio>
using namespace std;



typedef long long int lli;

int const maxn=1500,maxm=2500,mod=104659;

double const eps=1e-8,inf=30*maxn;

int N,M,E3[maxm][3],H[maxn],J[maxn],hs,I[maxn+1],Ji[maxn],C[maxn];

struct Edge{int to;double w;} A[2*maxm];

double D[maxn];



void pop_heap()

{ int t,r,c;

 --hs;t=H[0];H[0]=H[hs];J[H[0]]=0;H[hs]=t;

 r=0;c=(2*(r+1))-1;

 while(c<hs)

 { if(((c+1)<hs)&&(D[H[c]]>D[H[c+1]]))

  {++c;}

  if(D[H[r]]>D[H[c]])

  { t=H[r];H[r]=H[c];J[H[r]]=r;H[c]=t;J[H[c]]=c;

   r=c;c=(2*(r+1))-1;

  }

  else{c=hs;}

 }

}



void decrease_key(int i,double v)

{ int r,c,t;

 D[i]=v;c=J[i];

 while(0<c)

 { r=(c-1)/2;

  if(D[H[c]]<D[H[r]])

  { t=H[c];H[c]=H[r];J[H[c]]=c;H[r]=t;J[H[r]]=r;

   c=r;

  }

  else{c=0;}

 }

}



void update(int x,int y,double v)

{ if(fabs(v-D[y])<eps)

 {C[y]=(C[y]+C[x])%mod;}

 else

 { if(v<D[y])

  { if(inf==D[y]){H[hs]=y;J[y]=hs;++hs;}

   decrease_key(y,v);C[y]=C[x];

  }

 }

}



void dijkstra()

{ int x,y,i,t;

 double w;

 for(x=0;N>x;++x){D[x]=inf;}

 hs=0;C[0]=1;update(0,0,0.0);

 while(0<hs)

 { pop_heap();x=H[hs];i=I[x];t=I[x+1];

  while(i<t)

  { y=A[i].to;w=A[i].w;

   update(x,y,D[x]+w);

   ++i;

  }

 }

}



int main()

{ freopen("dmin.in","r",stdin);

 freopen("dmin.out","w",stdout);

 scanf("%d %d",&N,&M);int i,x,y;double w;

 for(i=0;M>i;++i)

 { scanf("%d %d %d",&E3[i][0],&E3[i][1],&E3[i][2]);

  --E3[i][0];--E3[i][1];

 }

 for(i=0;N>i;++i){I[i]=0;}

 for(i=0;M>i;++i)

 { x=E3[i][0];y=E3[i][1];

  ++I[x];++I[y];

 }

 x=I[0];I[0]=0;

 for(i=1;N>=i;++i)

 {y=I[i];I[i]=I[i-1]+x;x=y;}

 for(i=0;N>i;++i){Ji[i]=I[i];}

 for(i=0;M>i;++i)

 { x=E3[i][0];y=E3[i][1];w=log(E3[i][2]);

  A[Ji[x]].to=y;A[Ji[x]++].w=w;

  A[Ji[y]].to=x;A[Ji[y]++].w=w;

 }

 if(1<N)

 { dijkstra();

  printf("%d",C[1]);

  for(i=2;N>i;++i)

  {printf(" %d",C[i]);}

 }

 return 0;

}

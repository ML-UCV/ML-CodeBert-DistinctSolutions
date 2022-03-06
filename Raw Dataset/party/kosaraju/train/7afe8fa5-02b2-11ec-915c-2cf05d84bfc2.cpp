#include <cstdio>
#include <cstring>




bool ok=true,viz[4000005];

int sol[4000005],ord[4000005],n,m,nr;



struct nod {

 int x;

 nod *urm;

} *g[4000005],*gt[4000005];



inline int non (int a) {

 return (a>n)?a-n:a+n;

}



void adaugare(int x, int y, bool z) {

 nod *p;

 p=new nod;

 p->x=y;

 if(z) {

  p->urm=g[x];

  g[x]=p;

 }else {

  p->urm=gt[x];

  gt[x]=p;

 }

}



void dfs(int sursa) {

 nod *p;

 if(viz[sursa]) return;

 viz[sursa]=true;

 for(p=g[sursa];p!=NULL; p=p->urm)

  if(!viz[p->x]) dfs(p->x);

 ord[++nr]=sursa;

}



void dfs_2(int sursa) {

 nod *p;

 if(viz[sursa]) return;

 viz[sursa]=true;

 sol[non(sursa)]=1;

 for(p=gt[sursa];p!=NULL; p=p->urm)

  if(!viz[p->x]) dfs_2(p->x);

}



int main()

{

 int x,y,z,i;

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);

 scanf("%d %d",&n,&m);

 for(i=1; i<=m; ++i) {

  scanf("%d %d %d",&x,&y,&z);

  if(z==1) y+=n;

  else if(z==2) x+=n;

  else if(z==3) y+=n,x+=n;

  adaugare(non(x),y,true);

  adaugare(non(y),x,true);

  adaugare(y,non(x),false);

  adaugare(x,non(y),false);

 }

 for(i=1; i<=n+n; ++i) if(!viz[i]) dfs(i);

 memset(viz,0,sizeof(viz));

 for(i=n+n; i; --i) if(!viz[ord[i]] && !viz[non(ord[i])]) dfs_2(ord[i]);

 nr=0;

 for(i=1; i<=n; ++i) if(sol[i]) ++nr;

 printf("%d\n",nr);

 for(i=1; i<=n; ++i) if(sol[i]) printf("%d\n",i);

 return 0;

}

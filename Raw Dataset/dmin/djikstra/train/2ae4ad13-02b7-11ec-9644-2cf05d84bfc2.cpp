#include<fstream>
#include<math.h>using namespace std;
double make_abs(double x)

 {

 if(x>0)return x;

 return -x;

 }



ifstream f("dmin.in");

ofstream g("dmin.out");

typedef struct _lista

 {

 int x;

 double c;

 _lista *urm;

 }*Lista;

typedef struct _listan

 {

 int x;

 _listan *urm;

 }*Listan;

typedef struct _nod

 {

 Lista l;

 }Nod;

Nod V[1501];

Listan prim=NULL;

double c[1501];

long mod[1501];

int v[1501],coada[1501],pi[1501],n,m,p,u;

void adauga(int x,int y,int cost)

 {

 Lista nou=new _lista;

 nou->x=y;nou->c=cost;

 nou->urm=V[x].l;

 V[x].l=nou;

 }

void citire()

 {

 int i,cost,x,y;

 f>>n>>m;

 for(i=1;i<=m;i++)

  f>>x>>y>>cost,adauga(x,y,cost),adauga(y,x,cost);

 }

void getmin(int p,int u)

 {

 int i,aux;

 double min=c[coada[p]];

 int minpoz=p;

 for(i=p+1;i<=u;i++)

  if(min>c[coada[i]])min=c[coada[i]],minpoz=i;

 aux=coada[p],coada[p]=coada[minpoz],coada[minpoz]=aux;

 }

void dijkstra(int k)

 {

 Lista i;

 p=u=1;coada[1]=k;

 v[k]=1;c[k]=0;

 while(p<=u)

  {

  getmin(p,u);

  k=coada[p];

  for(i=V[k].l;i;i=i->urm)

   if(!v[i->x])

    coada[++u]=i->x,v[i->x]=1,pi[i->x]=k,

       c[i->x]=c[k]+log(i->c);



   else

    if(c[i->x]>c[k]+log(i->c))

     pi[i->x]=k,c[i->x]=c[k]+log(i->c);

  p++;

  }

 }

void adauga(int x)

 {

 Listan nou=new _listan;

 nou->x=x;

 nou->urm=prim;

 prim=nou;

 }

void df(int k)

 {

 v[k]=1;

 Lista i;

 for(i=V[k].l;i;i=i->urm)

  if(!v[i->x])

   if(make_abs(c[k]+log(i->c)-c[i->x])<0.00001)

    df(i->x);

 adauga(k);

 }

int main()

{

int i;

Lista j;

citire();f.close();

dijkstra(1);

for(i=1;i<=n;i++)v[i]=0;

mod[1]=1;

df(1);

Listan ii;

for(ii=prim;ii;ii=ii->urm)

 {



 for(j=V[ii->x].l;j;j=j->urm)

  if(make_abs(c[ii->x]+log(j->c)-c[j->x])<0.00001)

   mod[j->x]=(mod[j->x]+mod[ii->x])%104659;

 }



for(i=2;i<=n;i++)

 g<<mod[i]%104659<<" ";

g.close();

return 0;

}

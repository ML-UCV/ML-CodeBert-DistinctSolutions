# include <stdio.h>
# include <string.h>
# include <stdlib.h>


const long int MAXN=50000;



typedef struct NOD {long int pos; NOD *next;};

typedef struct NODA {long int inf; NODA *stga,*drta;};

NODA *rad;



struct {NOD *prim,*ultim;} list[30];

long int n;

char s1[MAXN+10],s2[MAXN+10];



void add(long int i, long int pos)

{

NOD *p=(NOD*) malloc (sizeof(NOD));

(*p).pos=pos;(*p).next=NULL;

if (list[i].prim)

 {

 (*list[i].ultim).next=p;

 list[i].ultim=p;

 }

else

 {

 list[i].prim=p;

 list[i].ultim=p;

 }

}



void citire()

{

FILE *f=fopen("swap.in","r");

fgets(s1+1,MAXN+10,f);

fgets(s2+1,MAXN+10,f);

n=strlen(s1+1)-1;

fclose(f);

}



long int parity()

{

long int count[30]={0};

long int i;

for (i=1;i<=n;i++)

 {

 count[s1[i]-'a'+1]++;

 count[s2[i]-'a'+1]--;

 }

for (i=1;i<='z'-'a'+1;i++) if (count[i]!=0) return 0;

return 1;

}



void create()

{

long int i;

for (i=1;i<=n;i++)

 add(s1[i]-'a'+1,i);

}



void update(NODA *p, long int li, long int lf, long int a)

{

long int m=(li+lf)/2;

if (lf>=li)

 if (li==lf) (*p).inf++;

 else

  {

  if (a<=m)

   {

   (*p).inf++;

   update((*p).stga,li,m,a);

   }

  else

   {

   (*p).inf++;

   update((*p).drta,m+1,lf,a);

   }

  }

}



long int query(NODA *p,long int li, long int lf, long int a, long int b)

{

long int m=(li+lf)/2;

if (b>=a)

 {

 if (li==a&&lf==b) return (*p).inf;

 if (b<=m) return query((*p).stga,li,m,a,b);

 if (a>m ) return query((*p).drta,m+1,lf,a,b);

 return query((*p).stga,li,m,a,m)+query((*p).drta,m+1,lf,m+1,b);

 }

return 0;

}



long int calculeaza()

{

long int sol=0;

long int i;

for (i=1;i<=n;i++)

 {



 sol+=(*list[s2[i]-'a'+1].prim).pos-i+query(rad,1,n,(*list[s2[i]-'a'+1].prim).pos+1,n);

 update(rad,1,n,(*list[s2[i]-'a'+1].prim).pos);

 list[s2[i]-'a'+1].prim=(*list[s2[i]-'a'+1].prim).next;

 }

return sol;

}



void scrie(long int a)

{

FILE *g=fopen("swap.out","w");

fprintf(g,"%ld\n",a);

fcloseall();

}



void aloca(NODA *rad, long int li, long int lf)

{

NODA *p;

long int m=(li+lf)/2;

if (li<lf)

 {

 p=(NODA*) malloc (sizeof(NODA));

 (*p).inf=0;(*p).stga=NULL;(*p).drta=NULL;

 (*rad).stga=p;

 aloca(p,li,m);

 p=(NODA*) malloc (sizeof(NODA));

 (*p).inf=0;(*p).drta=NULL;(*p).drta=NULL;

 (*rad).drta=p;

 aloca(p,m+1,lf);

 }

}



int main()

{

citire();

rad=(NODA*) malloc (sizeof(NODA));

(*rad).inf=0;(*rad).stga=(*rad).drta=NULL;

aloca(rad,1,n);

create();

if (!parity()) scrie(-1);

else scrie(calculeaza());

return 0;

}

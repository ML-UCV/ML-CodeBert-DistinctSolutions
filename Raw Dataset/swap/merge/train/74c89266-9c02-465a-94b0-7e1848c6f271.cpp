#include<stdio.h>



int a[50001],b[50001],poz[50001],apar[27][50001],segm[128*50001];
int a1,b1,sol,cost,value;
FILE *in,*out;

void ins_del(int nod,int st,int dr) {
int m;
 if (a1==st && dr==a1) segm[nod]=value;

 else {
  m=(st+dr)/2;
  if (a1<=m) ins_del(2*nod,st,m);
  else ins_del(2*nod+1,m+1,dr);
  segm[nod]=segm[2*nod]+segm[2*nod+1];
 }
}

void query(int nod,int st,int dr) {
int m;
 if (a1<=st && dr<=b1) cost+=segm[nod];
 else {
  m=(st+dr)/2;
  if (a1<=m) query(2*nod,st,m);
  if (b1>m) query(2*nod+1,m+1,dr);
 }
}

int main() {
int i,good=1;
char cache;
 in=fopen("swap.in","r"); out=fopen("swap.out","w");

 cache=fgetc(in);
 while (cache!='\n') {
  a[++a[0]]=(int)cache-'a';
  cache=fgetc(in);
 }

   cache=fgetc(in);
 while (cache!='\n' && cache!=EOF) {
  b[++b[0]]=(int)cache-'a';
  cache=fgetc(in);
 }

 for (i=1;i<=a[0];++i) apar[a[i]][++apar[a[i]][0]]=i;

 for (i=0;i<27;++i) apar[i][0]=1;

 value=1;

 for (i=1;i<=b[0];++i) {
  if (!apar[b[i]][apar[b[i]][0]]) { good=0; break; }

  else
   poz[i]=apar[b[i]][apar[b[i]][0]++];
  a1=i;
  ins_del(1,1,a[0]);
 }

 value=0;

 if (!good) fprintf(out,"-1\n");

 else {

  for (i=1;i<=b[0];++i) {

   a1=1; b1=poz[i];
   cost=0;
   query(1,1,a[0]);

   sol+=cost-1;

   a1=poz[i];
   ins_del(1,1,a[0]);

  }

  fprintf(out,"%i\n",sol);
 }

 fclose(in); fclose(out);

 return 0;
}

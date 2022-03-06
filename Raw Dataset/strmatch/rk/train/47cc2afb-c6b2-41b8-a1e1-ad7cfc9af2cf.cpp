#include <stdio.h>
#include <string.h>
char a[2000001],b[2000001];

int v[2000001];

int main(){

  FILE *fin=fopen("strmatch.in","r");

  FILE *fout=fopen("strmatch.out","w");

  int n,m,i,am1,am2,bm1,bm2,p1,p2,sol=0;



  fscanf(fin,"%s",&a);

  fscanf(fin,"%s",&b);

  n=strlen(a);

  m=strlen(b);

  if(n>m)

    sol=0;

  else{

    am1=am2=bm1=bm2=0;

    for(i=0; i<n; i++){

      am1=(am1*73 +a[i])%957091;

      am2=(am2*73 +a[i])%666013;

      bm1=(bm1*73 +b[i])%957091;

      bm2=(bm2*73 +b[i])%666013;

    }

    if(am1==bm1 && am2==bm2)

      v[sol++]=0;

    p1=p2=1;

    for(i=1; i<n; i++){

      p1=(p1*73)%957091;

      p2=(p2*73)%666013;

    }

    for(i=n; i<m; i++){

      bm1=((bm1-b[i-n]*p1%957091 +957091)*73 +b[i])%957091;

      bm2=((bm2-b[i-n]*p2%666013 +666013)*73 +b[i])%666013;

      if(am1==bm1 && am2==bm2)

        v[sol++]=i-n+1;

    }

  }

  fprintf(fout,"%d\n",sol);

  sol=1000<sol ? 1000:sol;

  for(i=0; i<sol; i++)

    fprintf(fout,"%d ",v[i]);

  fclose(fin);

  fclose(fout);

  return 0;

}

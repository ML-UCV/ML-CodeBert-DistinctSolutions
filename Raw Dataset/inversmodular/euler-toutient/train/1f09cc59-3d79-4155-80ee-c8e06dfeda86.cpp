#include <stdio.h>


long long phi(long long n){

  long long d=2,r=n;



  while(d*d<=n){

    if(n%d==0){

      while(n%d==0)

        n/=d;

      r=r/d*(d-1);

    }

    d++;

  }

  if(n>1)

    r=r/n*(n-1);

  return r;

}



long long exp(long long x, long long y, long long MOD){

  long long r=1;



  while(y){

    if(y%2)

      r=(r*x)%MOD;

    x=(x*x)%MOD;

    y/=2;

  }

  return r;

}



int main(){

    FILE *fin=fopen("inversmodular.in","r");

    FILE *fout=fopen("inversmodular.out","w");

    long long a,n;



    fscanf(fin,"%lld%lld",&a,&n);

    fprintf(fout,"%lld\n",exp(a,phi(n)-1,n));

    fclose(fin);

    fclose(fout);

    return 0;

}

#include <iostream>
#include <cstdio>


using namespace std;



int v[30001], aib[30001], sol[30001], n;



int len(int x) {

  return (x-(x&(x-1)));

}



void update(int poz, int val) {

  while(poz<=n) {

    aib[poz]+=val;

    poz+=len(poz);

  }

}



int query(int x) {

  int pas, rez;

  pas=(1<<30);

  rez=0;

  while(pas>0) {

    if(rez+pas<=n && aib[rez+pas]<x) {

      rez+=pas;

      x-=aib[rez];

    }

    pas/=2;

  }

  rez++;

  return rez;

}



int main() {

  FILE *fin, *fout;

  int i, poz;

  fin=fopen("schi.in","r");

  fout=fopen("schi.out","w");

  fscanf(fin, "%d ",&n);

  for(i=1;i<=n;i++) {

    fscanf(fin, "%d",&v[i]);

    update(i,1);

  }

  for(i=n;i>0;i--) {

    poz=query(v[i]);

    sol[poz]=i;

    update(poz,-1);

  }

  for(i=1;i<=n;i++)

    fprintf(fout, "%d\n",sol[i]);

  return 0;

}

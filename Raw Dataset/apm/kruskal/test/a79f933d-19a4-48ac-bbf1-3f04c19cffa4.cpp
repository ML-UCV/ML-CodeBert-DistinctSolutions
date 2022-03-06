#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;



struct ura {

  int st, dr, cost;

  bool corect;

};



ura v[400005], sol[400005];

int sef[200005];



bool cmp(ura a, ura b) {

  if(a.cost<b.cost)

    return 1;

  return 0;

}



int sefsuprem(int x) {

  if(x==sef[x])

    return x;

  else

    return sef[x]=sefsuprem(sef[x]);

}



int main() {

  FILE *fin, *fout;

  int n, m, i, aux, nr, s, sef1, sef2;

  fin=fopen("apm.in","r");

  fout=fopen("apm.out","w");

  fscanf(fin, "%d%d",&n,&m);

  for(i=1;i<=m;i++)

    fscanf(fin, "%d%d%d",&v[i].st,&v[i].dr,&v[i].cost);

  sort(v+1,v+m+1,cmp);

  for(i=1;i<=n;i++)

    sef[i]=i;

  nr=0;

  i=1;

  s=0;

  while(nr<n-1 && i<=m) {

    sef1=sefsuprem(v[i].st);

    sef2=sefsuprem(v[i].dr);

    if(sef1!=sef2) {

      nr++;

      s+=v[i].cost;

      v[i].corect=1;

      sef[sef2]=sef1;

    }

    i++;

  }

  fprintf(fout, "%d\n%d\n",s,n-1);

  for(i=1;i<=m;i++)

    if(v[i].corect==1)

      fprintf(fout, "%d %d\n",v[i].st,v[i].dr);

  fclose( fin );

  fclose( fout );

  return 0;

}

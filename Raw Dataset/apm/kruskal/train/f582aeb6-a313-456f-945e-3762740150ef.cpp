#include <stdio.h>
#include <algorithm>


using namespace std;







struct edge {

  int from;

  int to;

  int cost;

};



struct rasp{

  int from;

  int to;

};



struct edge v[200000 +1];

int sef[200000 +1];

struct rasp raspuns[200000 +1];



int find(int x){

  if(sef[x]==x){

    return x;

  }

  sef[x]=find(sef[x]);

  return sef[x];

}



void unite(int x,int y){

  sef[find(x)]=find(y);

}



bool comp(edge a,edge b){

  return(a.cost<b.cost);

}



int main()

{

  FILE *fin,*fout;

  fin=fopen("apm.in","r");

  fout=fopen("apm.out","w");



  int n,m,x,y,c,i,cost,muchii,j;

  fscanf(fin,"%d%d",&n,&m);

  for(i=0;i<m;i++){

    fscanf(fin,"%d%d%d",&x,&y,&c);

    v[i].from=x;

    v[i].to=y;

    v[i].cost=c;

  }

  for(i=0;i<n;i++){

    sef[i]=i;

  }

  std::sort(v,v+m,comp);

  cost=0;

  j=0;

  muchii=0;

  for(i=0;i<m;i++){

    if(find(v[i].from)!=find(v[i].to)){

      cost+=v[i].cost;

      muchii++;

      raspuns[j].from=v[i].from;

      raspuns[j].to=v[i].to;

      j++;

      unite(v[i].from,v[i].to);

    }

  }

  fprintf(fout,"%d\n%d\n",cost,muchii);

  for(i=0;i<muchii;i++){

    fprintf(fout,"%d %d\n",raspuns[i].from,raspuns[i].to);

  }



  fclose(fin);

  fclose(fout);

  return 0;

}

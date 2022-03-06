#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int n, m, *leg[1510], numar[1510];

double *cost[1510];

double eps= 1e-10;



void djikstra()

{

  int uz[1510], nr=0, min;

  double d[1510];

  memset(uz, 0, sizeof(uz));

  numar[1]=1;

  for(int i=0; i<=n; ++i) d[i]= 20000000;

  d[1]=0;



  while(nr-n) {

    min=0;

    for(int i=1; i<=n; ++i) if( !uz[i] && d[min] - d[i] >eps ) min=i;

    uz[min]= 1;

    nr++;

     for(int i=1; i<=leg[min][0]; ++i)

      if( d[ leg[min][i]] - d[min] - cost[min][i] >eps && min!=leg[min][i] && !uz[leg[min][i]]) {

        d[ leg[min][i]]= d[min] + cost[min][i];

        numar[ leg[min][i]]= numar[min];

      }

      else if( fabs( d[ leg[min][i]] - d[min] - cost[min][i]) <eps && min!=leg[min][i]) {

        numar[ leg[min][i]]+= numar[min];

        numar[ leg[min][i]]%=104659;

      }

    numar[min]%= 104659;

  }



  freopen("dmin.out","w",stdout);

  for(int i=2; i<=n; ++i) printf("%d ",numar[i]);

  printf("\n");





}



int main()

{

  int x, y, z;

  freopen("dmin.in","r",stdin);

  scanf("%d %d",&n,&m);



  for(int i=1; i<=n; ++i) {

    leg[i]=(int*)malloc(sizeof(int)*2);

    leg[i][0]=0;

    cost[i]=(double*)malloc(sizeof(double)*2);

  }



  for(int i=1; i<=m; ++i) {

    scanf("%d %d %d",&x,&y,&z);



    leg[x][0]++;

    leg[y][0]++;

    leg[x]=(int*)realloc(leg[x], sizeof(int)*(leg[x][0]+5));

    cost[x]=(double*)realloc(cost[x], sizeof(double)*(leg[x][0]+5));

    leg[y]=(int*)realloc(leg[y], sizeof(int)*(leg[y][0]+5));

    cost[y]=(double*)realloc(cost[y], sizeof(double)*(leg[y][0]+5));



    leg[x][ leg[x][0]]= y;

    leg[y][ leg[y][0]]= x;

    cost[x][ leg[x][0]]= log2(z);

    cost[y][ leg[y][0]]= log2(z);

  }

  djikstra();



  return 0;

}

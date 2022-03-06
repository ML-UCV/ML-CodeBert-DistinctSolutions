#include <stdio.h>
#include <stdlib.h>






struct cer {

 int x;

 int y;

 int t;

};



int C[4][2][2] = {{{0,1},{1,1}}, {{1,0},{1,1}}, {{1,1},{0,1}}, {{1,1},{1,0}}};



cer v[1011];



int u[1011/10];



int n,m,ok,tot,i,aux,poz;



int main(){

 FILE *f = fopen("party.in","r");

 fscanf(f,"%d %d",&n, &m);

 for (i = 1;i<=m;i++){

  fscanf(f,"%d %d %d", &v[i].x, &v[i].y, &v[i].t);

 }

 fclose(f);
 do{

  ok = 1;

  for (i=1;i<=m;i++) {

   if (!C[v[i].t][u[v[i].x]][u[v[i].y]]) {

    ok = 0;

    if (aux = rand()%2) {

     u[v[i].x] = 1 - u[v[i].x];

    } else {

     u[v[i].y] = 1 - u[v[i].y];

    }

    break;

   }

  }

  tot = 1;

  if (ok) {

   tot = 0;

   for (i=1;i<=n;i++){

    if (u[i]){

     tot++;

    }

   }

   if (!tot){

    if (aux = rand()%2) {

     u[v[1].x] = 1;

    } else {

     u[v[1].y] = 1;

    }

    continue;

   }

  }



 } while (!ok || !tot);



 tot = 0;

 for (i=1;i<=n;i++)

  if (u[i])

   tot++;

 FILE *g = fopen("party.out","w");

 fprintf(g,"%d\n",tot);

 for (i=1;i<=n;i++)

  if (u[i])

   fprintf(g,"%d\n",i);

 fclose(g);





 return 0;

}

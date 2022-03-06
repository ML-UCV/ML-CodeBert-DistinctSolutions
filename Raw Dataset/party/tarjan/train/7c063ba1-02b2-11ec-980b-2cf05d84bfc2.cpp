#include <stdio.h>
#include <stdlib.h>
struct muchie{

 int x,y,caz;

};



int fol[1024];

muchie a[1024];

int nr,i,n,m,aux,ok;



bool corect(int i)

{

 if (a[i].caz == 0)

  return (fol[a[i].x] || fol[a[i].y]);

 if (a[i].caz == 3)

  return ((!fol[a[i].x]) || (!fol[a[i].y]));

 return (fol[a[i].x] || (!fol[a[i].y]));

}



int main()

{

 freopen("party.in","r",stdin);

 freopen("party.out","w",stdout);

 scanf("%d %d",&n,&m);

 for (i=1; i<=m; i++){

  scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].caz);

  if (a[i].caz==2) {

   aux = a[i].x;

   a[i].x = a[i].y;

   a[i].y = aux;

   a[i].caz = 1;

  }

 }

 for (i=1; i<=n; i++)

  fol[i]=1;

 for (ok=0; !ok; ){

  ok = 1;

  for (i=1; i<=m; i++)

   if (!corect(i)) {

    ok=0;

    aux = rand()%2;

    if (aux ==0)

     fol[a[i].x] ^=1;

    else

     fol[a[i].y] ^=1;

   }

 }

 for (i=1; i<=n; i++)

  nr +=fol[i];

 printf("%d\n",nr);

 for (i=1; i<=n; i++)

  if (fol[i])

   printf("%d\n",i);

 return 0;

}

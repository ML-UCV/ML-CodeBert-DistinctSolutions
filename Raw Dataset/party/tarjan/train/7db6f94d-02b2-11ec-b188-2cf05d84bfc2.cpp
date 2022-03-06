#include <stdio.h>
#include <time.h>
#include <stdlib.h>






int n, m, a[101*10][3], v[101];



int main() {

 int i, ok, ct, op;

 freopen("party.in", "r", stdin);

 freopen("party.out", "w", stdout);



 scanf("%d %d\n", &n, &m);

 for (i=1; i<=m; ++i) scanf("%d %d %d\n", &a[i][0], &a[i][1], &a[i][2]);



 srand((unsigned)time(NULL));

 for (i=1; i<=n; ++i) v[i]=rand()%2;



 ok=0;

 while (!ok) {

  ok=1;

  for (i=1; i<=m && ok; ++i)

   if (a[i][2]==0) {

    if (!v[a[i][0]] && !v[a[i][1]]) {

     op=rand()%2;

     v[a[i][op]]=1;

     ok=0;

    }

   }

   else if (a[i][2]==1) {

    if (!v[a[i][0]] && v[a[i][1]]) {

     op=rand()%2;

     if (!op) v[a[i][0]]=1;

     else v[a[i][1]]=0;

     ok=0;

    }

   }

   else if (a[i][2]==2) {

    if (v[a[i][0]] && !v[a[i][1]]) {

     op=rand()%2;

     if (!op) v[a[i][0]]=0;

     else v[a[i][1]]=1;

     ok=0;

    }

   }

   else {

    if (v[a[i][0]] && v[a[i][1]]) {

     op=rand()%2;

     v[a[i][op]]=0;

     ok=0;

    }

   }

 }



 ct=0;

 for (i=1; i<=n; ++i)

  if (v[i]) ct++;



 printf("%d\n", ct);

 for (i=1; i<=n; ++i)

  if (v[i]) printf("%d\n", i);



 return 0;

}

#include <stdio.h>
#include <stdlib.h>


struct rel {

 int a,b,z;

};



int n,m;

rel x[1000];

char v[101];



void citire() {

 FILE *fin = fopen("party.in", "rt");



 fscanf(fin, " %d %d", &n, &m);



 int i;



 for (i = 0; i < m; ++i)

  fscanf(fin, " %d %d %d", &x[i].a, &x[i].b, &x[i].z);



 fclose(fin);

}



int check() {

 int i;



 for (i = 0; i < m; ++i)

  switch(x[i].z) {

   case 0:

    if (v[x[i].a] == 0 && v[x[i].b] == 0)

     return i;

    break;

   case 1:

    if (v[x[i].a] == 0 && v[x[i].b] == 1)

     return i;

    break;

   case 2:

    if (v[x[i].a] == 1 && v[x[i].b] == 0)

     return i;

    break;

   case 3:

    if (v[x[i].a] == 1 && v[x[i].b] == 1)

     return i;

    break;

  }

 return -1;

}



void aleator() {

 int i, k=0, q=32677;



 for (i = 0; i <= n; ++i)

  v[i]=0;



 while ((i = check()) != -1) {

  k = rand() & q;



  if (k < 16384)

   v[x[i].a] = 1 - v[x[i].a];

  else

   v[x[i].b] = 1 - v[x[i].b];

 }



}



void afisare() {

 FILE *fout=fopen("party.out","wt");

 int i, nr = 0;



 for (i = 1;i <= n; ++i)

  if (v[i] == 1) ++nr;



 fprintf(fout, "%d\n", nr);



 for (i = 1; i <= n; ++i)

  if (v[i] == 1)

   fprintf(fout, "%d\n", i);



 fclose(fout);

}



int main() {



 citire();



 aleator();



 afisare();



 return 0;

}

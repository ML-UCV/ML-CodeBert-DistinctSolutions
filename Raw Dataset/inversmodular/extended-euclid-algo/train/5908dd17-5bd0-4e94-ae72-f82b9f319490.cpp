#include <stdio.h>


FILE* fin, * fout;



int a, n;



int invers(int a, int n) {

 int t = n;

 int v[2], v1[2] = { 1,0 }, v2[2] = { 0,1 };

 while (n) {

  int q, r;

  q = a / n;

  r = a % n;

  v[0] = v1[0], v[1] = v1[1];

  v1[0] = v2[0], v1[1] = v2[1];

  v2[0] = v[0] - q * v2[0], v2[1] = v[1] = q * v2[1];



  a = n;

  n = r;

 }



 int alfa = v1[0] % t;

 if (alfa < 0) alfa += t;



 return alfa;

}



int main() {

 fin = fopen("inversmodular.in", "r");

 fout = fopen("inversmodular.out", "w");



 fscanf(fin, "%i %i", &a, &n);



 fprintf(fout, "%i", invers(a, n));



 return 0;

}

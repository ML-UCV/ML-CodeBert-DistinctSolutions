#include <iostream>
#include <stdio.h>


using namespace std;



int prod;



void rid_put(int x, int put, int mod) {

  if (put == 0)

    return;

  if (put % 2 == 1)

    prod = (1ll * prod * x) % mod;

  x = (1ll * x * x) % mod;

  rid_put(x, put / 2, mod);

}



int phi(int x) {

  int d, sol;



  sol = x;

  for (d = 2; d * d <= x; d++)

    if (x % d == 0) {

      while (x % d == 0)

        x /= d;

      sol = sol / d * (d - 1);

    }



  if (x > 1)

    sol = sol / x * (x - 1);

  return sol;

}



int inv_mod(int a, int n) {

  int nr = phi(n);

  prod = 1;

  rid_put(a, nr - 1, n);

  return prod;

}



int main() {

  FILE *fin, *fout;

  int a, n, nr;



  fin = fopen("inversmodular.in", "r");

  fscanf(fin, "%d%d", &a, &n);

  fclose( fin );



  fout = fopen("inversmodular.out", "w");

  fprintf(fout, "%d", inv_mod(a, n));

  fclose( fout );

  return 0;

}

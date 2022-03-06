#include <iostream>
#include <cstdio>




using namespace std;



int n, m;

int dad[250000 + 5], log[250000 + 5];

int r[18][250000 + 5];



void gen_log() {

  int b = 1;



  log[1] = 0;

  for(int i = 2; i <= n; i++)

    if(2 * b == i) {

      log[i] = log[b] + 1;

      b *= 2;

    }

    else

      log[i] = log[b];

}



void gen_rmq() {

  for(int i = 0; i <= log[n]; i++)

    for(int j = n; j - (1 << i) >= 1; j--)

      if(i == 0)

        r[i][j] = dad[j];

      else

        r[i][j] = r[i - 1][r[i - 1][j]];

}



int stramos(int q, int p) {

  int l = log[p];



  if((1 << l) == p)

    return r[l][q];

  return stramos(r[l][q], p ^ (1 << l));

}



int main() {

  freopen("stramosi.in", "r", stdin);

  freopen("stramosi.out", "w", stdout);

  int x, q, p;



  scanf("%d %d", &n, &m);

  gen_log();

  for(int i = 1; i <= n; i++) {

    scanf("%d", &x);

    dad[i] = x;

  }

  gen_rmq();



  for(int i = 1; i <= m; i++) {

    scanf("%d %d", &q, &p);

    printf("%d\n", stramos(q, p));

  }



  return 0;

}

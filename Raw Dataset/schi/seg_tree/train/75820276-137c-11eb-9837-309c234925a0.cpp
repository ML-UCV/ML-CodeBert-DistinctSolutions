#include <iostream>
#include <cstdio>




using namespace std;



int n;

int v[30000 + 5], aint[4 * 30000 + 5], ord[30000 + 5];



void init(int nod, int st, int dr) {

  int mij = (st + dr) / 2;



  aint[nod] = dr - st + 1;

  if(dr != st) {

    init(2 * nod, st, mij);

    init(2 * nod + 1, mij + 1, dr);

  }

}



int query(int nod, int st, int dr, int qval) {

  int mij = (st + dr) / 2;



  aint[nod]--;



  if(st == dr)

    return st;



  if(qval <= aint[2 * nod])

    return query(2 * nod, st, mij, qval);

  return query(2 * nod + 1, mij + 1, dr, qval - aint[2 * nod]);

}



int main() {

  freopen("schi.in", "r", stdin);

  freopen("schi.out", "w", stdout);

  int poz;



  scanf("%d", &n);

  for(int i = 1; i <= n; i++)

    scanf("%d", &v[i]);



  init(1, 1, n);

  for(int i = n; i >= 1; i--) {

    poz = query(1, 1, n, v[i]);

    ord[poz] = i;

  }



  for(int i = 1; i <= n; i++)

    printf("%d\n", ord[i]);



  return 0;

}

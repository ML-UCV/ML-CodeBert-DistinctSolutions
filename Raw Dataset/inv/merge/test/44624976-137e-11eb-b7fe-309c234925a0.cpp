#include <bits/stdc++.h>




const int MV = 1e5 + 5 ;



int n, inv, k ;

int v[MV], L[MV >> 1], R[MV >> 1] ;



void merge(int st, int dr) {

  int mij = (dr + st) >> 1, k(st - 1), c(0) ;

  int i(1), j(1) ;

  for (i = 1 ; i <= mij - st + 1 ; ++ i) {

    L[i] = v[i + st - 1] ;

  }

  for (i = 1 ; i <= dr - mij ; ++ i) {

    R[i] = v[mij + i] ;

  }

  i = 1 ;

  while (i <= mij - st + 1 && j <= dr - mij) {

    if (L[i] <= R[j]) {

      v[++ k] = L[i ++] ;

      inv = (inv + c) % 9917 ;

    } else {

      c = j ;

      v[++ k] = R[j ++] ;

    }

  }

  while (i <= mij - st + 1) {

    v[++ k] = L[i ++] ;

    inv = (inv + c) % 9917 ;

  }

  while (j <= dr - mij) {

    v[++ k] = R[j ++] ;

  }

}



void merge_sort(int st, int dr) {

  if (st >= dr)

    return ;

  merge_sort(st, (st + dr) >> 1) ;

  merge_sort(((st + dr) >> 1) + 1, dr) ;

  merge(st, dr) ;

}



int main() {

  freopen("inv.in", "r", stdin) ;

  freopen("inv.out", "w", stdout) ;

  int i ;

  scanf("%d", &n) ;

  for (i = 1 ; i <= n ; ++ i) {

    scanf("%d", v + i) ;

  }

  merge_sort(1, n) ;

  printf("%d", inv) ;

  return 0 ; }

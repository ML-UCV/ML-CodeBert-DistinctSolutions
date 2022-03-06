#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;



int father [ 20 + 1 ] [ 250000 + 1 ] ;

int put [ 20 ] ;



inline void preput () {

  int j ;

  put[0] = 1 ;

  for (j = 1 ; j < 20 ; j++ )

    put[j] = put[j-1] * 2 ;

}



inline void precalc (int n) {

  int i, j;

  for (i = 1 ; i <= n ; i++ )

    for (j = 1 ; j < 20 ; j++ )

    father[j][i] = father[j-1][father[j-1][i]] ;

}



inline int fadar (int nod, int x ) {

  int j ;

  for (j = 0 ; put[j] <= x ; j++ ) {

    if ( ( put[j] & x ) != 0 )

      nod = father[j][nod] ;

  }

  return nod ;

}



int main() {



  ifstream fin ("stramosi.in") ;

  ofstream fout ("stramosi.out" ) ;

  std::ios::sync_with_stdio(false) ;

  int n, m, i, v, x;

  fin >> n >> m ;

  for (i = 1 ; i <= n ; i++ )

    fin >> father[0][i] ;

  preput () ;

  precalc(n) ;

  for (i = 1 ; i <= m ; i++) {

    fin >> v >> x ;

    fout << fadar(v,x) << '\n' ;

  }

  return 0;

}

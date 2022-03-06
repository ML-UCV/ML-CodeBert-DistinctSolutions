#include <iostream>
#include <stdio.h>


using namespace std;



int aib[30001];

int v[30001];

int v2[30001];



int zeros( int x ) {

  return ( x ^ ( x - 1 ) ) & x;

}



void update( int x, int poz, int n ) {

  while ( poz <= n ) {

    aib[poz] += x;

    poz += zeros( poz );

  }

}



int sum( int poz ) {

  int s = 0;

  while ( poz > 0 ) {

    s += aib[poz];

    poz -= zeros( poz );

  }

  return s;

}



int cbin( int x, int n ) {

  int poz = 0, i;

  for ( i = 1 << 15; i > 0; i /= 2 ) {

    if ( poz + i <= n && sum( poz + i ) <= x - 1 )

      poz += i;

  }

  return poz + 1;

}



int main() {

  FILE *fin = fopen( "schi.in", "r" ), *fout = fopen( "schi.out", "w" );

  int n, i;

  fscanf( fin, "%d", &n );

  for ( i = 1; i <= n; i ++ ) {

    fscanf( fin, "%d", &v[i] );

    update( 1, i, n );

  }

  for ( i = n; i > 0; i -- ) {

    v2[cbin( v[i], n )] = i;

    update( -1, cbin( v[i], n ), n );

  }

  for ( i = 1; i <= n; i ++ ) {

    fprintf( fout, "%d\n", v2[i] );

  }

  fclose( fin );

  fclose( fout );

  return 0;

}

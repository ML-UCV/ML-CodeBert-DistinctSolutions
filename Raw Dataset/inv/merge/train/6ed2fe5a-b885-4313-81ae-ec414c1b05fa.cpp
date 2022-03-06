#include <stdio.h>
#include <stdlib.h>






int v [ 100000 + 1 ] ;

int aux[ 100000 + 1 ] ;



long long merge (int v[], int st, int dr ) {

  int m , i, j, k ;

  long long r = 0 ;

  m = (st+dr) / 2 ;

  i = k = st ;

  j = m + 1 ;

  while( i <= m && j <= dr ){

    if(v[i] <= v[j]){

      aux[k++] = v[i++] ;

    }

    else{

      aux[k++] = v[j++] ;

      r += m - i + 1 ;

    }

  }

  while(i <= m){

    aux[k++] = v[i++] ;

  }

  while(j <= dr) {

    aux[k++] = v[j++] ;

  }

  for(k = st; k <= dr ; k++ ){

    v[k] = aux[k] ;

  }

  return r ;

}



long long mergesort(int v[],int st,int dr){

  if(st == dr)

    return 0 ;

  int m = ( st + dr) / 2 ;

  long long r = 0 ;

  r += mergesort (v,st,m) ;

  r += mergesort (v,m+1,dr) ;

  r += merge (v,st,dr) ;

  return r;

}



int main() {

  FILE *fin, *fout ;

  fin = fopen("inv.in","r");

  fout = fopen("inv.out","w");

  int n, i ;

  fscanf(fin, "%d", &n ) ;

  for(i = 0 ; i < n ; i++ )

    fscanf(fin, "%d", &v[i] ) ;

  fprintf (fout,"%lld ",mergesort(v, 0, n-1) % 9917 ) ;

  fclose(fin) ;

  fclose(fout) ;

  return 0;

}

#include <cstdio>



using namespace std;

int aux[100005], v[100005];

int mmerge( int st, int dr, int v[] ) {
  int i,j,k,m;
  m = ( st + dr ) / 2;
  i = k = st;
  j = m + 1;
  int nr = 0;
  while( i <= m && j <= dr ) {
    if( v[i] <= v[j] )
      aux[k++] = v[i++];
    else
      aux[k++] = v[j++], nr += ( m - i + 1 ) % 9917;
  }
  while( i <= m )
    aux[k++] = v[i++];
  while( j <= dr )
    aux[k++] = v[j++];
  for( k = st; k <= dr; k ++ )
    v[k] = aux[k];
  return nr;
}

int msort( int st, int dr, int v[] ) {
  int i, j;
  if( st == dr )
    return 0;
  int m = ( st + dr ) / 2;
  i = msort(st,m,v);
  j = msort(m+1,dr,v);
  return (i + j + mmerge(st,dr,v)) % 9917;
}

int main() {
    freopen("inv.in","r",stdin);
    freopen("inv.out","w",stdout);
    int i, n, nr;
    scanf("%d",&n);
    for( i = 1; i <= n; i ++ )
      scanf("%d",&v[i]);
    nr = msort(1,n,v) % 9917;
    printf("%d",nr);
    return 0;
}

#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin( "apm.in" );
ofstream fout( "apm.out" );

const int MaxM = 400002;
const int MaxN = 200002;

struct graph {
  int cost, x, y;
};

int M[MaxN], ind[MaxM];
graph inG[MaxM];
graph G[MaxN];
int edges[MaxM][2];

int root( int x ) {
  if ( M[x] == x ) {
 return x;
  }
  return M[x] = root( M[x] );
}
void join( int x, int y ) {
  M[root( x )] = root( y );
}

int cmp( int a, int b ) {
  return inG[a].cost < inG[b].cost;
}

int main() {
  int n, m, i, c;

  fin >> n >> m;
  for ( i = 0; i < m; ++i ) {
 fin >> inG[i].x >> inG[i].y >> inG[i].cost;
    ind[i] = i;
 M[inG[i].x] = inG[i].x;
 M[inG[i].y] = inG[i].y;
  }
  sort( ind, ind + m, cmp );
  for ( i = 0; i < m; ++i ) {
    G[i].cost = inG[ind[i]].cost;
 G[i].x = inG[ind[i]].x;
 G[i].y = inG[ind[i]].y;
  }
  c = 0;
  int k = 0;
  for ( i = 0; i < m; ++i ) {
    if ( root( G[i].x ) != root( G[i].y ) ) {
   c += G[i].cost;
   edges[k][0] = G[i].x;
   edges[k++][1] = G[i].y;
   join( G[i].x, G[i].y );
 }
  }
  fout << c << "\n" << k << "\n";
  for ( i = 0; i < k; ++i ) {
 fout << edges[i][0] << " " << edges[i][1] << "\n";
  }
  fin.close();
  fout.close();
  return 0;
}

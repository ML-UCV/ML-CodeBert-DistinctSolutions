#include <stdio.h>
#include <vector>
#include <queue>
#define MaxN 30000

using namespace std;

vector<int> adj[MaxN + 1];
vector<int> dist[MaxN + 1];
queue<int> q;
int ld[MaxN + 1];
char viz[MaxN + 1];

int BFS( int s, int d ) {
  int i, node;

  q.push( s );
  viz[s] = 1;
  while ( !q.empty() && q.front() != d ) {
	node = q.front(); 
	q.pop();
	for ( i = 0; i < adj[node].size(); ++i ) {
	  if ( !viz[adj[node][i]] ) {
		if ( adj[node][i] > node ) {
	      ld[adj[node][i]] = ld[node] + dist[node][i]; 
		} else {
		  ld[adj[node][i]] = ld[node] - dist[node][i];
		}
		viz[adj[node][i]] = 1;
		q.push( adj[node][i] );
	  }
	}
  }
  if ( q.empty() ) {
	return 0;
  }
  return ld[d];
}

int main() {
  FILE *fin = fopen( "sate.in", "r" );
  FILE *fout = fopen( "sate.out", "w" );
  int n, m, s, d, i, x, y, dt;

  fscanf( fin, "%d%d%d%d", &n, &m, &s, &d );
  for ( i = 0; i < m; ++i ) {
    fscanf( fin, "%d%d%d", &x, &y, &dt );
    adj[x].push_back( y );
	adj[y].push_back( x );
	dist[x].push_back( dt );
	dist[y].push_back( dt );
  }
  fprintf( fout, "%d", BFS( s, d ) );
  fclose( fin );
  fclose( fout );
  return 0;
}

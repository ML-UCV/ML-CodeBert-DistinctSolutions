#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin( "apm.in" );
ofstream fout( "apm.out" );

const int MaxN = 200002;

vector<int> G[MaxN];
vector<int> cost[MaxN];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
int viz[MaxN];
int arb[MaxN][2];

void solve( int stNode ) {
  int node, ne = 0, minc = 0;

  q.push( { 0, { stNode, stNode } } );
  while ( !q.empty() ) {
 if ( !viz[q.top().second.second] ) {
      node = q.top().second.second;
   minc += q.top().first;
   arb[ne][0] = node;
   arb[ne++][1] = q.top().second.first;
   viz[node] = 1;
      for ( int i = 0; i < G[node].size(); ++i ) {
        if ( !viz[G[node][i]] ) {
       q.push( { cost[node][i], { node, G[node][i] } } );
     }
   }
 } else {
   q.pop();
 }
  }
  fout << minc << "\n" << ne - 1 << "\n";
  for ( int i = 1; i < ne; ++i ) {
    fout << arb[i][0] << " " << arb[i][1] << "\n";
  }
}

int main() {
  int n, m, i, x, y, c;

  fin >> n >> m;
  for ( i = 0; i < m; ++i ) {
    fin >> x >> y >> c;
 G[x].push_back( y );
 G[y].push_back( x );
 cost[x].push_back( c );
 cost[y].push_back( c );
  }
  solve( 1 );
  fin.close();
  fout.close();
  return 0;
}

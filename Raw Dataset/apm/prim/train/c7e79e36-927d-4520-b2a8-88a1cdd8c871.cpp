#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <bitset>

using namespace std;

const int N = 2e5;
const int M = 4e5;
const int INF = 2e9;

struct struct_node {
      int node, cost;
      bool operator < ( const struct_node &other )const {
          return cost < other.cost;
      }
};

multiset <struct_node> dist;
vector<struct_node> edge[N];
bitset<N+1> used (false);
int min_cost_to[N+1];
int pairs[N+1]; pair<int, int> result[N];

void insert_apm ( int node ) {
    used[node] = true;
    for ( int i = 0; i < (int) edge[node].size (); i ++ ) {
       int pay = edge[node][i].cost;
       int adj = edge[node][i].node;

       if ( pay < min_cost_to[adj] ) {
          min_cost_to[adj] = pay;
          dist.insert ( edge[node][i] );
          pairs[adj] = node;
       }
    }
}

void init_INF () {
    for ( int i = 1; i <= N; i ++ )
       min_cost_to[i] = INF;
}

ifstream fin ( "apm.in" );
ofstream fout ( "apm.out" );


int main()

{

   int n, m; fin >> n >> m;
   for ( int i = 0; i < m; i ++ ) {
      int x, y, pay; fin >> x >> y >> pay;
      edge[x].push_back ( {y, pay} );
      edge[y].push_back ( {x, pay} );
   }

   init_INF ();

   insert_apm ( 1 ); int final_dist = 0;
   for ( int i = 1; i < n; i ++ ) {
      int get_node = dist.begin () -> node;
      while ( used[get_node] == true ) {
         dist.erase ( dist.begin () );
         get_node = dist.begin () -> node;
      }

      dist.erase ( dist.begin () );
      insert_apm ( get_node );
      final_dist += min_cost_to[get_node];
      result[i-1].first = get_node; result[i-1].second = pairs[get_node];
   }

   fout << final_dist << '\n';
   fout << n - 1 << '\n';
   for ( int i = 0; i < n - 1; i ++ ) {
      fout << result[i].first << ' ' << result[i].second;
      fout << '\n';
   }




    return 0;

}

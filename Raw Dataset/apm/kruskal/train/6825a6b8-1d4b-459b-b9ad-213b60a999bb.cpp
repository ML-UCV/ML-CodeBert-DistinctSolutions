#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

const int N = 2e5;
const int M = 4e5;
int sef[N];

struct edge {
      int from, to, cost;
      bool operator < ( const edge &other )const {
          return cost < other.cost;
      }
};
vector<edge> graf;
vector<pair<int, int>> result;
int n, m, final_cost;

int sef_suprem ( int node ) {
   if ( sef[node] == node )
     return node;
   return sef[node] = sef_suprem ( sef[node] );
}

bool cmp_sef ( int node_x, int node_y ) {
    int sef_x, sef_y;
    sef_x = sef_suprem ( node_x );
    sef_y = sef_suprem ( node_y );

    if ( sef_x == sef_y )
      return true;
    return false;
}

void union_node ( int node_x, int node_y ) {
    int sef_x, sef_y;
    sef_x = sef_suprem ( node_x );
    sef_y = sef_suprem ( node_y );

    sef[sef_y] = sef_x;
}


ifstream fin ( "apm.in" );
ofstream fout ( "apm.out" );


int main()

{

   fin >> n >> m;
   for ( int i = 0; i < m; i ++ ) {
      int x, y, pay;
      fin >> x >> y >> pay;
      graf.push_back ( {x, y, pay} );
   }
   sort ( graf.begin (), graf.end () );

   for ( int i = 1; i <= N; i ++ )
      sef[i] = i;

   int count_good = 0;
   int e = 0;
   while ( count_good < n - 1 ) {
      if ( cmp_sef ( graf[e].from, graf[e].to ) == false ) {
        result.push_back ( {graf[e].from, graf[e].to} );
        union_node ( graf[e].from, graf[e].to );
        final_cost += graf[e].cost;
        count_good ++;
      }
      e ++;
   }

   fout << final_cost << '\n';
   fout << n - 1 << '\n';
   for ( int i = 0; i < (int) result.size (); i ++ ) {
      fout << result[i].first << ' ' << result[i].second;
      fout << '\n';
   }

    return 0;

}

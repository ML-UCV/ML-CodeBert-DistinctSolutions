#include <fstream>


using namespace std;



ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



const int NMAX = 250000;

const int LOGMAX = 18;



int t[LOGMAX + 1][NMAX + 1];



int main() {

    int n, m;

    fin>>n>>m;

    for( int i = 1; i <= n; i ++ )

      fin>>t[0][i];

    for( int dim = 1; (1<<dim) <= n; dim ++ )

      for( int i = 1; i <= n; i ++ )

        t[dim][i] = t[dim - 1][t[dim - 1][i]];

    while( m -- ) {

      int node, depth;

      fin>>node>>depth;

      int pas;

      for( pas = 1; (1<<pas) <= depth; pas ++ );

      int level = 0;

      while( pas ) {

        pas --;

        if( level + (1<<pas) <= depth )

          level += (1<<(pas)), node = t[pas][node];

      }

      fout<<node<<"\n";

    }

    return 0;

}

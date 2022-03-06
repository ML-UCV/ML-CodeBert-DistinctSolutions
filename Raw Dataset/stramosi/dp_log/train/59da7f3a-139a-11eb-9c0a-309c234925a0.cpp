#include <fstream>


using namespace std;



int stramosi[20][250001];

ifstream fin("stramosi.in");

ofstream fout("stramosi.out");



int main() {

  int n, m, i, x, j,p,q;

  long long int t;

  fin >> n >> m;

  for(i = 1; i <= n; ++i)

    {

      fin >> stramosi[0][i];

    }

  for(i = 1; i <= 19; ++i)

    for(j = 1; j <= n; ++j)

      stramosi[i][j] = stramosi[i - 1][stramosi[i-1][j]];

  for(i = 1; i <= m; ++i){

    fin >> q >> p;

    for(j = 0; t = (1 << j), t<= p; ++j)

      if(t & p)

        q = stramosi[j][q];

    fout << q << '\n';

  }

  return 0;

}

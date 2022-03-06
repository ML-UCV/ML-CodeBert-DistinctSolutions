#include <fstream>


int mat[25][250001], n, m, i, j, k;



int main() {

  std::ifstream is{"stramosi.in"};



  is >> n >> m;



  for (i = 1; i <= n; ++i)

    is >> mat[0][i];



  for (k = 1; (1 << k) <= n; ++k)

    for (j = 1; j <= n; ++j)

      mat[k][j] = mat[k - 1][mat[k - 1][j]];



  std::ofstream os{"stramosi.out"};



  while (m--) {

    k=0;

    is >> i >> j;



    while (j) {

      if (j & 1)

        i = mat[k][i];



      ++k;

      j >>= 1;

    }



    os << i << '\n';

  }

}

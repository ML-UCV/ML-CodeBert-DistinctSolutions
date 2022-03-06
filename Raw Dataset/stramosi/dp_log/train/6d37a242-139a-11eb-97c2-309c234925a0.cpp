#include <fstream>


int mat[25][250001];



int main() {

  std::ifstream is{"stramosi.in"};



  int n, m;

  is >> n >> m;



  for (auto i = 1; i <= n; ++i)

    is >> mat[0][i];



  for (auto k = 1; (1 << k) <= n; ++k)

    for (auto j = 1; j <= n; ++j)

      mat[k][j] = mat[k - 1][mat[k - 1][j]];



  std::ofstream os{"stramosi.out"};



  for (auto i = 1; i <= m; ++i) {

    int q, p, exp{};

    is >> q >> p;



    while (p) {

      if (p & 1)

        q = mat[exp][q];



      ++exp;

      p >>= 1;

    }



    os << q << '\n';

  }

}

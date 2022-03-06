#include <fstream>
int g[25][250001], n, m, i, j, k;main(){

  std::ifstream o{"stramosi.in"};

  o>>n>>m;

  for(i=1;i<=n;++i)

    o>>g[0][i];

  for(k=1;(1<<k)<=n;++k)

    for(j=1;j<=n;++j)

      g[k][j]=g[k-1][g[k-1][j]];

  std::ofstream s{"stramosi.out"};

  while(m--){

    k=0;o>>i>>j;

    while(j){

      if(j&1)i=g[k][i];

      ++k;j>>=1;

    }

    s<<i<<'\n';

  }

}

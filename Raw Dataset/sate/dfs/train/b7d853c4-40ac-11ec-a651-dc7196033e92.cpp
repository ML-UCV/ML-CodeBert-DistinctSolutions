#include <fstream>
#include <vector>
#include <memory.h>

std::ifstream fin("sate.in");
std::ofstream fout("sate.out");

const int mxn = 30e3 + 5;

int n, m, start, finish;
std::vector < std::pair < int, int > > mat[mxn];
int viz[mxn];

inline void DFS(int nod){
  for (auto i : mat[nod]){
    if (!viz[i.second]){
      viz[i.second] = viz[nod] + i.first;
      DFS(i.second);
    }
  }
}

inline void solve(){
  fin >> n >> m >> start >> finish;
  for (int i = 1; i <= m; ++i){
    int x, y, d;
    fin >> x >> y >> d;
    mat[x].push_back({d, y});
    mat[y].push_back({-d, x});
  }
  viz[start] = 1;
  DFS(start);
  fout << std::max(viz[start] - viz[finish], -viz[start] + viz[finish]);
}

int main(){
  solve();
  return 0;
}

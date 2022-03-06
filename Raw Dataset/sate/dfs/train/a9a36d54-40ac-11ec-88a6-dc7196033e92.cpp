#include <fstream>
#include <vector>

using namespace std;

const int N = 30005;

vector<pair<int, int>> gr[N];
int d[N];
bool viz[N];

void dfs(int nod) {
  viz[nod] = true;
  for (auto e : gr[nod])
    if (!viz[e.first]) {
      d[e.first] = d[nod] + e.second;
      dfs(e.first);
    }
}

int main() {
  ifstream cin("sate.in");
  ofstream cout("sate.out");
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  while (m--) {
    int a, b, dist;
    cin >> a >> b >> dist;
    gr[a].emplace_back(b, dist);
    gr[b].emplace_back(a, -dist);
  }
  cin.close();
  dfs(x);
  cout << d[y] << "\n";
  cout.close();
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

const int MAXN = 30001;

vector<pair<int, int> > v[MAXN];

int answer;
bool seen[MAXN];

void dfs(int node, int sink, int current) {
  seen[node] = 1;
  if (node == sink)
      answer = current;
  for (auto elem: v[ node ]) {
    if (!seen[elem.first]) {
      current += elem.second;
      dfs(elem.first, sink, current);
      current -= elem.second;
    }
  }
}

int main()
{
  int n, m, x, y;
  fin >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    fin >> a >> b >> c;
    v[ a ].push_back({b, c});
    v[ b ].push_back({a, -c});
  }

  dfs(x, y, 0);
  fout << answer;

  return 0;
}

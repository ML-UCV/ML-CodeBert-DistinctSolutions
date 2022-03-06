#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e4;

vector <pair <int, int>> g[MAXN + 1];
queue <int> q;
int d[MAXN + 1];

int main()
{
    int n, m, x, y;
    ifstream fin("sate.in");
    fin >> n >> m >> x >> y;
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      fin >> a >> b >> c;
      g[a].push_back({b, c});
      g[b].push_back({a, -c});
    }
    fin.close();
    for (int i = 1; i <= n; ++i)
      d[i] = -1;
    d[x] = 0;
    q.push(x);
    while (q.empty() == 0) {
      int node = q.front();
      q.pop();
      for (auto it : g[node])
        if (d[it.first] == -1) {
          d[it.first] = d[node] + it.second;
          q.push(it.first);
        }
    }
    ofstream fout("sate.out");
    fout << d[y];
    fout.close();
    return 0;
}

#include <bits/stdc++.h>


using namespace std;



const int MAXN = 2e2;



vector <int> g[MAXN + 1], gt[MAXN + 1], srt;

int seen[MAXN + 1], val[MAXN + 1], n;



int non(int node) {

  if (node > n)

    return node - n;

  return node + n;

}



void dfs(int node) {

  seen[node] = 1;

  for (auto it : g[node])

    if (seen[it] == 0)

      dfs(it);

  srt.push_back(node);

}



void rev_dfs(int node) {

  seen[node] = 0;

  val[non(node)] = 1;

  for (auto it : gt[node])

    if (seen[it])

      rev_dfs(it);

}



inline void add_edg(int x, int y) {

  g[x].push_back(y);

  gt[y].push_back(x);

}



int main()

{

    int m, x, y, z, nr;

    ifstream fin("party.in");

    fin >> n >> m;

    for (int i = 0; i < m; ++i) {

      fin >> x >> y >> z;

      switch (z) {

        case 0:

          add_edg(non(x), y);

          add_edg(non(y), x);

          break;

        case 1:

          add_edg(non(x), non(y));

          add_edg(y, x);

          break;

        case 2:

          add_edg(x, y);

          add_edg(non(y), non(x));

          break;

        case 3:

          add_edg(x, non(y));

          add_edg(y, non(x));

          break;

      }

    }

    fin.close();

    for (int i = 1; i <= 2 * n; ++i)

      if (seen[i] == 0)

        dfs(i);

    for (int i = 2 * n - 1; i >= 0; --i)

      if (seen[srt[i]] && seen[non(srt[i])])

        rev_dfs(srt[i]);

    nr = 0;

    for (int i = 1; i <= n; ++i)

      nr += val[i];

    ofstream fout("party.out");

    fout << nr << '\n';

    for (int i = 1; i <= n; ++i)

      if (val[i])

        fout << i << '\n';

    fout.close();

    return 0;

}

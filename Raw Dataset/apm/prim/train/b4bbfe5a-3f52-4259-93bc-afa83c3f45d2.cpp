#include <bits/stdc++.h>


using namespace std;



ifstream fin ("apm.in");

ofstream fout ("apm.out");



typedef pair < int, int > Pair;

int N, M, ans;

vector < Pair > G[200002];

list < Pair > sol;



void Read () {

  fin >> N >> M;

  while (M --) {

    int u, v, wt;

    fin >> u >> v >> wt;

    G[u].push_back ({v, wt});

    G[v].push_back ({u, wt});

  }

}



void Prim () {

  priority_queue < Pair, vector < Pair > , greater < Pair > > Heap;

  vector < int > key (N + 2, INT_MAX),

                 parent (N + 2);

  vector < bool > viz (N + 2, 0);

  Heap.push ({0, 1});

  key[1] = 0;

  while (!Heap.empty()) {

    int u = Heap.top().second;

    Heap.pop();

    viz[u] = true;

    for (auto it : G[u]) {

      int v = it.first, weight = it.second;

      if (viz[v] == false && key[v] > weight) {

        key[v] = weight;

        Heap.push ({key[v], v});

        parent[v] = u;

      }

    }

  }

  for (int i = 2; i <= N; i ++) {

    sol.push_back ({parent[i], i});

    ans += key[i];

  }

}



void Solve () {

  Read();

  Prim();

  fout << ans << '\n' << N - 1 << '\n';

  for (auto it : sol)

    fout << it.first << ' ' << it.second << '\n';

}



int main() {

  Solve();

  return 0;

}

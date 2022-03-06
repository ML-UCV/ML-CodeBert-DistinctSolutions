#include <iostream>
#include <fstream>
#include <vector>
#include <queue>




using namespace std;



const int NMAX = 200005;

const int INF = 1e9;



int n, m;

vector<pair<int,int> > graph[NMAX];



int main() {



  ifstream fin("apm.in");

  ofstream fout("apm.out");



  fin >> n >> m;

  int x, y, w;

  for (int i = 0; i < m; i++) {

      fin >> x >> y >> w;

      graph[x].emplace_back(y, w);

      graph[y].emplace_back(x, w);

  }





  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<>> pq;

  int s = 1;

  vector<int> dist(n + 1, INF);

  vector<int> parent(n + 1, 0);

  vector<bool> viz(n, false);



  pq.push(make_pair(0, s));

  dist[s] = 0;



  int cost = 0;



  pair<int,int> pair;

  while (!pq.empty()) {

      pair = pq.top();

      pq.pop();

      x = pair.second;



      if (viz[x]) {

          continue;

      }



      cost += pair.first;

      viz[x] = true;



      for (auto & i : graph[x]) {

          y = i.first;

          w = i.second;



          if (!viz[y] && w < dist[y]) {

              dist[y] = w;

              pq.push(make_pair(dist[y], y));

              parent[y] = x;

          }

      }

  }



  fout << cost << "\n" << n - 1 << "\n";

  for (int i = 1; i <= n; i++) {

      if (i != s)

          fout << parent[i] << " " << i << "\n";

  }



  fin.close();

  fout.close();

  return 0;

}

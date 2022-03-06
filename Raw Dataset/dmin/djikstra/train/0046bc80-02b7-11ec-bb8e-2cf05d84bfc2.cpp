#include <bits/stdc++.h>




using namespace std;



const int INF = 1e9;

const int mod = 104659;

const double eps = 1e-6;



ifstream fin ("dmin.in");

ofstream fout ("dmin.out");

priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > >pq;

int n, m, nr[1502];

double dist[1502];

vector<pair<double, int> >G[1502];



void dijkstra () {

  for (int i = 1; i <= n; i++)

    dist[i] = 1.0 * INF;

  dist[1] = 0;

  pq.push({0.0, 1});

  nr[1] = 1;

  while (!pq.empty()) {

    int x = pq.top().second;

    double c = pq.top().first;

    pq.pop();

    if (dist[x] != c)

      continue;

    for (auto it : G[x]) {

      long long y = it.second;

      double cost = it.first;

      if (dist[y] - (dist[x] + cost) > eps) {

        dist[y] = dist[x] + cost;

        pq.push({dist[y], y});

        nr[y] = nr[x];

      }

      else if (abs(dist[y] - (dist[x] + cost)) <= eps)

        nr[y] = (nr[y] + nr[x]) % mod;

    }

  }

}



int main()

{

  fin >> n >> m;

  for (int i = 1; i <= m; i++) {

    int x, y, z;

    fin >> x >> y >> z;

    G[x].push_back({log2((double)z), y});

    G[y].push_back({log2((double)z), x});

  }

  dijkstra();

  for (int i = 2; i <= n; i++)

    fout << nr[i] << " ";

  return 0;

}

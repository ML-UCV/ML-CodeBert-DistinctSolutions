#include <cmath>
#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;



double EPSILON = 0.000001;

const int Inf = 1e9 + 1;

int n, m;

vector<pair<double, int>> a[1501];

double d[1501];

int nrways[1501];

const int MOD = 104659;



void read() {

 int x, y, i;

 double c;

 ifstream f("dmin.in");

 f >> n >> m;

 for (i = 1; i <= m; i++) {

  f >> x >> y >> c;

  a[x].emplace_back(log2(c), y);

  a[y].emplace_back(log2(c), x);

 }

 f.close();

}



priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;

void dijkstra(int x) {

 pair<double, int> p, cur;

 int i;

 d[x] = 0;

 nrways[1] = 1;

 Q.push(make_pair(0, x));

 while (!Q.empty()) {

  p = Q.top();

  Q.pop();

  if (p.first != d[p.second]) continue;

  for (i = 0; i < a[p.second].size(); i++) {

   cur = a[p.second][i];

   if(d[p.second] + cur.first - d[cur.second] < -EPSILON) {

    d[cur.second] = d[p.second] + cur.first;

    Q.push(make_pair(d[cur.second], cur.second));

    nrways[cur.second] = nrways[p.second];

   }

   else if(abs(d[p.second] + cur.first - d[cur.second]) < EPSILON)

                nrways[cur.second] = (nrways[cur.second] + nrways[p.second]) % MOD;

  }

 }

}



void solve() {

 int i;

 for (i = 1; i <= n; i++)

  d[i] = Inf;

 dijkstra(1);

}



void output() {

 ofstream g("dmin.out");

 int i, j;

 for (i = 2; i <= n; i++)

  g << nrways[i] << ' ';

 g.close();

}



int main() {

 read();

 solve();

 output();

 return 0;

}

#include <cassert>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 1505;
const double EPS = 1e-10;
const double INF = 1e10;
const int MOD = 104659;

ifstream fin("dmin.in");
ofstream fout("dmin.out");

typedef pair<double, int> pdi;


int N, M;
vector<pair<int, double>> graph[MAX_N];
double cost[MAX_N];
int dmin[MAX_N];
bool vis[MAX_N];

void dijkstra(int source);

int main() {
  fin >> N >> M;
  for (int i = 1, a, b, c; i <= M; i += 1) {
    fin >> a >> b >> c;
    double cc = log(double(c));
    graph[a].push_back(make_pair(b, cc));
    graph[b].push_back(make_pair(a, cc));
  }

  dijkstra(1);
  for (int i = 2; i <= N; i += 1) {
    fout << dmin[i] << ' ';
  }
  fout << endl;
  return 0;
}

void dijkstra(int source) {
  priority_queue<pdi, vector<pdi>, greater<pdi>> heap;
  heap.push(make_pair(0.0, source));

  for (int i = 1; i <= N; i += 1) {
    cost[i] = INF;
  }
  cost[source] = 0;
  dmin[source] = 1;

  while (!heap.empty()) {
    int node = heap.top().second;
    heap.pop();

    if (vis[node]) continue;
    vis[node] = true;

    for (auto p: graph[node]) {
      double c = cost[node] + p.second;
      if (abs(c - cost[p.first]) < EPS) {
        dmin[p.first] += dmin[node];
        if (dmin[p.first] >= MOD) {
          dmin[p.first] -= MOD;
        }
      } else if (c < cost[p.first]) {
        cost[p.first] = c;
        dmin[p.first] = dmin[node];
        heap.push(make_pair(c, p.first));
      }
    }
  }
}

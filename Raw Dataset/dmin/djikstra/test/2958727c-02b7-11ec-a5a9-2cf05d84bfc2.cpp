#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, double> pid;



int N, M;
vector<pid> G[1501];

double dist[1501];
int cnt[1501];
bool gata[1501];

void dijkstra() {
 for (int i(1); i <= N; ++i)
  dist[i] = 1e100;

 dist[1] = 0;
 cnt[1] = 1;

 for (int z(0); z < N; ++z) {
  int u = -1;
  for (int i(1); i <= N; ++i)
   if (!gata[i])
    if ((u == -1) || (dist[i] < dist[u]))
     u = i;

  for (vector<pid>::iterator v = G[u].begin(); v != G[u].end(); ++v)
   if (abs(dist[u] - dist[v->first] - v->second) < 1e-8)
    cnt[u] = (cnt[u] + cnt[v->first]) % 104659;


  for (vector<pid>::iterator v = G[u].begin(); v != G[u].end(); ++v)
   if ((dist[u] + v->second) / dist[v->first] < 1e-8)
    dist[v->first] = dist[u] + v->second;

  gata[u] = true;
 }
}

int main(int argc, char *argv[]) {
 FILE *fi = fopen("dmin.in", "r");
 fscanf(fi, "%d %d", &N, &M);
 int u, v, w;
 for (int i(0); i < M; ++i) {
  fscanf(fi, "%d %d %d", &u, &v, &w);
  G[u].push_back(make_pair(v, log(w)));
  G[v].push_back(make_pair(u, log(w)));
 }
 fclose(fi);

 dijkstra();

 FILE *fo = fopen("dmin.out", "w");
 for (int i(2); i <= N; ++i)
  fprintf(fo, "%d ", cnt[i]);
 fprintf(fo, "\n");
 fclose(fo);

 return 0;
}

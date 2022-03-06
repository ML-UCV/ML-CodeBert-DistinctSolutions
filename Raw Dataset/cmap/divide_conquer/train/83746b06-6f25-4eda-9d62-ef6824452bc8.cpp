#include <cstdio>
#include <cmath>

typedef double f64;
const int MAX_N = 100000;
struct Punct {
  f64 x, y;
  Punct() { x = y = 0; }
  Punct(int _x, int _y):x(_x), y(_y) {}
} v[MAX_N], aux[MAX_N];

f64 dist(Punct a, Punct b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


void interclasare(int st, int mid, int dr) {
  int i = st, n = mid, j = mid, m = dr;
  int k = 0;
  while(i < n || j < m) {
    if(i < n && j < m && v[i].x < v[j].x)
      aux[k++] = v[i++];
    else if(i < n && j < m)
      aux[k++] = v[j++];
    else if(i < n)
      aux[k++] = v[i++];
    else
      aux[k++] = v[j++];
  }
  for(i = st; i < dr; ++i)
    v[i] = aux[i - st];
}

f64 INF = 1e10;

f64 min(f64 a, f64 b) {
  if(a < b) return a;
  return b;
}

f64 cmap(int st, int dr) {
  int mid = (st + dr) / 2;
  f64 best;
  if(dr - st == 1)
    return INF;
  else if(dr - st == 2) {
    interclasare(st, st + 1, dr);
    return dist(v[st], v[st + 1]);
  }
  best = min(cmap(st, mid), cmap(mid, dr));
  interclasare(st, mid, dr);
  for(int i = st; i < dr; ++i)
    for(int j = i + 1; j < i + 6; ++j)
      best = min(best, dist(v[i], v[j]));
  return best;
}

int main() {
  int n;
  FILE *fin = fopen("cmap.in", "r");
  fscanf(fin, "%d", &n);
  for(int i = 0; i < n; ++i)
    fscanf(fin, "%lf%lf", &v[i].x, &v[i].y);
  fclose(fin);
  FILE *fout = fopen("cmap.out", "w");
  fprintf(fout, "%f", cmap(0, n));
  fclose(fout);
  return 0;
}

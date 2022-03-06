#include <iostream>

using namespace std;

int n, m, x, y, k;
int tata[25][250005];

const int Lim = 10000000;
int u = Lim - 1;
char s[Lim];

void Next () {
 if (++u == Lim)
  fread(s, 1, Lim, stdin), u = 0;
}

void Get (int &_x) {
 for (; s[u] < '0' || s[u] > '9'; Next());
 for (_x = 0; s[u] >= '0' && s[u] <= '9'; Next())
  _x = _x * 10 + s[u] - '0';
}

int main() {
 freopen("stramosi.in", "r", stdin);
 freopen("stramosi.out", "w", stdout);

  Get(n);
  Get(m);
  for (int i = 1; i <= n; ++i)
  Get(tata[1][i]);
 bool gata = false;
 for (int i = 1; !gata; ++i) {
  gata = true;
  for (int j = 1; j <= n; ++j) {
   tata[i + 1][j] = tata[i][tata[i][j]];
   if (tata[i + 1][j])
    gata = false;
  }
 }
 while (m--) {
    Get(x);
    Get(y);
    for (int i = 0; i <= 19; ++i)
   if (y & (1 << i))
    x = tata[i + 1][x];
    cout << x << '\n';
 }
 return 0;
}

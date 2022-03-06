#include <cstdio>
#include <string>
#include <deque>



using namespace std;

char a[50001], b[50001];
int H[50001];
int n;
deque<int> ax[256];

int x[50001], nx;
int u1[256], u2[256];

void read() {
  int i;
  freopen("swap.in","r",stdin);
  fgets(a, 50001, stdin);
  n = 0;
  while (a[n] >= 'a' && a[n] <= 'z')
    ++n;

  fgets(b, 50001, stdin);

  for (i = 0;i < n;++i)
    ax[ (int)a[i] ].push_back(i + 1);

  for (i = 0;i < n;++i) {
      x[++nx] = ax[ b[i] ][0];
      ax[b[i]].pop_front();
    }
}

inline void update(int x, int v) {
  for (int i = x; i <= n; i += (i & -i))
    H[i] += v;
}

inline int query(int x) {
  int s = 0;
  for (int i = x; i ; i -= (i & -i))
    s += H[i];
  return s;
}

void solve() {
  int i, j;
  for (i = 1;i <= n;++i)
    update(i, 1);
  int nr = 0;
  for (i = 1;i <= n;++i) {
      update(x[i], -1);
      nr += query(x[i]);
  }

  printf("%d\n", nr);
}

int main() {
  freopen("swap.out","w",stdout);
  read();
  int i;
  for (i = 0;i < n;++i)
    ++u1[ a[i] ],
    ++u2[ b[i] ];

  for (i = 0;i <= 255;++i)
    if (u1[i] != u2[i]){
        printf("-1\n");
        return 0;
    }

  solve();
  return 0;
}

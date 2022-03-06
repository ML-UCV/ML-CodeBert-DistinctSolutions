#include <bits/stdc++.h>


using namespace std;



const int MAXN = 2000005;

const int MAXA = 1000;



char a[MAXN], b[MAXN];

int pi[MAXN];

int pos[MAXA + 5];



int main() {

  freopen("strmatch.in", "r", stdin);

  freopen("strmatch.out", "w", stdout);



  scanf("%s", a + 1);

  scanf("%s", b + 1);

  int n = strlen(a + 1);

  int m = strlen(b + 1);

  int x = 0;

  for (int i = 2; i <= n; ++i) {

    while (x && a[x + 1] != a[i])

      x = pi[x];

    if (a[x + 1] == a[i])

      x++;

    pi[i] = x;

  }



  int k = 0;

  x = 0;

  for (int i = 1; i <= m; ++i) {

    while (x && b[i] != a[x + 1])

      x = pi[x];

    if (b[i] == a[x + 1])

      x++;

    if (x == n) {

      k++;

      if (k <= MAXA)

        pos[k] = i - n;

    }

  }



  printf("%d\n", k);

  for (int i = 1; i <= min(k, MAXA); ++i)

    printf("%d ", pos[i]);



  return 0;

}

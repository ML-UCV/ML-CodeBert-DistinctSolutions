#include <bits/stdc++.h>


using namespace std;







const int MAXN = 1e5;



char s[MAXN + 1], t[MAXN + 1];

vector <int> poz[100];

int code (char c) {

  return c - 'a';

}

int nr;

int p[4 * MAXN + 1], v[4 * MAXN + 1];

void build (int st, int dr, int nod) {

  if (st == dr) {

    p[++nr] = nod;

    return;

  }

  int mij = (st + dr) / 2;

  build (st, mij, nod * 2);

  build (mij + 1, dr, nod * 2 + 1);

}



int take (int nod, int sum) {

  if (nod == 1)

    return sum;

  if (nod % 2 == 0)

    v[nod + 1]++;

  return take (nod / 2, sum + v[nod]);

}



int main() {

  int n, i, x;

  long long swaps;

  freopen ("swap.in", "r", stdin);

  freopen ("swap.out", "w", stdout);

  scanf ("%s", &s);

  n = strlen (s);

  for (i = n - 1; i >= 0; i--)

    poz[code (s[i])].push_back (i);

  build (1, n, 1);

  scanf ("%s", &t);

  swaps = 0;

  for (i = 0; i < n; i++) {

    if (poz[code(t[i])].size () == 0) {

      printf ("-1\n");

      return 0;

    }

    x = poz[code(t[i])].back () + 1;

    swaps += x - take (p[x], 0);

    poz[code (t[i])].pop_back ();

  }

  printf ("%lld\n", swaps - n);

  return 0;

}

#include <cstdio>
#include <vector>


const int MAXN = 5e4;





std::vector <int> pos[26];

int f1[26], f2[26], last[26],

    aib[MAXN + 1], p[MAXN + 1];

char s1[MAXN], s2[MAXN];



void update(int x, int val, int n) {

  while (x <= n) {

    aib[x] += val;

    x += x & -x;

  }

}



int sum(int x) {

  int s = 0;

  while (x > 0) {

    s += aib[x];

    x -= x & -x;

  }

  return s;

}



int main() {

  int n, imp, ans;

  char ch;

  FILE *f = fopen("swap.in", "r");

  n = 0;

  ch = fgetc(f);

  while (ch != '\n') {

    ch -= 'a';

    s1[n++] = ch;

    ++f1[ch];

    ch = fgetc(f);

  }

  n = 0;

  ch = fgetc(f);

  while (ch != '\n') {

    ch -= 'a';

    s2[n++] = ch;

    pos[ch].push_back(n);

    ++f2[ch];

    ch = fgetc(f);

  }

  fclose(f);

  imp = 0;

  while (imp < 26 && f1[imp] == f2[imp]) {

    ++imp;

  }

  f = fopen("swap.out", "w");

  if (imp != 26) {

    fprintf(f, "-1\n");

  } else {

    for (int i = 0; i < n; ++i) {

      p[i] = pos[s1[i]][last[s1[i]]++];

    }

    ans = 0;

    for (int i = n - 1; i >= 0; --i) {

      ans += sum(p[i]);

      update(p[i], 1, n);

    }

    fprintf(f, "%d\n", ans);

  }

  fclose(f);

  return 0;

}

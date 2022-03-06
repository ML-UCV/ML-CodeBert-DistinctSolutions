#include <bits/stdc++.h>

const int LMAX = 2000005;

char p[LMAX], t[LMAX];
int lenp, lent;
int lps[LMAX];

void read() {
 scanf("%s %s", p, t);

 lenp = strlen(p);
 lent = strlen(t);
}

void build_lps() {
 int j = 0;

 for (int i = 1; i < lenp; ++i) {
  while (j > 0 && p[i] != p[j])
   j = lps[j - 1];

  if (p[i] == p[j])
   ++j;

  lps[i] = j;
 }
}

void kmp() {
 std::vector<int> matches;

 int j = 0;

 for (int i = 0; i < lent; ++i) {
  while (j > 0 && t[i] != p[j])
   j = lps[j - 1];

  if (t[i] == p[j])
   ++j;

  if (j == lenp)
   matches.push_back(i - j + 1);
 }

 printf("%ld\n", matches.size());
 int k = std::min(1000ul, matches.size());
 for (int i = 0; i < k; ++i)
  printf("%d ", matches[i]);
}

int main() {
 freopen("strmatch.in", "r", stdin);
 freopen("strmatch.out", "w", stdout);

 read();
 build_lps();
 kmp();
}

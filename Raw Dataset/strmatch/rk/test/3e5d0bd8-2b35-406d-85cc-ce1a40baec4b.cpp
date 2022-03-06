#include <bits/stdc++.h>

const int LMAX = 2000005;
const int a = 31;

char p[LMAX], t[LMAX];
int lenp, lent;

void read() {
 scanf("%s %s", p, t);

 lenp = strlen(p);
 lent = strlen(t);
}

struct RollingHash {
 int a, n;
 int maxpw{1}, value{0};

 void init(char *s, int len) {
  for (int i = 0; i < len; i++) {
   value = (value * a + s[i]) % n;

   if (i) maxpw = (maxpw * a) % n;
  }
 }

 void roll(char out, char in) {
  value = ((value - (out * maxpw) % n + n) * a + in) % n;
 }

 bool operator==(const RollingHash& other) const {
  return value == other.value;
 }
};

void rabin_karp() {
 std::vector<int> matches;

 int n1 = 100003, n2 = 100109;

 RollingHash hp[]{{a, n1}, {a, n2}};
 RollingHash ht[]{{a, n1}, {a, n2}};

 for (int i = 0; i < 2; i++) {
  hp[i].init(p, lenp);
  ht[i].init(t, lenp);
 }

 if (lenp > lent) {
  printf("0\n");
  return;
 }

 if (hp[0] == ht[0] && hp[1] == ht[1])
  matches.push_back(0);

 for (int i = lenp; i < lent; i++) {
  ht[0].roll(t[i - lenp], t[i]);
  ht[1].roll(t[i - lenp], t[i]);

  if (hp[0] == ht[0] && hp[1] == ht[1])
   matches.push_back(i - lenp + 1);
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
 rabin_karp();
}

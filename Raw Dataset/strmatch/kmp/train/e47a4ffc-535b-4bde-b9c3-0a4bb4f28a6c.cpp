#include <cstdio>
#include <cstring>
#include <vector>

const int LMAX = 2000005;

char p[LMAX], t[LMAX];
int pl, tl;
int pref[LMAX];

void build_pref() {
 int m = 0, i = 1;

 while (i < pl) {
  if (p[i] == p[m]) {
   m += 1;
   pref[i] = m;
   i += 1;
  } else if (m != 0) {
   m = pref[m - 1];
  } else {
   pref[i] = 0;
   i += 1;
  }
 }
}

void kmp() {
 std::vector<int> matches;

 int i = 0, j = 0;

 while (j < tl) {
  if (p[i] != t[j]) {
   if (i == 0)
    j++;
   else
    i = pref[i - 1];
  } else {
   i++;
   j++;

   if (i == pl) {
    matches.push_back(j - i);
    i = pref[i - 1];
   }
  }
 }

 printf("%ld\n", matches.size());
 for (int i = 0; i < 1000 && i < matches.size(); i++)
  printf("%d ", matches[i]);
}

int main() {
 freopen("strmatch.in", "r", stdin);
 freopen("strmatch.out", "w", stdout);

 scanf("%s %s", p, t);

 pl = strlen(p);
 tl = strlen(t);

 build_pref();
 kmp();
}

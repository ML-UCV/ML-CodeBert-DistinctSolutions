#include <bits/stdc++.h>

const int LMAX = 2000005;

std::string p, t;
int pref[LMAX];

void build_pref() {
 for (int i = 1, m = 0; i < p.size(); ++i) {
  if (p[i] == p[m])
   pref[i] = ++m;
  else if (m != 0)
   m = pref[m - 1], --i;
  else
   pref[i] = 0;
 }
}

void kmp() {
 std::vector<int> matches;

 for (int i = 0, j = 0; j < t.size();) {
  if (p[i] != t[j]) {
   if (i == 0)
    ++j;
   else
    i = pref[i - 1];
  } else {
   ++i, ++j;

   if (i == p.size()) {
    matches.push_back(j - i);
    i = pref[i - 1];
   }
  }

 }

 std::cout << matches.size() << '\n';
 int k = std::min(1000ul, matches.size());
 for (int i = 0; i < k; ++i)
  std::cout << matches[i] << ' ';
}

int main() {
 freopen("strmatch.in", "r", stdin);
 freopen("strmatch.out", "w", stdout);

 std::cin >> p >> t;

 build_pref();
 kmp();
}

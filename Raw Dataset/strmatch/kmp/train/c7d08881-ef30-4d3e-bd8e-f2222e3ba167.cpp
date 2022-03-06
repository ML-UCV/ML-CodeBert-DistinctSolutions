#include <bits/stdc++.h>


const int MAX_N = 2000005;

const unsigned int MAX_ANS = 1000;



int n, m;



int lps[MAX_N];

char p[MAX_N], t[MAX_N];



std::vector <int> ans;



int main() {

  int curr;

  freopen("strmatch.in", "r", stdin);

  freopen("strmatch.out", "w", stdout);

  std::cin >> (p + 1) >> (t + 1);

  n = strlen(p + 1);

  m = strlen(t + 1);

  t[0] = p[0] = '\0';

  lps[0] = lps[1] = 0;

  for (int i = 2; i <= n; ++i) {

    curr = lps[i - 1];

    while (curr > 0 && p[curr + 1] != p[i]) {

      curr = lps[curr];

    }

    if (p[i] == p[curr + 1]) {

      lps[i] = curr + 1;

    } else {

      lps[i] = 0;

    }

  }

  curr = 0;

  for (int i = 1; i <= m; ++i) {

    while (curr > 0 && p[curr + 1] != t[i]) {

      curr = lps[curr];

    }

    if (p[curr + 1] == t[i]) {

      ++curr;

    } else {

      curr = 0;

    }

    if (curr == n) {

      ans.push_back(i - curr + 1);

    }

  }

  std::cout << ans.size() << "\n";

  for (int i = 0; i < ans.size(); ++i) {

    std::cout << ans[i] - 1 << " ";

    if (i >= 999) {

      return 0;

    }

  }

  return 0;

}

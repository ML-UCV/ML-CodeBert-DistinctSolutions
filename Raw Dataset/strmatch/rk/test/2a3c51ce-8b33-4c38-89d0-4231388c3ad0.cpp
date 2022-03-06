#include <bits/stdc++.h>


const int MAX_N = 2000005;

const int P = 57;

const int MOD1 = 1000000009;

const int MOD2 = 1000000007;



int n, m;



std::vector <int> ans;



char p[MAX_N], t[MAX_N];



long long a1, a2, b1, b2, p1, p2;



int main() {

  freopen("strmatch.in", "r", stdin);

  freopen("strmatch.out", "w", stdout);

  scanf("%s\n%s", p + 1, t + 1);

  t[0] = p[0] = '\0';

  n = strlen(p + 1);

  m = strlen(t + 1);

  p1 = p2 = 1;

  for (int i = 1; i <= n; ++i) {

    a1 = (1LL * a1 * P + p[i]) % MOD1;

    a2 = (1LL * a2 * P + p[i]) % MOD2;

    if (i != 1) {

      p1 = (1LL * p1 * P) % MOD1;

      p2 = (1LL * p2 * P) % MOD2;

    }

  }

  for (int i = 1; i <= n; ++i) {

    b1 = (1LL * b1 * P + t[i]) % MOD1;

    b2 = (1LL * b2 * P + t[i]) % MOD2;

  }

  if (a1 == b1 && a2 == b2) {

    ans.push_back(0);

  }

  for (int i = n + 1; i <= m; ++i) {

    b1 = ((1LL * b1 - (p1 * t[i - n]) % MOD1 + MOD1) % MOD1 * P + t[i]) % MOD1;

    b2 = ((1LL * b2 - (p2 * t[i - n]) % MOD2 + MOD2) % MOD2 * P + t[i]) % MOD2;

    if (a1 == b1 && a2 == b2) {

      ans.push_back(i - n);

    }

  }

  std::cout << ans.size() << "\n";

  for (int i = 0; i < ans.size() && i < 1000; ++i) {

    std::cout << ans[i] << " ";

  }

  return 0;

}

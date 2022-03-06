#include <bits/stdc++.h>


using namespace std;



vector<int> kmp(string s, string pat) {

  int m = (int) pat.size();

  int n = (int) s.size();

  vector<int> ps(m, 0);

  int j = 0;

  for (int i = 1; i < m; i++) {

    while (j && pat[i] != pat[j]) {

      j = ps[j - 1];

    }

    if (pat[i] == pat[j]) {

      j++;

    }

    ps[i] = j;

  }

  j = 0;

  vector<int> ret;

  for (int i = 0; i < n; i++) {

    while (j && s[i] != pat[j]) {

      j = ps[j - 1];

    }

    if (pat[j] == s[i]) {

      j++;

    }

    if (j == m) {

      j = ps[m - 1];

      ret.push_back(i - m + 1);

    }

  }

  return ret;

}



int main() {

  freopen ("strmatch.in", "r", stdin);

  freopen ("strmatch.out", "w", stdout);

  string pat, s;

  cin >> pat >> s;

  auto ret = kmp(s, pat);

  cout << (int) ret.size() << "\n";

  while ((int) ret.size() > 1000) {

    ret.pop_back();

  }

  for (auto &i : ret) {

    cout << i << " ";

  }

  cout << "\n";

}

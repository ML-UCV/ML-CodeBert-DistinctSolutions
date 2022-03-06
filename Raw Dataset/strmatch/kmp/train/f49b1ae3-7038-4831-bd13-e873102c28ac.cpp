#include <bits/stdc++.h>



using namespace std;

const int NMAX = (int)2e6;

int pi[NMAX], ans[1000];

int main() {
  ifstream cin("strmatch.in");
  ofstream cout("strmatch.out");

  string pattern, text;
  getline(cin, pattern);
  getline(cin, text);

  pi[0] = 0;
  int n = pattern.size();
  for (int i = 1; i < n; ++i) {
    int k = pi[i - 1];
    while (k > 0 && pattern[k] != pattern[i])
      k = pi[k - 1];
    if (pattern[k] == pattern[i])
      ++k;
    pi[i] = k;
  }

  int m = text.size();
  int k = 0, res = 0;
  for (int i = 0; i < m; ++i) {
    while (k > 0 && pattern[k] != text[i])
      k = pi[k - 1];
    if (pattern[k] == text[i])
      ++k;
    if (k == n) {
      if (res < 1000) ans[res] = i - n + 1;
      ++res;
      k = pi[k - 1];
    }
  }

  cout << res << endl;
  for (int i = 0; i < min(1000, res); ++i)
    cout << ans[i] << ' ';
  cout << endl;
}

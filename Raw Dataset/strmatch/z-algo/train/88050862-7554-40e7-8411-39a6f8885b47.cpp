#include <bits/stdc++.h>





using namespace std;

vector<int> GetZ(string s) {
  int n = s.length();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    z[i] = min(r - i + 1, z[i - l]);
    if (z[i] < 0)
      z[i] = 0;
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

int main() {
  ifstream cin("strmatch.in");
  ofstream cout("strmatch.out");

  string patt, text;
  getline(cin, patt);
  getline(cin, text);
  string s = patt + "#" + text;
  auto z = GetZ(s);
  vector<int> ans;
  int res = 0;
  for (int i = patt.size() + 1; i < (int)s.size(); ++i) {
    if (z[i] == (int)patt.size()) {
      if ((int)ans.size() < 1000)
        ans.emplace_back(i - patt.size() - 1);
      ++res;
    }
  }
  cout << res << '\n';
  for (int x : ans) cout << x << ' ';
  cout << endl;
}

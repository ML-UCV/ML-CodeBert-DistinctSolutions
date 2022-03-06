#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;



const int N = (int) 2e6 + 7;

string pat, s;

int m, n;

int ps[N];



int main() {

  freopen ("strmatch.in", "r", stdin);

  freopen ("strmatch.out", "w", stdout);



  cin >> pat >> s;

  m = (int) pat.size();

  n = (int) s.size();

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

      ret.push_back(i);

    }

  }

  cout << (int) ret.size() << "\n";

  while ((int) ret.size() > 1000) {

    ret.pop_back();

  }

  for (auto &i : ret) {

    cout << i - m + 1 << " ";

  }

  cout << "\n";

}

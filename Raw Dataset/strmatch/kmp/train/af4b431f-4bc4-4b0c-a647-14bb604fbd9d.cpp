#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;



const int N = 2000000 + 7;

string pat, s;

int m, n, l[N];



int main() {

  freopen ("strmatch.in", "r", stdin);

  freopen ("strmatch.out", "w", stdout);



  cin >> pat >> s;

  m = (int) pat.size();

  n = (int) s.size();

  l[0] = 0;

  int p = 0;

  for (int i = 1; i < m; i++) {

    while (p && pat[i] != pat[p]) {

      p = l[p - 1];

    }

    if (pat[i] == pat[p]) {

      p++;

    }

    l[i] = p;

  }

  p = 0;

  vector<int> sol;

  for (int i = 0; i < n; i++) {

    while (p && s[i] != pat[p]) {

      p = l[p - 1];

    }

    if (s[i] == pat[p]) {

      p++;

    }

    if (p == m) {

      sol.push_back(i - m + 1);

      p = l[p - 1];

    }

  }

  cout << (int) sol.size() << "\n";

  if ((int) sol.size() > 1000) {

    sol.resize(1000);

  }

  for (auto &i : sol) {

    cout << i << " ";

  }

  cout << "\n";

}

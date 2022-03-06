#include <cstdio>
#include <iostream>
#include <vector>


using namespace std;



string s;

string t;

int n;

int m;

vector<int> bk;



void build_automat() {

  bk.resize(m, 0);

  int j = 0;

  for (int i = 1; i < m; i++) {

    while (j && t[i] != t[j]) {

      j = bk[j - 1];

    }

    if (t[i] == t[j]) {

      j++;

      bk[i] = j;

    }

  }

}



vector<int> find_matches() {

  vector<int> sol;

  int j = 0;

  for (int i = 0; i < n; i++) {

    while (j && s[i] != t[j]) {

      j = bk[j - 1];

    }

    if (s[i] == t[j]) {

      j++;

    }

    if (j == m) {

      sol.push_back(i - m + 1);

      j = bk[j - 1];

    }

  }

  return sol;

}



int main() {

  freopen ("strmatch.in", "r", stdin);

  freopen ("strmatch.out", "w", stdout);

  cin >> t >> s;

  n = (int) s.size();

  m = (int) t.size();

  build_automat();

  vector<int> s = find_matches();

  cout << (int) s.size() << "\n";

  if ((int) s.size() > 1000) {

    s.resize(1000);

  }

  for (auto &i : s) {

    cout << i << " ";

  }

  cout << "\n";

  return 0;

}

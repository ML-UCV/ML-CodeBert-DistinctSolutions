#include <bits/stdc++.h>


using namespace std;



ifstream fin("strmatch.in");

ofstream fout("strmatch.out");



const int MAX_N = 2e6 + 5;



int n, m;



char a[MAX_N], b[MAX_N];



int kmp[MAX_N];



vector <int> ans;



int main() {

  int k;

  fin >> (a + 1) >> (b + 1);

  n = strlen(a + 1);

  m = strlen(b + 1);

  a[0] = b[0] = '\0';

  kmp[0] = kmp[1] = 0;

  for (int i = 2; i <= n; ++i) {

    k = kmp[i - 1];

    while (k > 0 && a[k + 1] != a[i]) {

      k = kmp[k];

    }

    if (a[i] == a[1 + k]) {

      kmp[i] = 1 + k;

    } else {

      kmp[i] = 0;

    }

  }

  k = 0;

  for (int i = 1; i <= m; ++i) {

    while (k > 0 && b[i] != a[1 + k]) {

      k = kmp[k];

    }

    if (b[i] == a[1 + k]) {

      ++k;

    } else {

      k = 0;

    }

    if (k == n) {

      ans.push_back(i - n);

    }

  }

  fout << ans.size() << "\n";

  for (int i = 0; i < ans.size() && i < 1000; ++i) {

    fout << ans[i] << " ";

  }

  return 0;

}

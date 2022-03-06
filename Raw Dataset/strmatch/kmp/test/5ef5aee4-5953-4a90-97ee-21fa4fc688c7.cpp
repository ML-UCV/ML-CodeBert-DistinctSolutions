#include <bits/stdc++.h>


using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



string a, b;

int lps[4000002];





int main()

{

  fin >> a >> b;

  int m = a.size();

  a = a + '#' + b;

  int n = a.size();

  int i = 1, l = 0;

  while (i < n) {

    if (a[i] == a[l]) {

      l++;

      lps[i] = l;

      i++;

    }

    else {

      if (l > 0)

        l = lps[l - 1];

      else {

        l = 0;

        i++;

      }

    }

  }

  vector<int>ans;

  for (int i = 2 * m; i < n; i++)

    if (lps[i] == m)

      ans.push_back(i);

  fout << ans.size() << "\n";

  for (int i = 0; i < min((int)ans.size(), 1000); i++)

    fout << ans[i] - 2 * m << " ";

  return 0;

}

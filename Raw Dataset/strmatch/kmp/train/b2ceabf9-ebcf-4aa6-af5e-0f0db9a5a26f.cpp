#include <bits/stdc++.h>
using namespace std;



ifstream fin ("strmatch.in");

ofstream fout ("strmatch.out");



string pat, txt;

int n, m;

int lps[2000000 +5];

vector<int> ans;



int main () {

  fin >> pat >> txt;

  m = (int)(pat).size(); n = (int)(txt).size();

  int i, j, z, len = 0;

  lps[0] = 0; i = 1;

  while (i < m) {

    if (pat[i] == pat[len]) lps[i++] = ++len;

    else if (len > 0) len = lps[len-1];

    else lps[i++] = 0;

  }

  i = j = 0;

  while (i < n) {

    if (txt[i] == pat[j]) i++, j++;

    if (j == m) {

      ans.push_back(i-m);

      j = lps[m-1];

    } else if (i < n && pat[j] != txt[i]) {

      if (j > 0) j = lps[j-1];

      else i++;

    }

  }

  fout << (int)(ans).size() << '\n';

  for (i = 0; i < min(1000, (int)(ans).size()); i++) fout << ans[i] << ' ';

  fin.close(); fout.close();

  return 0;

}

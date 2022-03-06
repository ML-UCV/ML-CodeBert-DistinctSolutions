#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

ifstream fin ("swap.in");
ofstream fout ("swap.out");

int sp[2][50001][26], n, x, ans;
queue <int> urm[26];
string s1, s2;

int main() {
  fin >> s1 >> s2;
  int n = s1.size();
  if (n != s2.size()) {
    fout << -1;
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    ++sp[0][i][s1[i - 1] - 'a'];
    ++sp[1][i][s2[i - 1] - 'a'];
    urm[s1[i - 1] - 'a'].push(i);
    for (int j = 0; j < 26; ++j) {
      sp[0][i][j] += sp[0][i - 1][j];
      sp[1][i][j] += sp[1][i - 1][j];
    }
  }
  for (int j = 0; j < 26; ++j) {
    if (sp[0][n][j] != sp[1][n][j]) {
      fout << -1;
      return 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    x = urm[s2[i - 1] - 'a'].front();
    urm[s2[i - 1] - 'a'].pop();
    for (int j = 0; j < 26; ++j) {
      ans += max(0, sp[0][x][j] - sp[1][i][j]);
    }
  }
  fout << ans;
  return 0;
}

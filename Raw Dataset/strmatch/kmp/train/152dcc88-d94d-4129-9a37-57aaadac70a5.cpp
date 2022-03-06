#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
string pattern, text;

int main() {
 freopen("strmatch.in", "r", stdin);
 freopen("strmatch.out", "w", stdout);

 cin.tie(NULL);
 ios_base::sync_with_stdio(false);

 cin >> pattern >> text;
 int N = pattern.size();
 string newString = pattern + "#" + text;
 int M = (int) newString.size();

 vector<int> pi(N, 0);
 vector<int> sol;
 sol.reserve(1000);
 int totalSolutions = 0, len = 0;
 for (int idx = 1; idx < M; idx++) {
  while (len > 0 && newString[idx] != newString[len]) {
   len = pi[len - 1];
  }
  if (newString[len] == newString[idx]) {
   len++;
  }

  if (idx < N) {
   pi[idx] = len;
  }
  if (len == N) {
   totalSolutions++;
   if (totalSolutions <= 1000) {
    sol.push_back(idx - 2 * N);
   }
  }
 }

 cout << totalSolutions << "\n";
 for (auto idx : sol) {
  cout << idx << " ";
 }
 cout << "\n";
 return 0;
}

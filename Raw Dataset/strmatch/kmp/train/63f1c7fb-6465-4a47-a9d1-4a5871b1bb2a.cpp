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
 int N = pattern.size(), M = text.size();

 vector<int> pi(N, 0);
 for (int idx = 1; idx < N; idx++) {
  int len = pi[idx - 1];
  while (len > 0 && pattern[idx] != pattern[len]) {
   len = pi[len - 1];
  }
  if (pattern[len] == pattern[idx]) {
   len++;
  }
  pi[idx] = len;
 }

 vector<int> sol;
 sol.reserve(1000);
 int totalSolutions = 0, len = 0;
 for (int idx = 0; idx < M; idx++) {
  while (len > 0 && text[idx] != pattern[len]) {
   len = pi[len - 1];
  }
  if (text[idx] == pattern[len]) {
   len++;
  }
  if (len == N) {
   totalSolutions++;
   if (totalSolutions <= 1000) {
    sol.push_back(idx - N + 1);
   }
   len = pi[len - 1];
  }
 }

 cout << totalSolutions << "\n";
 for (auto idx : sol) {
  cout << idx << " ";
 }
 cout << "\n";
 return 0;
}

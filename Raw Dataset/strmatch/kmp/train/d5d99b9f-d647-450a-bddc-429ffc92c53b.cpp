#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream f("strmatch.in");
ofstream g("strmatch.out");

int pi[2000001];
int noMatches = 0;
int matchBeginnings[2000001];

void buildAutomaton(string s) {
  int matchingLength = 0;
  pi[0] = 0;
  for (int i = 1; i < s.length(); i++) {
    while (matchingLength > 0 and s[matchingLength] != s[i]) {
      matchingLength = pi[matchingLength - 1];
    }
    if (s[matchingLength] == s[i]) {
      matchingLength++;
    }
    pi[i] = matchingLength;
  }
}

void findMatches(string a, string b) {
  int aPrefixLength = 0;
  for (int i = 0; i < b.length(); i++) {
    while (aPrefixLength > 0 && a[aPrefixLength] != b[i]) {
      aPrefixLength = pi[aPrefixLength - 1];
    }
    if (a[aPrefixLength] == b[i]) {
      aPrefixLength++;
    }
    if (aPrefixLength == a.length()) {
      matchBeginnings[noMatches] = i - a.length() + 1;
      noMatches++;
    }
  }
}

void printMatches() {
  g << noMatches << endl;
  for (int i = 0; i < min(noMatches, 1000); i++) {
    g << matchBeginnings[i] << " ";
  }
  g << endl;
}

int main() {
  string a, b;
  f >> a >> b;
  buildAutomaton(a);
  findMatches(a, b);
  printMatches();
  return 0;
}

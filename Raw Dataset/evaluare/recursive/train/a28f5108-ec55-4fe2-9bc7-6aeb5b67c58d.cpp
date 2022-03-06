#include <fstream>


std::string s;

int curr;



int solve();



int factor() {

 int ans = 0;

 if (s[curr] == '(') {

  curr++, ans += solve(), curr++;

  return ans;

 }

 while (curr < s.size() and isdigit(s[curr])) ans = ans * 10 + (int)(s[curr++] - '0');

 return ans;

}



int termen() {

 int ans = factor();

 while (curr < s.size()) {

  if (s[curr] == '*') curr++, ans *= factor();

  else if (s[curr] == '/') curr++, ans /= factor();

  else break;

 }

 return ans;

}



int solve() {

 int ans = termen();

 while (curr < s.size()) {

  if (s[curr] == '+') curr++, ans += termen();

  else if (s[curr] == '-') curr++, ans -= termen();

  else break;

 }

 return ans;

}



int main() {

 std::ifstream fin("evaluare.in");

 std::ofstream fout("evaluare.out");

 fin >> s;

 fout<<solve();

}

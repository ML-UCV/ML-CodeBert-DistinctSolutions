#include <fstream>
#include <string>
using namespace std;



ifstream cin("evaluare.in"); ofstream cout("evaluare.out");



string s;

int i;



int termen();

int factor();

int expresie();



int termen() {

 int ans = factor();

 while (s[i] == '+' || s[i] == '-') {

  if (s[i] == '+') {

   i++;

   ans += factor();

  }

  else {

   i++;

   ans -= factor();

  }

 }

 return ans;

}



int factor() {

 int ans = expresie();

 while (s[i] == '*' || s[i] == '/') {

  if (s[i] == '*') {

   i++;

   ans *= expresie();

  }

  else {

   i++;

   ans /= expresie();

  }

 }

 return ans;

}



int expresie() {

 int ans = 0;

 if (s[i] == '(') {

  i++;

  ans = termen();

  i++;

 }

 else {

  while (i < s.size() && '0' <= s[i] && s[i] <= '9') {

   ans *= 10;

   ans += s[i] - '0';

   i++;

  }

 }

 return ans;

}



int main() {

 cin >> s;

 cout << termen();

 return 0;

}

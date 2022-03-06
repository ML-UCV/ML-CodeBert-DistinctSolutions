#include <bits/stdc++.h>

using namespace std;

int i = 0;
string s;

int f1();
int f2();
int f3();

int f1() {
 int ans = f2();
 while(s[i] == '+' || s[i] == '-') {
  if(s[i] == '+') {
   ++i;
   ans += f2();
  } else {
   ++i;
   ans -= f2();
  }
 }
 return ans;
}

int f2() {
 int ans = f3();
 while(s[i] == '*' || s[i] == '/') {
  if(s[i] == '*') {
   ++i;
   ans *= f3();
  } else {
   ++i;
   ans /= f3();
  }
 }

 return ans;
}

int f3() {
 int ans = 0;
 if(s[i] == '(') {
  ++i;
  ans = f1();
  ++i;
 } else {
  while(isdigit(s[i])) {
   ans = (ans<<1) + (ans<<3) + s[i] - '0';
   ++i;
  }
 }

 return ans;
}

int main() {



  freopen("evaluare.in", "r", stdin);
  freopen("evaluare.out", "w", stdout);


 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);

 cin >> s;
 cout << f1() << '\n';
 return 0;
}

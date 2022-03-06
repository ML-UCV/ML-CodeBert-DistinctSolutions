#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_map>
#include <random>
#include <time.h>
#include <assert.h>
#include <fstream>
using namespace std;







ifstream cin("evaluare.in"); ofstream cout("evaluare.out");







string s;

int i;



int f1();

int f2();

int f3();



int f1() {

 int ans = f2();

 while (s[i] == '+' || s[i] == '-') {

  if (s[i] == '+') {

   i++;

   ans += f2();

  }

  else {

   i++;

   ans -= f2();

  }

 }

 return ans;

}



int f2() {

 int ans = f3();

 while (s[i] == '*' || s[i] == '/') {

  if (s[i] == '*') {

   i++;

   ans *= f3();

  }

  else {

   i++;

   ans /= f3();

  }

 }

 return ans;

}



int f3() {

 int ans = 0;

 if (s[i] == '(') {

  i++;

  ans = f1();

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

 cout << f1() << '\n';



 return 0;

}

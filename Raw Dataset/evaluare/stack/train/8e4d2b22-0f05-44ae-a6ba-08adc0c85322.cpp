#include <algorithm>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
#include <set>



using namespace std;

ifstream cin("evaluare.in");
ofstream cout("evaluare.out");



typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

vector < int > val(256);

void getPol (string &pol) {

  string s;
  getline(cin, s);

  stack < char > stk;

  int ind = 0;
  while (ind < (int)(s).size()) {

    bool digit = false;
    while (ind < (int)(s).size() and isdigit(s[ind])) {
      pol += s[ind ++];
      digit = true;
    }

    if (digit) pol += ' ';

    if (ind == (int)(s).size()) break;

    if (s[ind] == '(') {
      stk.push(s[ind ++]);
      continue;
    }

    if (s[ind] == ')') {
      while (not stk.empty() and stk.top() != '(') {
        pol += stk.top();
        stk.pop();
      }
      stk.pop();
      ++ ind;
      continue;
    }

    while (not stk.empty() and val[stk.top()] >= val[s[ind]]) {
      if (stk.top() == '(') break;
      pol += stk.top();
      stk.pop();
    }
    stk.push(s[ind ++]);
  }

  while (not stk.empty()) {
    pol += stk.top();
    stk.pop();
  }
}

int main() {






  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  val['('] = 20;
  val[')'] = 20;
  val['*'] = 6;
  val['/'] = 6;
  val['+'] = 3;
  val['-'] = 3;

  string pol;
  getPol(pol);

  int ind = 0;
  stack < int > stk;

  while (ind < (int)(pol).size()) {

    int nr = 0;
    while (ind < (int)(pol).size() and isdigit(pol[ind])) {
      nr = (nr << 1) + (nr << 3) + pol[ind ++] - '0';
    }

    stk.push(nr);

    while (ind < (int)(pol).size() and not isdigit(pol[ind])) {

      if (pol[ind] == ' ') {
        ++ ind;
        continue;
      }

      int b = stk.top();
      stk.pop();
      int a = stk.top();
      stk.pop();

      if (pol[ind] == '+') {
        stk.push(a + b);
      }
      else if (pol[ind] == '-') {
        stk.push(a - b);
      }
      else if (pol[ind] == '/') {
        stk.push(a / b);
      }
      else if (pol[ind] == '*') {
        stk.push(a * b);
      }

      ++ ind;
    }
  }

  cout << stk.top() << '\n';
}

#include <bits/stdc++.h>
using namespace std;



typedef pair <int, int> pii;

typedef vector <int> vi;

typedef long long ll;

typedef unsigned long long ull;



template <class T> void uin (T &a, T b) {a = min (a, b);}

template <class T> void uax (T &a, T b) {a = max (a, b);}



ifstream f ("evaluare.in");

ofstream g ("evaluare.out");



const int NMAX = 1e5 + 5;



int n, pos;

char s[NMAX];



int eval();



int getInt() {

  int ret = 0;

  while (isdigit (s[pos])) {

    (ret *= 10) += s[pos++] - '0';

  }



  return ret;

}



int factor() {

  int ret = 0;

  if (s[pos] == '(') {

    ++pos;

    ret = eval();

    ++pos;

  } else {

    ret = getInt();

  }



  return ret;

}



int term() {

  int ret = factor();

  while (s[pos] == '*' || s[pos] == '/') {

    if (s[pos++] == '*') {

      ret *= factor();

    } else {

      ret /= factor();

    }

  }



  return ret;

}



int eval() {

  int ret = 0, sign;

  ret = term();

  while (s[pos] == '+' || s[pos] == '-') {

    if (s[pos++] == '+') sign = 1;

    else sign = -1;



    ret += sign * term();

  }



  return ret;

}



int main() {

  ios::sync_with_stdio(0);

  cin.tie(0);
  f.getline (s + 1, NMAX);

  n = strlen (s + 1);



  pos = 1;

  g << eval() << '\n';



  f.close();

  g.close();
  return 0;

}

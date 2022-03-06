#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



const int MAX_N = 1e5 + 5;



char s[MAX_N];



int p;



int term();

int fact();

int expres();



int fact() {

  int sign, value;

  value = 0;

  sign = 1;

  if (s[p] == '-') {

    ++p;

    sign = - 1;

  }

  if (s[p] == '(') {

    ++p;

    value = expres();

    ++p;

  } else {

    while (isdigit(s[p]) > 0) {

      value = value * 10 + s[p] - '0';

      ++p;

    }

  }

  return value * sign;

}



int term() {

  int value;

  value = fact();

  while (s[p] == '*' || s[p] == '/') {

    if (s[p] == '*') {

      ++p;

      value *= fact();

    } else if (s[p] == '/') {

      ++p;

      value /= fact();

    }

  }

  return value;

}



int expres() {

  int value;

  value = term();

  while (s[p] == '+' || s[p] == '-') {

    if (s[p] == '+') {

      ++p;

      value += term();

    } else if (s[p] == '-') {

      ++p;

      value -= term();

    }

  }

  return value;

}



int main() {

  fin >> s;

  fout << expres();

  return 0;

}

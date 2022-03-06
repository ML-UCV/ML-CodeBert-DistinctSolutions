#include <fstream>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");



string s;

int p;



int eval ();



int factor () {

  int r = 0;

  if (s[p] == '(') {

    p++;

    r = eval ();

    p++;

  }

  else

    while ('0' <= s[p] and s[p] <= '9') {

      r = r * 10 + s[p] - '0';

      p++;

    }

  return r;

}



int termen () {

  int r = factor ();

  while (s[p] == '*' or s[p] == '/') {

    if (s[p] == '*') {

      p++; r *= factor ();

    }

    else {

      p++; r /= factor ();

    }

  }

  return r;

}



int eval () {

  int r = termen ();

  while (s[p] == '+' or s[p] == '-') {

    if (s[p] == '+') {

      p++; r += termen ();

    }

    else {

      p++; r -= termen ();

    }

  }

  return r;

}



int main ()

{

  fin >> s;

  fout << eval ();

  return 0;

}

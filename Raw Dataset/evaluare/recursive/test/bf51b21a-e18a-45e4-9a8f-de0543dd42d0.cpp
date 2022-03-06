#include <bits/stdc++.h>
using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");



char last;

int paranteza();

int inmultire();

int adunare();



int getint () {

  int ans = 0;

  while (isdigit(last)) {

    ans = (ans * 10 + last - '0');

    fin.get(last);

  }

  return ans;

}



int paranteza () {

  int ans;

  if (last == '(') {

    fin.get(last);

    ans = adunare();

    fin.get(last);

  } else ans = getint();

  return ans;

}



int inmultire () {

  int ans = paranteza();

  while (last == '*' || last == '/') {

    if (last == '*') {

      fin.get(last);

      ans *= paranteza();

    }

    else {

      fin.get(last);

      ans /= paranteza();

    }

  }

  return ans;

}



int adunare () {

  int ans = inmultire();

  while (last == '+' || last == '-') {

    if (last == '+') {

      fin.get(last);

      ans += inmultire();

    } else {

      fin.get(last);

      ans -= inmultire();

    }

  }

  return ans;

}



int main () {

  fin.get(last);

  fout << adunare();

  fin.close(); fout.close();

  return 0;

}

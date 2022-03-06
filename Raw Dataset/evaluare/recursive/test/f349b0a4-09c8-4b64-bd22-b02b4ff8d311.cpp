#include <iostream>
#include <cstdio>


using namespace std;



const int N = 100001;

int p;

char s[N];



int e();

int t();

int f();



int e() {

  int x = t();

  bool ok;

  while (s[p] == '+' || s[p] == '-') {

    ok = (s[p] == '+');

    p++;

    if (ok)

      x += t();

    else

      x -= t();

  }

  return x;

}



int t() {

  int x = f();

  bool ok;

  while (s[p] == '*' || s[p] == '/') {

    ok = (s[p] == '*');

    p++;

    if (ok)

      x *= f();

    else

      x /= f();

  }

  return x;

}



int f() {

  int sgn = 1;

  while (s[p] == '-') {

    p++;

    sgn *= -1;

  }

  if (s[p] == '(') {

    p++;

    int x = e();

    p++;

    return x * sgn;

  }

  int x = 0;

  while ('0' <= s[p] && s[p] <= '9') {

    x = 10 * x + s[p] - '0';

    p++;

  }

  return x * sgn;

}



int main() {

  freopen ("evaluare.in","r",stdin);

  freopen ("evaluare.out","w",stdout);



  scanf("%s", &s);

  printf("%d\n", e());





  return 0;

}

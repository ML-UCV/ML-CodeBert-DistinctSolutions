#include <bits/stdc++.h>




using namespace std;



char s[100000], *p = s;



int eval();



int factor( ) {

  int nr = 0;

  if( *p == '(' ) {

    p ++;

    nr = eval();

    p ++;

    return nr;

  }

  else {

    while( *p >= '0' && *p <= '9' ) {

      nr = nr * 10 + (*p - '0');

      p ++;

    }

    return nr;

  }

}



int termen( ) {

  int r = factor();

  while( *p == '*' || *p == '/' ) {

    if( *p == '*' )

      p ++, r = r * factor();

    else

      p ++, r = r / factor();

  }

  return r;

}



int eval( ) {

  int r = termen();

  while( *p == '+' || *p == '-' ) {

    if( *p == '+' )

      p ++, r += termen();

    else

      p ++, r -= termen();

  }

  return r;

}



int main() {

    ifstream fin("evaluare.in");

    ofstream fout("evaluare.out");

    fin>>s;

    fout<<eval();

    return 0;

}

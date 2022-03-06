#include <bits/stdc++.h>


using namespace std;



const long MAX = 100005;

char S[MAX], *p = S;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



long termen();

long factor();



long eval() {

 long r = termen();

 while ( *p == '+' || *p == '-' ) {

  switch ( *p ) {

   case '+':

    ++p;

    r += termen();

    break;

   case '-':

    ++p;

    r -= termen();

    break;

  }

 }

 return r;

}



long termen() {

 long r = factor();

 while ( *p == '*' || *p == '/' ) {

  switch ( *p ) {

   case '*' :

    ++p;

    r *= factor();

    break;

   case '/':

    ++p;

    r /= factor();

    break;

  }

 }

 return r;

}



long factor() {

    long r = 0;

    if ( *p == '(' ) {

        ++p;

  r = eval();

  ++p;

    } else {

        while ( *p>='0' && *p<='9' ) {

            r = r*10 + *p - '0';

   ++p;

  }

    }

    return r;

}



int main() {

    f.getline(S, MAX);

    g << eval();

    f.close();

    g.close();

    return 0;

}

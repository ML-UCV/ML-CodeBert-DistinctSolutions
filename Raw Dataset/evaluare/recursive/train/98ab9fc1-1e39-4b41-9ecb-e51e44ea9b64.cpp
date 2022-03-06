#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



char s[100010], *p=s;

ll expr();

ll subexpr();

ll eval() {

 ll r = expr();

 while ( *p=='+' || *p=='-' ) {

  switch ( *p ) {

   case '+':

    ++p;

    r += expr();

    break;

   case '-':

    ++p;

    r -= expr();

    break;

  }

 }

 return r;

}



ll expr(){

    ll r = subexpr();

 while ( *p=='*' || *p=='/' ) {

  switch ( *p ) {

   case '*' :

    ++p;

    r *= subexpr();

    break;

   case '/':

    ++p;

    r /= subexpr();

    break;

  }

 }

 return r;



}

ll subexpr(){

    ll r = 0;

    if ( *p == '(' ) {

        ++p;

  r = eval();

  ++p;

    }

    else {

        while ( *p>='0' && *p<='9' ) {

            r = r*10 + *p - '0';

   ++p;

  }

    }

    return r;

}

int main(){

    freopen("evaluare.in", "r", stdin);

    freopen("evaluare.out", "w", stdout);

    fgets(s, 100010, stdin);

    printf("%lld", eval());

    return 0;

}

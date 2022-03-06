#include <fstream>
#include <string.h>
using namespace std;

ifstream f("evaluare.in"); ofstream g("evaluare.out");

int MAX;

char S[100010], *p=S;

int termen();

int factor();

int eval()

{ int r = termen();

 while ( *p=='+' || *p=='-' )

  switch ( *p )

   {case '+' : ++p;

      r += termen(); break;

    case '-' : ++p;

      r -= termen(); break;

   }

 return r;

}

int termen()

{ int r = factor();

 while ( *p=='*' || *p=='/' )

  switch ( *p )

   {case '*' : ++p; r *= factor(); break;

    case '/' : ++p; r /= factor(); break;

   }

 return r;

}

int factor()

{ int r=0;

    if (*p =='(') {

      ++p;

      r = eval();

      ++p;

     }

   else {

      while ( *p>='0' && *p<='9' ) {r = r*10 + *p - '0'; ++p;}

        }

    return r;

}

int main()

{f>>S; MAX=strlen(S); g<<eval()<<'\n'; g.close(); return 0;}

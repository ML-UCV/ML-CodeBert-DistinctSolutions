#include <iostream>
#include <fstream>
using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char s[100001];

int i=0;



int expr();

int termen();

int factor();



int main()

{

    f>>s;

    g<<expr();

    return 0;

}



int expr()

{ int r=termen();

  while (s[i]=='+' || s[i]=='-')

    if (s[i]=='+') i++, r+=termen();

    else i++, r-=termen();

  return r;

}



int termen()

{ int r=factor();

  while (s[i]=='*' || s[i]=='/')

    if (s[i]=='*') i++, r*=factor();

    else i++, r/=factor();

  return r;

}



int factor()

{ int r=0;

  if (s[i]=='(') i++, r=expr(), i++;

  else while (s[i]>='0' && s[i]<='9') r=r*10+s[i]-'0', i++;

  return r;

}

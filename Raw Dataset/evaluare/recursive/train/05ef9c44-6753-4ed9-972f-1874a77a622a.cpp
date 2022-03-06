#include <fstream>
#include <cstring>


using namespace std;



const int NMAX = 100005;

int n, p;

char s[NMAX];

int expr(), termen(), factor();



int expr()

{

 int x = termen();

 while (p <= n && (s[p] == '+' || s[p] == '-'))

 {

  ++p;

  if (s[p - 1] == '+')

   x += termen();

  else

   x -= termen();

 }

 return x;

}



int termen()

{

 int x = factor();

 while (p <= n && (s[p] == '*' || s[p] == '/'))

 {

  ++p;

  if (s[p - 1] == '*')

   x *= factor();

  else

   x /= factor();

 }

 return x;

}



int factor()

{

 int x = 0;

 if (s[p] == '(')

 {

  ++p;

  x = expr();

  ++p;

 }

 else

 {

  while (p <= n && ('0' <= s[p] && s[p] <= '9'))

   x = x * 10 + (s[p++] - '0');

 }

 return x;

}



int main()

{

 ifstream fin("evaluare.in");

 ofstream fout("evaluare.out");

 fin >> (s + 1);

 n = strlen(s + 1);

 p = 1;

 fout << expr() << "\n";

 fin.close();

 fout.close();

 return 0;

}

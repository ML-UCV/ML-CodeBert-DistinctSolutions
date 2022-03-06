#include<fstream>
#include<ctype.h>
#include<string.h>
using namespace std;

char expr[100005];

long lg,i;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



long evaluare_expresie();

long evaluare_factor()

{

 long f=0;

 if (expr[i] == '(')

 {

  i++;

  f = evaluare_expresie();

  i++;

 }

 else

  while (i < lg && !strchr("+-*/()", expr[i]))

  {

   f = f * 10 + (expr[i] - '0');

   i++;

  }

 return f;

}



long evaluare_termen()

{

 long T = evaluare_factor();

 while (i < lg && strchr("*/", expr[i]))

 {

  char semn = expr[i];

  i++;

  if (semn == '*')

   T *= evaluare_factor();

  else

   T /= evaluare_factor();

 }

 return T;



}



long evaluare_expresie()

{

 long E = evaluare_termen();

 while (i < lg && strchr("+-", expr[i]))

 {

  char semn = expr[i];

  i++;

  if (semn == '+')

   E += evaluare_termen();

  else

   E -= evaluare_termen();





 }

 return E;

}



int main()

{

 f.getline(expr, 100005);

 lg = strlen(expr);

 g << evaluare_expresie();

 return 0;

}

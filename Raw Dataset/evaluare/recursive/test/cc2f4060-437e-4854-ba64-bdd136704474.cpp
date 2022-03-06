#include <iostream>	
#include <fstream>	




using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int evaluate(char* &expr);

int termen(char* &expr) ;

int factor(char* &expr) ;

int number(char* &expr) ;



char s[100001];



int main()

{

 char *expr;



 fin >> s;

 expr = s;

 fout << evaluate(expr);

 return 0;

}



int evaluate(char* &expr)

{

 auto result = termen(expr);



 while (expr[0] == '+' || expr[0] == '-')

 {

  switch (expr[0])

  {

  case '+':

   result += termen(++expr);

   break;

  case '-':

   result -= termen(++expr);

   break;

  default:

   break;

  }

 }



 return result;

}



int termen(char* &expr)

{

 auto result = factor(expr);



 while (expr[0] == '*' || expr[0] == '/')

 {

  switch (expr[0])

  {

  case '*':

   result *= factor(++expr);

   break;

  case '/':

   result /= factor(++expr);

   break;

  default:

   break;

  }

 }



 return result;

}



int factor(char* &expr)

{

 if (expr[0] == '(')

 {

  auto result = evaluate(++expr);

  expr++;

  return result;

 }

 else

 {

  return number(expr);

 }

}



int number(char* &expr)

{

 int nr = 0;



 while (isdigit(expr[0]))

 {

  nr = nr * 10 + (expr[0] - '0');

  expr++;

 }



 return nr;

}

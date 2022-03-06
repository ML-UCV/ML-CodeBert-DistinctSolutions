#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

int evaluate(char* &expr);
int operand(char* &expr);
int value(char* &expr);
int ADD_SUBSTRACT(char*& expr);
int MULTIPLY_DIVIDE(char* &expr);

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
 return ADD_SUBSTRACT(expr);
}

int ADD_SUBSTRACT(char*& expr)
{
 auto result = MULTIPLY_DIVIDE(expr);

 while (expr[0] == '+' || expr[0] == '-')
 {
  switch (expr[0])
  {
  case '+':
   result += MULTIPLY_DIVIDE(++expr);
   break;
  case '-':
   result -= MULTIPLY_DIVIDE(++expr);
   break;
  default:
   break;
  }
 }

 return result;
}

int MULTIPLY_DIVIDE(char* &expr)
{
 auto result = operand(expr);

 while (expr[0] == '*' || expr[0] == '/')
 {
  switch (expr[0])
  {
  case '*':
   result *= operand(++expr);
   break;
  case '/':
   result /= operand(++expr);
   break;
  default:
   break;
  }
 }

 return result;
}

int operand(char* &expr)
{
 if (expr[0] == '(')
 {
  auto result = evaluate(++expr);
  expr++;
  return result;
 }
 else
 {
  return value(expr);
 }
}

int value(char* &expr)
{
 int nr = 0;

 while (isdigit(expr[0]))
 {
  nr = nr * 10 + (expr[0] - '0');
  expr++;
 }

 return nr;
}

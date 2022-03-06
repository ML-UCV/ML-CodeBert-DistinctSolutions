#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<string.h>


using namespace std;



ifstream f("evaluare.in");

ofstream g("evaluare.out");



char a[100005];

vector<char> op;

vector<int> numbers;

string fin;

void postfix()

{

 int n = strlen(a);

 for (int i = 0; i < n; ++i)

 {

  int nr = 0;

  bool number = false;

  while (i < n && a[i] >= '0' && a[i] <= '9')

  {

   number = true;

   nr = nr * 10 + a[i] - '0';

   i++;

  }

  if (number)

  {

   fin += to_string(nr) + ' ';

   i--;

   continue;

  }

  if (a[i] == '*' || a[i] == '/')

  {

   while (op.size() != 0 && op[op.size() - 1] != '(' && op[op.size() - 1] != '+' && op[op.size() - 1] != '-')

   {

    fin += op[op.size() - 1];

    op.pop_back();

   }

   op.push_back(a[i]);

  }

  else if (a[i] == '+' || a[i] == '-')

  {

   while (op.size() != 0 && op[op.size() - 1] != '(')

   {

    fin += op[op.size() - 1];

    op.pop_back();

   }

   op.push_back(a[i]);

  }

  else if (a[i] == '(')

  {

   op.push_back(a[i]);

  }

  else

  {

   while (op.size() != 0 && op[op.size() - 1] != '(')

   {

    fin += op[op.size() - 1];

    op.pop_back();

   }

   if(op.size() != 0)

    op.pop_back();

  }

 }

 while (op.size() != 0)

 {

  fin += op[op.size() - 1];

  op.pop_back();

 }

}



int calculate(int a, int b, char op)

{

 switch (op)

 {

 case '+':

  return a + b;

  break;

 case '-':

  return a - b;

  break;

 case '*':

  return a * b;

  break;

 case '/':

  return a / b;

  break;

 }

}



int eval()

{

 for (int i = 0; i < fin.size(); ++i)

 {

  int nr = 0;

  bool number = false;

  while (fin[i] >= '0' && fin[i] <= '9')

  {

   nr = nr * 10 + fin[i] - '0';

   i++;

   number = true;

  }

  if (number)

  {

   numbers.push_back(nr);

  }

  else if (fin[i] != ' ')

  {

   int val = calculate(numbers[numbers.size() - 2], numbers[numbers.size() - 1], fin[i]);

   numbers.pop_back();

   numbers.pop_back();

   numbers.push_back(val);

  }

 }

 return numbers[0];

}



int main()

{

 f.getline(a, 100005);

 postfix();

 g<<eval();

}

#include <iostream>
#include <cstdio>
#include <stack>
#include <string>






using namespace std;



string s;

int i = 0;

int res = 0;

stack<int> seq;



int open_bracket = 1000000000 + int('(');

int closed_bracket = 1000000000 + int(')');

int plus_sign = 1000000000 + int('+');

int minus_sign = 1000000000 + int('-');

int multiplication_sign = 1000000000 + int('*');

int division_sign = 1000000000 + int('/');



int sum_to_closed_bracket()

{

 int sum = 0;

 int nr;

 while (seq.top() != open_bracket)

 {

  nr = seq.top();

  seq.pop();

  if (seq.top() == plus_sign)

  {

   seq.pop();

   sum += nr;

  }

  if (seq.top() == minus_sign)

  {

   seq.pop();

   sum -= nr;

   nr = 0;

  }

 }

 return sum + nr;

}



void close_bracket()

{

 int sum = sum_to_closed_bracket();



 seq.pop();



 if (seq.top() == multiplication_sign)

 {

  seq.pop();

  int multiplier = seq.top();

  seq.pop();

  sum = multiplier * sum;

 }

 if (seq.top() == division_sign)

 {

  seq.pop();

  int dividend = seq.top();

  seq.pop();

  sum = dividend / sum;

 }

 seq.push(sum);

}



void readNumber()

{

 int nr = 0;

 while (i < s.length() && s[i] >= '0' && s[i] <= '9')

  nr = nr * 10 + int(s[i++] - '0');

 if (seq.top() == multiplication_sign)

 {

  seq.pop();

  int previous = seq.top();

  seq.pop();

  seq.push(previous * nr);

 }

 else

 {

  if (seq.top() == division_sign)

  {

   seq.pop();

   int previous = seq.top();

   seq.pop();

   seq.push(previous / nr);

  }

  else

   seq.push(nr);

 }



 --i;

}



int main() {

 freopen("evaluare.in", "r", stdin);

 freopen("evaluare.out", "w", stdout);

 cin >> s;

 seq.push(open_bracket);



 while (i < s.length())

 {

  switch (s[i])

  {

  case ')':

   close_bracket();

   break;

  case '(':

   seq.push(open_bracket);

   break;

  case '+':

   seq.push(plus_sign);

   break;

  case '-':

   seq.push(minus_sign);

   break;

  case '*':

   seq.push(multiplication_sign);

   break;

  case '/':

   seq.push(division_sign);

   break;

  default:

   readNumber();

   break;

  }

  ++i;

 }



 cout << sum_to_closed_bracket();



 return 0;

}

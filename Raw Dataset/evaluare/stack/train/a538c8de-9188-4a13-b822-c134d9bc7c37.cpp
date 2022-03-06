#include <cstdio>
#include <string>
#include <iostream>
#include <stack>
#include <string>
#include <cassert>
using namespace std;

string expression;

bool isOperator(char ch) {
 return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPriority(char ch) {
 if (ch == '+' || ch == '-') {
  return 1;
 } else if (ch == '*' || ch == '/') {
  return 2;
 }
 return -1;
}

void applyOperator(stack<int>& numbers, char op) {
 int secondNo = numbers.top();
 numbers.pop();
 int firstNo = numbers.top();
 numbers.pop();

 switch (op) {
  case '+': {
   numbers.push(firstNo + secondNo);
   break;
  }
  case '-': {
   numbers.push(firstNo - secondNo);
   break;
  }
  case '*': {
   numbers.push(firstNo * secondNo);
   break;
  }
  case '/': {
   numbers.push(firstNo / secondNo);
   break;
  }
 }
}

int main() {
 freopen("evaluare.in", "r", stdin);
 freopen("evaluare.out", "w", stdout);

 cin >> expression;
 stack<int> numbers;
 stack<char> operators;

 for (size_t i = 0; i < expression.size(); i++) {
  if (expression[i] == '(') {
   operators.push('(');
  } else if (expression[i] == ')') {
   while (operators.top() != '(') {
    applyOperator(numbers, operators.top());
    operators.pop();
   }
   operators.pop();
  } else if (isOperator(expression[i])) {
   while (!operators.empty() && getPriority(operators.top()) >= getPriority(expression[i])) {
    applyOperator(numbers, operators.top());
    operators.pop();
   }
   operators.push(expression[i]);
  } else {
   assert(isdigit(expression[i]));
   int number = 0;
   while (i < expression.size() && isdigit(expression[i])) {
    number = number * 10 + expression[i++] - '0';
   }
   i--;
   numbers.push(number);
  }
 }

 while (!operators.empty()) {
  applyOperator(numbers, operators.top());
  operators.pop();
 }

 cout << numbers.top() << "\n";
 return 0;
}

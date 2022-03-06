#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int opPriority(char c)
{
  if (c == '(' || c == ')') return -1;
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/') return 2;
  return 3;
}

bool isDigit(char c)
{
  return '0' <= c && c <= '9';
}

class ExpressionEvaluator{
 public:
  int Evaluate(string expr)
  {
    for (int i = 0; i < expr.size(); ++i) {
      char c = expr[i];
      if (c == '(') {
 op_.push(c);
 priority_.push(opPriority(c));
 continue;
      }
      if (isDigit(c)) {
 int number = c - '0';
 while (i+1 < expr.size() && isDigit(expr[i + 1])) {
   ++i;
   number = number * 10 + (expr[i] - '0');
 }
 numbers_.push(number);
 continue;
      }
      Pop_(opPriority(c));
      if (c != ')') {
 priority_.push(opPriority(c));
 op_.push(c);
      }
    }
    int result = numbers_.top();
    numbers_.pop();
    return result;
  }
 private:
  void Pop_(int p)
  {
    while (!priority_.empty() && priority_.top() >= p) {
      char op = op_.top();
      op_.pop();
      priority_.pop();

      if (op == '(')
 return;

      int b = numbers_.top();
      numbers_.pop();
      int a = numbers_.top();
      numbers_.pop();

      if (op == '+') numbers_.push(a + b);
      else if (op == '-') numbers_.push(a - b);
      else if (op == '*') numbers_.push(a * b);
      else if (op == '/') numbers_.push(a / b);
    }
  }

  stack<int> numbers_;
  stack<int> priority_;
  stack<char> op_;
};

int main()
{
  ifstream fin("evaluare.in");
  ofstream fout("evaluare.out");

  string s;
  fin >> s;

  ExpressionEvaluator exprEval;
  fout << exprEval.Evaluate("(" + s + ")");

  return 0;
}

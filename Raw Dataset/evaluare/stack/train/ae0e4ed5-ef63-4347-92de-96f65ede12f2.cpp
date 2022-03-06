#include <iostream>
#include <fstream>
#include <string>
#include <vector>
std::string expr;

int pos = 0;

bool issign(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/';
}

int eval() {

  std::vector<int> stack;

  std::string number;

  char prev_sign = '+';
  int value;

  if (expr[pos] == '-') {
    ++pos;
    prev_sign = '-';
  }

  for (; pos < expr.size(); ++pos) {

    if (isdigit(expr[pos])) {
      number += expr[pos];

    } else if (issign(expr[pos])) {

      if (!number.empty())
        value = std::stoi(number);

      number.clear();

      if (prev_sign == '*') {

        stack.back() *= value;

      } else if (prev_sign == '/') {

        stack.back() /= value;

      } else if (prev_sign == '+') {
        stack.push_back(value);

      } else if (prev_sign == '-') {
        stack.push_back(-value);

      }

      prev_sign = expr[pos];
    } else if (expr[pos] == '(') {

      ++pos;
      value = eval();

    } else if (expr[pos] == ')') {


      if (!number.empty())
        value = std::stoi(number);
      number.clear();

      if (prev_sign == '*') {

        stack.back() *= value;

      } else if (prev_sign == '/') {

        stack.back() /= value;

      } else if (prev_sign == '+') {
        stack.push_back(value);

      } else if (prev_sign == '-') {
        stack.push_back(-value);

      }

      break;
    }
  }

  int ans = 0;
  for (int el : stack)
    ans += el;


  return ans;
}

void read() {
  std::ifstream in("evaluare.in");

  std::getline(in, expr);
  expr += '+';

  in.close();
}

int main() {
  read();

  std::ofstream out("evaluare.out");
  out << eval() << '\n';

  out.close();
  return 0;
}

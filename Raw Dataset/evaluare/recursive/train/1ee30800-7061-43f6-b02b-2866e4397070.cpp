#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

bool is_numerical(char a) {
  return a >= '0' && a <= '9';
}
pair <int, int> get_term(string &exp, int pos);
pair <int, int> get_product(string &exp, int pos);

pair <int, int> evaluate(string &exp, int pos) {
  pair <int, int> term_1 = get_product(exp, pos);
  pos = term_1.second;
  while (exp[pos] == '+' || exp[pos] == '-') {
    if (exp[pos] == '+') {
      pair <int, int> term_2 = get_product(exp, pos + 1);
      term_1.first += term_2.first;
      pos = term_2.second;
    } else if (exp[pos] == '-') {
      pair <int, int> term_2 = get_product(exp, pos + 1);
      term_1.first -= term_2.first;
      pos = term_2.second;
    }

  }
  return {term_1.first, pos};
}

pair <int, int> get_term(string &exp, int pos) {
  if (exp[pos] == '(') {
    pair <int, int> res = evaluate(exp, pos + 1);
    pos = res.second;
    pos++;
    return {res.first, pos};
  } else {
    int number = 0;
    while (is_numerical(exp[pos])) {
      number = number * 10 + (exp[pos] - '0');
      pos++;
    }
    return {number, pos};
  }
}

pair <int, int> get_product(string &exp, int pos) {
  pair <int, int> term_1 = get_term(exp, pos);
  pos = term_1.second;
  while (exp[pos] == '*' || exp[pos] == '/') {
    if (exp[pos] == '*') {
      pair <int, int> term_2 = get_term(exp, pos + 1);
      term_1.first *= term_2.first;
      pos = term_2.second;
    } else if (exp[pos] == '/') {
      pair <int, int> term_2 = get_term(exp, pos + 1);
      term_1.first /= term_2.first;
      pos = term_2.second;
    }
  }
  return {term_1.first, pos};
}

int main() {
  ifstream fin("evaluare.in");
  ofstream fout("evaluare.out");

  string exp; fin >> exp;

  pair <int, int> result = evaluate(exp, 0);

  fout << result.first << "\n";

  return 0;
}

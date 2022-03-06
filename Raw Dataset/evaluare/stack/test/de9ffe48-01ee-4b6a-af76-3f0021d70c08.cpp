#include<iostream>
#include<fstream>
#include<stack>
#include<map>
#include<vector>
using namespace std;

bool is_number(char a) {
  return a >= '0' && a <= '9';
}

bool is_operator(char a) {
  return a == '+' || a == '-' || a == '*' || a == '/';
}

int result(int a, int b, string cur) {
  if (cur == "+")
    return a + b;
  if (cur == "-")
    return a - b;
  if (cur == "*")
    return a * b;
  if (cur == "/")
    return a / b;
  return 1;
}

vector <string> expresie_polandeza(string &exp) {
  int n = exp.size();

  map <char, int> prec;
  prec['+'] = prec['-'] = 0;
  prec['*'] = prec['/'] = 1;

  stack <char> st;
  st.push('e');

  vector <string> output;
  int i = 0;
  while (i < n) {
    if (is_number(exp[i])) {
      string number = "";
      while (is_number(exp[i])) {
        number += exp[i];
        i++;
      }
      output.push_back(number);
    } else {
      if (exp[i] == '(') {
        st.push(exp[i]);
      } else if (exp[i] == ')') {
        while (st.top() != '(') {
          output.push_back(string(1, st.top()));
          st.pop();
        }
        st.pop();
      } else {
          while (is_operator(st.top()) && prec[st.top()] >= prec[exp[i]]) {
            output.push_back(string(1, st.top()));
            st.pop();
          }
          st.push(exp[i]);
      }
      i++;
    }
  }

  while (st.top() != 'e') {
    output.push_back(string(1, st.top()));
    st.pop();
  }
  st.pop();

  return output;
}


int evaluare_polandeza(vector <string> &output) {
  stack <int> eval;
  for (int i = 0; i < (int) output.size(); i++) {
    string cur = output[i];
    if (!is_operator(cur[0])) {
      eval.push(stoi(cur));
    } else {
      int a = eval.top();
      eval.pop();
      int b = eval.top();
      eval.pop();
      int r = result(b, a, cur);
      eval.push(r);
    }
  }
  return eval.top();
}

int main() {
  ifstream fin("evaluare.in");
  ofstream fout("evaluare.out");

  string exp; fin >> exp;

  vector <string> output = expresie_polandeza(exp);

  int res = evaluare_polandeza(output);
  fout << res << "\n";

  return 0;
}

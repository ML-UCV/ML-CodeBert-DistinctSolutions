#include<iostream>
#include<fstream>
#include<stack>
#include<map>
#include<vector>
using namespace std;

struct node {
  int tip, val;
  char op;
  node *left, *right;
  node(int t = 0, int v = 0, char o = ' ', node *l = 0, node *r = 0) {
    tip = t;
    val = v;
    op = o;
    left = l;
    right = r;
  }
};

bool is_number(char a) {
  return a >= '0' && a <= '9';
}

bool is_operator(char a) {
  return a == '+' || a == '-' || a == '*' || a == '/';
}

int result(int a, int b, char cur) {
  if (cur == '+')
    return a + b;
  if (cur == '-')
    return a - b;
  if (cur == '*')
    return a * b;
  if (cur == '/')
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

node *arbore(vector <string> &exp) {
  stack <node *> members;
  for (int i = 0; i < (int) exp.size(); i++) {
    node *this_node;
    if (!is_operator(exp[i][0])) {

      this_node = new node(0, stoi(exp[i]), ' ', 0, 0);
    } else {
      node *right = members.top();
      members.pop();
      node *left = members.top();
      members.pop();
      this_node = new node(1, 0, exp[i][0], left, right);
    }
    members.push(this_node);
  }
  return members.top();
}

int rezolvare_arbore(node *root) {
  if (root->tip == 0)
    return root->val;
  if (root->tip == 1) {
    int l = rezolvare_arbore(root->left), r = rezolvare_arbore(root->right);
    return result(l, r, root->op);
  }
  return 0;
}

int main() {
  ifstream fin("evaluare.in");
  ofstream fout("evaluare.out");

  string exp; fin >> exp;

  vector <string> output = expresie_polandeza(exp);

  node *root = arbore(output);

  int res = rezolvare_arbore(root);
  fout << res << "\n";

  return 0;
}

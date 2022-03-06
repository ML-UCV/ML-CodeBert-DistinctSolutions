#include<fstream>
#include<vector>
using namespace std;

struct node {
  int type, val;
  char op;
  node *left, *right;
  node (int t = 0, int v = 0, char o = ' ', node *l = 0, node *r = 0) {
    type = t;
    val = v;
    op = o;
    left = l;
    right = r;
  }
};

int evaluate(int a, int b, char op) {
  if (op == '+')
    return a + b;
  if (op == '-')
    return a - b;
  if (op == '*')
    return a * b;
  if (op == '/')
    return a / b;
  return 1;
}

bool is_numerical(char a) {
  return a >= '0' && a <= '9';
}
pair <node*, int> get_term(string &exp, int pos);
pair <node*, int> get_product(string &exp, int pos);

pair <node*, int> evaluate_exp(string &exp, int pos) {
  pair <node*, int> term_1 = get_product(exp, pos);
  pos = term_1.second;
  while (exp[pos] == '+' || exp[pos] == '-') {
    node *parent;
    if (exp[pos] == '+') {
      pair <node*, int> term_2 = get_product(exp, pos + 1);
      pos = term_2.second;
      parent = new node(1, 0, '+', term_1.first, term_2.first);
      term_1.first = parent;
    } else if (exp[pos] == '-') {
      pair <node*, int> term_2 = get_product(exp, pos + 1);
      pos = term_2.second;
      parent = new node(1, 0, '-', term_1.first, term_2.first);
      term_1.first = parent;
    }

  }
  return {term_1.first, pos};
}

pair <node*, int> get_term(string &exp, int pos) {
  if (exp[pos] == '(') {
    pair <node*, int> res = evaluate_exp(exp, pos + 1);
    pos = res.second;
    pos++;
    return {res.first, pos};
  } else {
    int number = 0;
    while (is_numerical(exp[pos])) {
      number = number * 10 + (exp[pos] - '0');
      pos++;
    }
    node* leaf;
    leaf = new node(0, number, ' ', 0, 0);
    return {leaf, pos};
  }
}

pair <node*, int> get_product(string &exp, int pos) {
  pair <node*, int> term_1 = get_term(exp, pos);
  pos = term_1.second;
  while (exp[pos] == '*' || exp[pos] == '/') {
    node* parent;
    if (exp[pos] == '*') {
      pair <node*, int> term_2 = get_term(exp, pos + 1);
      parent = new node(1, 0, '*', term_1.first, term_2.first);
      pos = term_2.second;
      term_1.first = parent;
    } else if (exp[pos] == '/') {
      pair <node*, int> term_2 = get_term(exp, pos + 1);
      parent = new node(1, 0, '/', term_1.first, term_2.first);
      pos = term_2.second;
      term_1.first = parent;
    }
  }
  return {term_1.first, pos};
}

int evaluate_tree(node *root) {
  if (root->type == 0)
    return root->val;
  int l = evaluate_tree(root->left), r = evaluate_tree(root->right);
  return evaluate(l, r, root->op);
}

int main() {
  ifstream fin("evaluare.in");
  ofstream fout("evaluare.out");

  string exp; fin >> exp;

  pair <node*, int> root = evaluate_exp(exp, 0);

  int result = evaluate_tree(root.first);

  fout << result << "\n";

  return 0;
}

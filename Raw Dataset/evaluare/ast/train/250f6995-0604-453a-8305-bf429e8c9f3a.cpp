#include <cstdio>
#include <cstring>
#include <algorithm>

const int LMAX = 100005;

char s[LMAX];

struct Node {
 Node *left{0}, *right{0};
 int value{0};
 char op{'#'};
};

Node* build(int left, int right);

Node* build_ops(int left, int right, const char* ops) {
 int brackets = 0;

 for (int i = right; i >= left; i--) {
  if (s[i] == ')')
   brackets++;
  else if (s[i] == '(')
   brackets--;
  else if (!brackets && strchr(ops, s[i])) {
   Node* node = new Node;
   node->op = s[i];
   node->left = build(left, i - 1);
   node->right = build(i + 1, right);
   return node;
  }
 }

 return 0;
}

Node* build(int left, int right) {
 if (Node *node = build_ops(left, right, "+-"))
  return node;

 if (Node *node = build_ops(left, right, "*/"))
  return node;

 if (s[left] == '(')
  return build(left + 1, right - 1);

 Node *node = new Node;
 char aux = 0;

 std::swap(s[right + 1], aux);
 sscanf(s + left, "%d", &node->value);
 std::swap(s[right + 1], aux);

 return node;
}

int eval(Node* node) {
 if (node->op == '#')
  return node->value;

 int left = eval(node->left);
 int right = eval(node->right);

 if (node->op == '+')
  return left + right;
 if (node->op == '-')
  return left - right;
 if (node->op == '*')
  return left * right;
 if (node->op == '/')
  return left / right;

 return -1;
}

int main() {
 freopen("evaluare.in", "r", stdin);
 freopen("evaluare.out", "w", stdout);

 scanf("%s", s);

 Node* root = build(0, strlen(s) - 1);

 printf("%d\n", eval(root));

 return 0;
}

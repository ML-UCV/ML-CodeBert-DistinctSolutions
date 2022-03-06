#include <bits/stdc++.h>




using namespace std;

typedef long long ll;

ifstream in("evaluare.in");

ofstream out("evaluare.out");

const int N = 100005;

char c[N];

string s;

stack < int > nums;

stack < char > op;

bool is_op(char ch) {

  if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {

    return true;

  }

  return false;

}

int val(char ch) {

  if (ch == '+' || ch == '-') {

    return 1;

  }

  if (ch == '*' || ch == '/') {

    return 2;

  }

  return -1;

}

int do_op(char op) {

  int a = nums.top();

  nums.pop();

  int b = nums.top();

  nums.pop();

  if (op == '+') {

    b += a;

  }

  if (op == '-') {

    b -= a;

  }

  if (op == '*') {

    b *= a;

  }

  if (op == '/') {

    b /= a;

  }

  nums.push(b);

}

int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(0);

  in >> s;

  for (int i = 0; i < s.size(); i++) {

    c[i + 1] = s[i];

  }

  int n = s.size();

  for (int i = 1; i <= n; i++) {

    if (c[i] == '(') {

      op.push('(');

    }

    else if (c[i] == ')') {

      while(op.top() != '(') {

        char oper = op.top();

        op.pop();

        do_op(oper);

      }

      op.pop();

    }

    else if (is_op(c[i])) {

      while(op.size() && val(c[i]) <= val(op.top())) {

        do_op(op.top());

        op.pop();

      }

      op.push(c[i]);

    }

    else {

      int nr = 0;

      int j = i;

      while(c[j] >= '0' && c[j] <= '9') {

        nr = nr * 10 + (c[j] - '0');

        j++;

      }

      nums.push(nr);

      i = j - 1;

    }

  }

  while(op.size()) {

    do_op(op.top());

    op.pop();

  }

  out << nums.top() << '\n';

  return 0;

}

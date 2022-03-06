#include <bits/stdc++.h>


char expr[100000], *p = expr;

long termen();
long factor();

long eval() {
 long r = termen();
 while (*p == '+' || *p == '-') {
  switch (*p) {
   case '+':
    ++p;
    r += termen();
    break;
   case '-':
    ++p;
    r -= termen();
    break;
  }
 }

 return r;
}

long termen() {
 long r = factor();
 while (*p == '*' || *p == '/') {
  switch (*p) {
   case '*':
    ++p;
    r *= factor();
    break;
   case '/':
    ++p;
    r /= factor();
    break;
  }
 }

 return r;
}

long factor() {
 long r = 0;
 if (*p == '(') {
  ++p;
  r = eval();
  ++p;
 } else {
  while ('0' <= *p && *p <= '9') {
   r = (r << 3) + (r << 1) + *p - '0';
   ++p;
  }
 }

 return r;
}

int main() {
 fgets(expr, 100000, fopen("evaluare.in", "r"));
 fprintf(fopen("evaluare.out", "w"), "%ld\n", eval());
 return 0;
}

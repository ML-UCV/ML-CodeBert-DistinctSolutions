#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;



char s[100010], st[100010];

int rez[100010];

int top_st = -1, top_rez = -1;



int eval(int a, int b, char op) {

  if(op == '+')

    return a + b;

  if(op == '-')

    return a - b;

  if(op == '*')

    return a * b;

  if(op == '/')

    return a / b;

}



int priority(char op) {

  if(op == '+' || op == '-')

    return 1;

  if(op == '*' || op == '/')

    return 2;

  return 0;

}



int main() {

  FILE *fin = fopen("evaluare.in", "r");

  FILE *fout = fopen("evaluare.out", "w");

  int i, n, x;



  fscanf(fin, "%s", &s);

  n = strlen(s);

  st[0] = '(';

  top_st = 0;

  s[n] = ')';

  n++;

  for(i = 0; i < n; i++) {

    if(s[i] >= '0' && s[i] <= '9') {

      x = 0;

      while(s[i] >= '0' && s[i] <= '9') {

        x = x * 10 + s[i] - '0';

        i++;

      }

      i--;

      rez[++top_rez] = x;

    }

    else if(s[i] == '(')

      st[++top_st] = '(';

    else if(s[i] == ')') {

      while(st[top_st] != '(') {

        rez[top_rez - 1] = eval(rez[top_rez - 1], rez[top_rez], st[top_st]);

        top_st--;

        top_rez--;

      }

      top_st--;

    }

    else {

      while(priority(s[i]) <= priority(st[top_st])) {

        rez[top_rez - 1] = eval(rez[top_rez - 1], rez[top_rez], st[top_st]);

        top_st--;

        top_rez--;

      }

      st[++top_st] = s[i];

    }

  }

  fprintf(fout, "%d", rez[0]);



  return 0;

}

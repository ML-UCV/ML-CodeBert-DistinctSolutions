#include <cstdio>
#include <cstring>
#include <cctype>

const int LMAX = 100005;

char input[LMAX];
char *p = input;

int eval_add();
int eval_mul();
int eval_par();

int eval_add() {
    int result = eval_mul();

    while (strchr("+-", *p))
        if (*p == '+')
            p++, result += eval_mul();
  else
            p++, result -= eval_mul();

    return result;
}

int eval_mul() {
    int result = eval_par();

    while (strchr("*/", *p))
        if (*p == '*')
            p++, result *= eval_par();
  else
            p++, result /= eval_par();

    return result;
}

int eval_par() {
    int result = 0;

    if (*p == '(')
        p++, result = eval_add(), p++;
 else
        while (isdigit(*p))
            result = result * 10 + (*p - '0'), p++;

    return result;
}

int main() {
 freopen("evaluare.in", "r", stdin);
    freopen("evaluare.out", "w", stdout);

    fgets(input, LMAX, stdin);
 printf("%d\n", eval_add());

    return 0;
}

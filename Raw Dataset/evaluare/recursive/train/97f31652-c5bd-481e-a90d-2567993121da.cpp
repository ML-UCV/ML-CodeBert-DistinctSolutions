#include <string.h>
#include <stdio.h>






char op[4][4] = { "+-", "*/", "^", "" };





char S[100010], * p = S;



int eval(int a, int b, char o) {

    switch (o) {

    case '+': return a + b;

    case '-': return a - b;

    case '*': return a * b;

    case '/': return a / b;

    }

}

int expr(int lev) {

    int x, y;



    if (lev == 2)

        if (*p == '(')

            ++p, x = expr(0), ++p;

        else

            for (x = 0; *p >= '0' && *p <= '9'; ++p)

                x = x * 10 + *p - '0';

    else

        for (x = expr(lev + 1); strchr(op[lev], *p); x = y)

            y = eval(x, expr(lev + 1), *p++);

    return x;

}



int main() {

    fgets(S, 100010, fopen("evaluare.in", "r"));

    fprintf(fopen("evaluare.out", "w"), "%d\n", expr(0));

    return 0;

}

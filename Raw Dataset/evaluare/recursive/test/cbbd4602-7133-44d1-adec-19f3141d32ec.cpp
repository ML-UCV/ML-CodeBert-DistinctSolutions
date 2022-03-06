#include <cstdio>
#include <cstring>


using namespace std;

const int NMAX = 100005;

char s[NMAX];

char *p = s;

int termen();

int factor();

int eval() {

    int r = termen();

    while(*p == '+' || *p == '-') {

        switch(*p) {

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

int termen() {

    int r = factor();

    while(*p == '*' || *p == '/') {

        switch(*p) {

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

int factor() {

    int r = 0;

    if(*p == '(') {

        ++p;

        r = eval();

        ++p;

    } else {

        while((*p ^ '0') < 10) {

            r = r * 10 + *p - '0';

            ++p;

        }

    }

    return r;

}



int main()

{

    freopen("evaluare.in", "r", stdin);

    freopen("evaluare.out", "w", stdout);

    int k = -1;

    char ch;

    while(scanf("%c", &ch) != -1 && ch != '\n') s[++k] = ch;

    printf("%d\n", eval());

    return 0;

}

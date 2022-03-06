#include <cstdio>
#include <iostream>
char s[100010];
int i = 0;


long termen();

long factor();
long eval() {

    long rezultat = termen();

    while (s[i] == '+' || s[i] == '-') {
        switch (s[i]) {
            case '+':
                ++i;
                rezultat += termen();
                break;
            case '-':
                ++i;
                rezultat -= termen();
                break;
        }
    }
    return rezultat;
}
long termen() {
    long rezultat = factor();

    while (s[i] == '*' || s[i] == '/') {
        switch (s[i]) {
            case '*':
                i++;
                rezultat *= factor();
                break;
            case '/':
                i++;
                rezultat /= factor();
                break;
        }
    }
    return rezultat;
}
long factor() {
    if (s[i] == '(') {
        i++;
        long rezultat = eval();
        i++;
        return rezultat;
    }
    int rezultat = 0;
    while (isdigit(s[i]))
        rezultat = rezultat * 10 + s[i++] - '0';
    return rezultat;
}


int main() {

    fgets(s, 100010, fopen("evaluare.in", "r"));
    fprintf(fopen("evaluare.out", "w"), "%ld\n", eval());

    return 0;

}

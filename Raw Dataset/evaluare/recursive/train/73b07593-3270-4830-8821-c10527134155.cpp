#include <fstream>

char s[100001];
int p = 0;

int evaluate();

int multiplier() {
    if (s[p] == '(') {
        ++p;
        int r = evaluate();
        ++p;
        return r;
    }
    int n = 0;
    while (s[p] >= '0' && s[p] <= '9') n = n * 10 + (s[p++] - '0');
    return n;
}

int addend() {
    int r = multiplier();
    while (s[p] == '*' || s[p] == '/') {
        if (s[p++] == '*') {
            r *= multiplier();
        } else {
            r /= multiplier();
        }
    }
    return r;
}

int evaluate() {
    int r = addend();
    while (s[p] == '+' || s[p] == '-') {
        if (s[p++] == '+') r += addend();
        else r -= addend();
    }
    return r;
}

int main() {
    std::ifstream in("evaluare.in");
    std::ofstream out("evaluare.out");
    in >> s;
    out << evaluate();
    return 0;
}

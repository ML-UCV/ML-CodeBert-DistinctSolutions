#include <fstream>
#include <cstring>
#include <cctype>
#include <fstream>


constexpr int N = 100000;

char s[N + 1];

char *p = s;



int expresie();

int termen();

int factor();



int expresie() {

    int sum = termen();

    while (*p && strchr("+-", *p)) {

        ++p;

        if (p[-1] == '+') {

            sum += termen();

        }

        else {

            sum -= termen();

        }

    }

    return sum;

}



int termen() {

    int prod = factor();

    while (*p && strchr("/*", *p)) {

        ++p;

        if (p[-1] == '*') {

            prod *= factor();

        }

        else {

            prod /= factor();

        }

    }

    return prod;

}



int factor() {

    int val = 0;

    int sign = 1;

    while (*p == '-') {

        sign = -sign;

        ++p;

    }

    if (*p == '(') {

        ++p;

        val = expresie();

        ++p;

        return sign * val;

    }

    while (isdigit(*p)) {

        val = val * 10 + *p - '0';

        ++p;

    }

    return sign * val;

}



int main() {

    std::ifstream in("evaluare.in");

    std::ofstream out("evaluare.out");

    in.getline(s, sizeof s);

    out << expresie() << '\n';

}

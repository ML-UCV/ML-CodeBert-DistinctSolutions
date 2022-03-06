#include <bits/stdc++.h>
using namespace std;

ifstream in("evaluare.in");

ofstream out("evaluare.out");

string s;

int i = 0;

long long produs();

long long term();



long long eval() {

    long long r = produs();

    while (s[i] == '+' || s[i] == '-') {

        if (s[i] == '+') {

            i++;

            r += produs();

        }

        else if (s[i] == '-') {

            i++;

            r -= produs();

        }

    }

    return r;

}

long long produs() {

    long long r = term();

    while (s[i] == '*' || s[i] == '/') {

        if (s[i] == '*') {

            i++;

            r *= term();

        }

        else if (s[i] == '/') {

            i++;

            r /= term();

        }

    }

        return r;

}

long long term() {

    long long r = 0;

    if (s[i] == '(') {

            i++;

            r = eval();

            i++;

        }

    else {

        while (s[i] >= '0' && s[i] <= '9') {

            r = r * 10 + (s[i] - '0');

            i++;

        }

    }

    return r;

}

int main() {

    in >> s;

    out << eval();

}

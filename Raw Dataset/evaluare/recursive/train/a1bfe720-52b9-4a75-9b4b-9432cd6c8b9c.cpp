#include <bits/stdc++.h>


using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

string s;

long long p;



long long termen();

long long factor();



long long eval() {

    long long r = termen();

    while (s[p] == '+' || s[p] == '-') {

        if (s[p] == '+') {

            ++p;

            r += termen();

        }

        else if (s[p] == '-') {

            ++p;

            r -= termen();

        }

    }

    return r;

}



long long termen() {

    long long r = factor();

    while (s[p] == '*' || s[p] == '/') {

        if (s[p] == '*') {

            ++p;

            r *= factor();

        }

        else if (s[p] == '/') {

            ++p;

            r /= factor();

        }

    }

    return r;

}



long long factor() {

    long long r = 0;

    if (s[p] == '(' || s[p] == ')') {

        ++p;

        r = eval();

        ++p;

    }

    else

        while (s[p] >= '0' && s[p] <= '9') {

            r = r * 10 + (s[p] - '0');

            ++p;

        }

    return r;

}



int main() {

    getline(fin, s);

    fout << eval();

    return 0;

}

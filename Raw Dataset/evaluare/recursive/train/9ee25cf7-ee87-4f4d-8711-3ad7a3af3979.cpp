#include <bits/stdc++.h>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

const int MAXN = 1e6 + 5;

char sir[MAXN], *p = sir;

long long termen();

long long factor();

long long eval(){

    long long r = termen();

    while(*p == '+' or *p == '-'){

        if(*p == '+'){

            ++p;

            r += termen();

        }

        else if(*p == '-'){

            ++p;

            r -= termen();

        }

    }

    return r;

}

long long termen(){

    long long r = factor();

    while(*p == '*' or *p == '/'){

        if(*p == '*'){

            ++p;

            r *= factor();

        }

        else if(*p == '/'){

            ++p;

            r /= factor();

        }

    }

    return r;

}

long long factor(){

    long long r = 0;

    if(*p == '(') {

        ++p;

        r = eval();

        ++p;

    }

    else{

        while(*p >= '0' and *p <= '9')

            r = r * 10 + *p - '0', ++p;

    }

    return r;

}

int main(){

    fin.getline(sir, MAXN);

    fout << eval();

    return 0;

}

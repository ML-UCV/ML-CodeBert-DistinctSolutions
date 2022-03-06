#include <iostream>
#include <fstream>

using namespace std;

string s;
int i;

long termen();
long factor();

long eval() {
    long r = termen();
    while(s[i] == '+' || s[i] == '-') {
        if(s[i] == '+') {
            i++;
            r += termen();
        }
        else if(s[i] == '-') {
            i++;
            r -= termen();
        }
    }
    return r;
}

long termen() {
    long r = factor();
    while(s[i] == '*' || s[i] == '/') {
        if(s[i] == '*') {
            i++;
            r *= factor();
        }
        else if(s[i] == '/') {
            i++;
            r /= factor();
        }
    }
    return r;
}

long factor() {
    long r = 0;
    if(s[i] == '(') {
        i++;
        r = eval();
        i++;
    }
    else
        while(isdigit(s[i]))
            r = r * 10 + (s[i++] - '0');
    return r;
}

int main() {
    ifstream f("evaluare.in");
    ofstream g("evaluare.out");
    getline(f, s);

    g << eval() << '\n';
    f.close();
    g.close();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string file="evaluare";

ifstream fin(file+".in");
ofstream fout(file+".out");

int termen();
int factor();
int calcul();

int i;
char s[100001];

int main() {
    fin >> s;
    fout << calcul();
    return 0;
}

int calcul() {
    int x = termen();
    while (s[i] == '+' || s[i] == '-') {
        if (s[i] == '+') {
            i++;
            x = x + termen();
        } else {
            i++;
            x = x - termen();
        }
    }
    i++;
    return x;
}

int termen() {
    int x = factor();
    while (s[i] == '*' || s[i] == '/') {
        if (s[i] == '*') {
            i++;
            x = x * factor();
        } else {
            i++;
            x = x / factor();
        }
    }
    return x;
}

int factor() {
    int x = 0;
    if (s[i] == '(') {
        i++;
        return calcul();
    } else {
        while (s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + s[i] - '0';
            i++;
        }
        return x;
    }
}

#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <string>
#include <cctype>
using namespace std;


ifstream cin("evaluare.in");
ofstream cout("evaluare.out");

int i;
string s;

int op1();
int op2();
int op3();

int op1() {
    int ans = op2();
    while (s[i] == '+' || s[i] == '-') {
        if (s[i] == '+') {
            i++;
            ans += op2();
        }
        else {
            i++;
            ans -= op2();
        }
    }
    return ans;
}

int op2() {
    int ans = op3();
    while (s[i] == '*' || s[i] == '/') {
        if (s[i] == '*') {
            i++;
            ans *= op3();
        } else {
            i++;
            ans /= op3();
        }
    }
    return ans;
}

int op3() {
    int ans = 0;
    if (s[i] == '(') {
        i++;
        ans = op1();
        i++;
    } else {
        while (isdigit(s[i]) && i <s.size()) {
            ans *= 10;
            ans += s[i] - '0';
            i++;
        }
    }
    return ans;
}

int main() {
    cin >> s;
    cout << op1() << '\n';
    return 0;
}

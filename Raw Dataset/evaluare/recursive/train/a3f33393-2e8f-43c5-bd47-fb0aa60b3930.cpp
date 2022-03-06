#include <bits/stdc++.h>

using namespace std;

int where = 0;
char s[100002];

int solveMultiplicationDivision();
int solveBracketsNumbers();

int solveAdditionSubtraction() {
    int value = solveMultiplicationDivision();
    while (s[where] == '+' or s[where] == '-') {
        if (s[where] == '+') {
            where += 1;
            value += solveMultiplicationDivision();
        } else {
            where += 1;
            value -= solveMultiplicationDivision();
        }
    }
    return value;
}

int solveMultiplicationDivision() {
    int value = solveBracketsNumbers();
    while (s[where] == '*' or s[where] == '/') {
        if (s[where] == '*') {
            where += 1;
            value *= solveBracketsNumbers();
        } else {
            where += 1;
            value /= solveBracketsNumbers();
        }
    }
    return value;
}

int solveBracketsNumbers() {
    int result = 0;
    if (s[where] == '(') {
        where += 1;
        result = solveAdditionSubtraction();
        where += 1;
    } else {
        while ('0' <= s[where] and s[where] <= '9') {
            result = result * 10 + (s[where] - '0');
            where += 1;
        }
    }
    return result;
}

int main() {
    ifstream fin("evaluare.in");
    ofstream fout("evaluare.out");
    fin.getline(s, 100002);
    fout << solveAdditionSubtraction();
    return 0;
}

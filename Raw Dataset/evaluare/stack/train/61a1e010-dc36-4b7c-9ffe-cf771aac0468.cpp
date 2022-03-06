#include <fstream>
#include <cstring>
#include <stack>

using namespace std;

ifstream f("evaluare.in");
ofstream g("evaluare.out");

char s[100005];
stack<char> operatori;
stack<int> operanzi;

void evaluare_expresie() {
    while (!operatori.empty() && operatori.top() != '(') {
        int b = operanzi.top();
        operanzi.pop();
        int a = operanzi.top();
        operanzi.pop();
        char op = operatori.top();
        operatori.pop();
        switch (op) {
            case '+':
                operanzi.push(a + b);
                break;
            case '-':
                operanzi.push(a - b);
                break;
            case '*':
                operanzi.push(a * b);
                break;
            case '/':
                operanzi.push(a / b);
                break;
        }
    }
}

int evaluare() {
    int nrl = strlen(s);
    for (int i = 0; i < nrl; ++i) {
        if (s[i] == '(')
            operatori.push('(');
        else if (s[i] == ')') {
            evaluare_expresie();
            operatori.pop();
        } else if (s[i] == '+' || s[i] == '-') {
            evaluare_expresie();
            operatori.push(s[i]);
        } else if (s[i] == '*' || s[i] == '/') {
            if (!operatori.empty()) {
                char inainte = operatori.top();
                if (inainte == '*' || inainte == '/') {
                    int b = operanzi.top();
                    operanzi.pop();
                    int a = operanzi.top();
                    operanzi.pop();
                    operatori.pop();
                    if (inainte == '*')
                        operanzi.push(a * b);
                    else
                        operanzi.push(a / b);
                }
            }
            operatori.push(s[i]);
        } else {
            int nr = 0, j;
            for (j = i; j < nrl && isdigit(s[j]); ++j)
                nr = nr * 10 + s[j] - '0';
            operanzi.push(nr);
            i = j - 1;
        }
    }
    evaluare_expresie();
    return operanzi.top();
}

int main() {
    f.getline(s, 100005);
    g << evaluare();
    return 0;
}

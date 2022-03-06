#include <fstream>
#include <stack>



using namespace std;

stack<int> postForm;
stack<char> opStack;

int priorities[256];

void setPriorities() {
    priorities['+'] = 1;
    priorities['-'] = 1;
    priorities['*'] = 2;
    priorities['/'] = 2;
    priorities['('] = 0;
}

int getNum(char *&s) {
    int num = 0;
    while (isdigit(*s)) {
        num = num * 10 + *s - '0';
        s++;
    }
    return num;
}

int eval(int x, int y, char op) {
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        default:
            return 0;
    }
}

void evaluateLast() {
    char op = opStack.top();
    opStack.pop();
    int o2 = postForm.top();
    postForm.pop();
    int o1 = postForm.top();
    postForm.pop();
    postForm.push(eval(o1, o2, op));
}

void convert(char *s) {
    while (*s) {
        if (isdigit(*s)) {
            postForm.push(getNum(s));
        } else {
            if (*s == '(') {
                opStack.push(*s);
                s++;
            } else if (*s == ')') {
                while (opStack.top() != '(') {
                    evaluateLast();
                }
                opStack.pop();
                s++;
            } else {
                char op = *s;
                s++;
                while (!opStack.empty() && priorities[opStack.top()] >= priorities[op]) {
                    evaluateLast();
                }
                opStack.push(op);
            }
        }
    }
    while (!opStack.empty()) {
        evaluateLast();
    }
}

int main() {
    ifstream f("evaluare.in");
    ofstream g("evaluare.out");
    setPriorities();
    char S[100005], *s = S;
    f >> S;
    convert(s);
    g << postForm.top() << '\n';
    return 0;
}

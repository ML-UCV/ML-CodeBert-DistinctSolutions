#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;



bool isDigit(char c) {

    if(c >= '0' && c <= '9')

        return true;

    return false;

}



int priority(char c) {

    if(c == '*' || c == '/')

        return 2;

    if(c == '+' || c == '-')

        return 1;

    return 0;

}



int operate(int n1, int n2, char op) {

    switch(op) {

        case '*':

            return n1 * n2;

        case '/':

            return n1 / n2;

        case '+':

            return n1 + n2;

        case '-':

            return n1 - n2;

    }

}



int main() {

    char s[100005], operation;

    int i, l, n1, n2;

    stack<int> nr;

    stack<char> op;



    freopen("evaluare.in", "r", stdin);

    freopen("evaluare.out", "w", stdout);

    scanf("%s", s);

    l = strlen(s);



    for(i = 0; i < l; ++i)

        if(priority(s[i])) {

            while(!op.empty() && priority(s[i]) <= priority(op.top())) {

                n2 = nr.top();

                nr.pop();

                n1 = nr.top();

                nr.pop();

                operation = op.top();

                op.pop();

                nr.push(operate(n1, n2, operation));

            }

            op.push(s[i]);

        }

        else if(isDigit(s[i])) {

            n1 = 0;

            while(isDigit(s[i]) && i < l)

                n1 = 10*n1 + s[i++] - '0';

            --i;

            nr.push(n1);

        }

        else if(s[i] == '(')

            op.push('(');

        else if(s[i] == ')') {

            while(!op.empty() && op.top() != '(') {

                n2 = nr.top();

                nr.pop();

                n1 = nr.top();

                nr.pop();

                operation = op.top();

                op.pop();

                nr.push(operate(n1, n2, operation));

            }

            op.pop();

        }



    while(!op.empty()) {

        n2 = nr.top();

        nr.pop();

        n1 = nr.top();

        nr.pop();

        operation = op.top();

        op.pop();

        nr.push(operate(n1, n2, operation));

    }



    printf("%d", nr.top());

}

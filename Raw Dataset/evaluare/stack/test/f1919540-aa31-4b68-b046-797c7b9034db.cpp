#include <cstdio>
#include <stack>
#include <cstring>
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



int operate(int n1, int n2, char c) {

    switch(c) {

        case '+':

            return n1 + n2;

        case '-':

            return n1 - n2;

        case '*':

            return n1 * n2;

        case '/':

            return n1 / n2;

    }

}



int main() {

    char expresie[100005], sign;

    int l, i, temp, n1, n2;

    stack<int> nr;

    stack<char> op;

    freopen("evaluare.in", "r", stdin);

    freopen("evaluare.out", "w", stdout);



    scanf("%s", expresie);

    l = strlen(expresie);



    for(i = 0; i < l; ++i) {

        if(priority(expresie[i])) {

            while(!op.empty() && priority(expresie[i]) <= priority(op.top())) {

                sign = op.top();

                op.pop();

                n2 = nr.top();

                nr.pop();

                n1 = nr.top();

                nr.pop();

                nr.push(operate(n1, n2, sign));

            }

            op.push(expresie[i]);



        }

        else if(isDigit(expresie[i])) {

            temp = 0;

            while(isDigit(expresie[i]) && i < l)

                temp = 10*temp + expresie[i++] - '0';

            nr.push(temp);

            i--;

        }

        else if(expresie[i] == '(')

            op.push('(');

        else if(expresie[i] == ')') {

            while(!op.empty() && op.top() != '(') {

                n2 = nr.top();

                nr.pop();

                n1 = nr.top();

                nr.pop();

                sign = op.top();

                op.pop();

                nr.push(operate(n1, n2, sign));

            }

            op.pop();

        }

    }



    while(!op.empty()) {

        n2 = nr.top();

        nr.pop();

        n1 = nr.top();

        nr.pop();

        sign = op.top();

        op.pop();

        nr.push(operate(n1, n2, sign));

    }

    printf("%d", nr.top());

}

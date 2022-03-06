#include <bits/stdc++.h>


using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



stack <char> operations;

stack <int> numbers;

string expression;



bool isOperator(char s) {

    if(s == '+' || s == '-' || s == '*' || s == '/') {

        return 1;

    }

    return 0;

}



int priority(char s) {

    if(s == '+' || s == '-') {

        return 0;

    } else if(s == '*' || s == '/') {

        return 1;

    }

    return -1;

}



int calculateOperation() {

    int a = numbers.top(); numbers.pop();

    int b = numbers.top(); numbers.pop();



    char op = operations.top(); operations.pop();

    if(op == '+') {

        return a + b;

    } else if(op == '-') {

        return b - a;

    } else if(op == '/') {

        return b / a;

    }

    return a * b;

}



void prepare() {

    int i = 0, next_value;

    while(i < expression.length()) {

        if(isOperator(expression[i])) {

            while(operations.size() && priority(expression[i]) <= priority(operations.top())) {

                int next_value = calculateOperation();

                numbers.push(next_value);

            }

            operations.push(expression[i]);

            i++;

        } else if(isdigit(expression[i])) {

            int integer = 0;

            while(expression[i] >= '0' && expression[i] <= '9' && i < expression.length()) {

                integer = integer * 10 + (expression[i] - '0');

                i++;

            }

            numbers.push(integer);

        } else if(expression[i] == '(') {

            operations.push(expression[i]);

            i++;

        } else if(expression[i] == ')') {

            while(operations.top() != '(') {

                next_value = calculateOperation();

                numbers.push(next_value);

            }

            i++;

            operations.pop();

        }

    }

}



int calculateExpression() {

    while(operations.size()) {

        int next_value = calculateOperation();

        numbers.push(next_value);

    }

    return numbers.top();

}



int main()

{

    in >> expression;

    prepare();

    out << calculateExpression();

    return 0;

}

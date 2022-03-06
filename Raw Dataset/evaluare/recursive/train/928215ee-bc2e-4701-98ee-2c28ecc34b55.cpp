#include <bits/stdc++.h>


using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



string expression;

int expIndex;



int terms();

int calculateInteger();



int calculateExpression() {

    int answer = terms();



    while(expression[expIndex] == '+' || expression[expIndex] == '-') {

        if(expression[expIndex] == '+') {

            ++expIndex;

            answer += terms();

        } else {

            ++expIndex;

            answer -= terms();

        }

    }

    ++expIndex;



    return answer;

}



int terms() {

    int makeProduct = calculateInteger();

    while(expression[expIndex] == '*' || expression[expIndex] == '/') {

        if(expression[expIndex] == '/') {

            ++expIndex;

            makeProduct /= calculateInteger();

        } else {

            ++expIndex;

            makeProduct *= calculateInteger();

        }

    }



    return makeProduct;

}



int calculateInteger() {

    int next_integer = 0;



    if(expression[expIndex] == '(') {

        ++expIndex;

        return calculateExpression();

    }

    while(expression[expIndex] >= '0' && expression[expIndex] <= '9' && expIndex < expression.length()) {

        next_integer = next_integer * 10 + (expression[expIndex] - '0');

        ++expIndex;

    }

    return next_integer;

}



int main()

{

    in >> expression;

    out << calculateExpression();

    return 0;

}

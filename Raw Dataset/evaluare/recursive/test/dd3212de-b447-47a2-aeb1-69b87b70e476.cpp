#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;



ifstream in("evaluare.in");

ofstream out("evaluare.out");



char expr[100001];



int evaluate(char *& expr);

int ori_div(char *& expr);

int plus_minus(char *& expr);

int operand(char *& expr);

int value(char *& expr);



int main()

{

    in.get(expr, 1000001);

    char *p = expr;

    out << evaluate(p);

    return 0;

}



int evaluate(char *& expr)

{

    return

        plus_minus(expr);

}



int ori_div(char *& expr)

{

    int result = operand(expr);

    while(expr[0] == '/' || expr[0] == '*')

    {

        switch(expr[0])

        {

        case '*':

            result = result * operand(++ expr);

            break;

        case '/':

            result = result / operand(++ expr);

            break;

        }

    }

    return

        result;

}



int plus_minus(char *& expr)

{

    int result = ori_div(expr);;

    while(expr[0] == '+' || expr[0] == '-')

    {

        switch(expr[0])

        {

        case '+':

            result += ori_div(++ expr);

            break;

        case '-':

            result -= ori_div(++ expr);

            break;

        }

    }

    return

        result;

}



int operand(char *& expr)

{

    int result;

    if(expr[0] == '(')

    {

        result = evaluate(++ expr);

        ++ expr;

    }

    else

        result = value(expr);

    return

        result;

}



int value(char *& expr)

{

    int nr = 0;

    while(isdigit(expr[0]))

    {

        nr = (expr[0] - '0') + nr * 10;

        ++ expr;

    }

    return nr;

}

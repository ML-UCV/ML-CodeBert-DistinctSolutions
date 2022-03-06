#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char s[100001];



int evaluate(char*& expr);

int operand(char*& expr);

int value(char*& expr);

int plus_minus(char*& expr);

int ori_div(char*& expr);



int main(){

    fin.get(s, 100001 -1);

    char* expr = s;

    fout<<evaluate(expr);

    return 0;

}



int evaluate(char*& expr)

{

    return plus_minus(expr);

}



int operand(char*& expr)

{

    int result;

    if(expr[0] == '('){

      result = evaluate(++expr);

      ++expr;

    } else {

       result = value(expr);

    }

    return result;

}



int value(char*& expr)

{

    int result = 0;

    while(isdigit(expr[0])){

            result = result * 10 + (expr[0] - '0');

            ++expr;

    }

    return result;

}



int plus_minus(char*& expr)

{

    int result = ori_div(expr);

    while(expr[0] == '+' || expr[0] == '-'){

        switch(expr[0]){

            case '+':

                result += ori_div(++expr);

                break;

            case '-':

                result -= ori_div(++expr);

                break;

        }

    }

    return result;

}



int ori_div(char*& expr)

{

    int result = operand(expr);

    while(expr[0] == '*' || expr[0] == '/'){

        switch(expr[0]){

            case '*':

                result *= operand(++expr);

                break;

            case '/':

                result /= operand(++expr);

                break;

        }

    }

    return result;



}

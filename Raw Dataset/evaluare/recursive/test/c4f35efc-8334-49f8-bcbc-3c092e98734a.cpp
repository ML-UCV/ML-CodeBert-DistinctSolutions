#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char s[100005];



int eval(char*& expr);

int operand(char*& expr);

int value(char*& expr);

int pm(char*& expr);

int od(char*& expr);



int eval(char*& expr){

    return pm(expr);

}



int pm(char*& expr){

    int result = od(expr);

    while(expr[0]=='-' || expr[0]=='+'){

        switch (expr[0]){

            case '-':

                result-=od(++expr);

                break;

            case '+':

                result+=od(++expr);

                break;

            default:

                break;

        }

    }

    return result;

}



int od(char*& expr){

    int result = operand(expr);

    while(expr[0]=='/' || expr[0]=='*'){

        switch (expr[0]){

            case '/':

                result/=operand(++expr);

                break;

            case '*':

                result*=operand(++expr);

                break;

            default:

                break;

        }

    }

    return result;

}



int value(char*& expr){

    int n = 0;

    while(isdigit(expr[0])){

        n = n*10 + (expr[0]-'0');

        expr++;

    }

    return n;

}



int operand(char*& expr){

    int result;

    if(expr[0]=='('){

        result = eval(++expr);

        expr++;

    }else{

        result = value(expr);

    }

    return result;

}



int main(){

    fin.get(s, 100005);

    char* expr = s;

    fout<<eval(expr);

    return 0;

}

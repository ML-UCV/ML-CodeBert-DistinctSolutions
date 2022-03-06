#include <bits/stdc++.h>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



stack <int> nums;

stack <char> ops;

int pri[260];



void setpri();

int getNum(char*&s);

void eval(char* s);

void exec(char &op);



int main(){

    setpri();

    char s[100005];

    fin>>s;

    eval(s);

    fout<<nums.top();

    return 0;

}

void setpri(){

    pri['+'] = 1;

    pri['-'] = 1;

    pri['*'] = 2;

    pri['/'] = 2;

    pri['^'] = 3;

}



int getNum(char*&s){

    int num = 0;

    while(isdigit(*s)){

        num = num*10 + *s -'0';

        s++;

    }

    return num;

}



void eval(char* s){

    while(*s){

        if(isdigit(*s)){

            int x = getNum(s);

            nums.push(x);

        }else if(*s == '('){

            ops.push('(');

            s++;

        }else if(*s==')'){

            while(ops.top()!='('){

                exec(ops.top());

                ops.pop();

            }

            ops.pop();

            s++;

        }else{

            char op = *s;

            while(!ops.empty() && pri[ops.top()]>=pri[op]){

                exec(ops.top());

                ops.pop();

            }

            ops.push(op);

            s++;

        }

    }

    while(!ops.empty()){

        exec(ops.top());

        ops.pop();

    }

}



void exec(char &op){

    int rez = 0;

    int x1 = nums.top();

    nums.pop();

    int x2 = nums.top();

    nums.pop();

    switch (op){

        case '+':

            rez = x1+x2;

            break;

        case '-':

            rez = x2-x1;

            break;

        case '*':

            rez = x1*x2;

            break;

        case '/':

            rez = x2/x1;

            break;

        case '^':

            rez = pow(x2,x1);

            break;

        default:

            break;

    }

    nums.push(rez);

}

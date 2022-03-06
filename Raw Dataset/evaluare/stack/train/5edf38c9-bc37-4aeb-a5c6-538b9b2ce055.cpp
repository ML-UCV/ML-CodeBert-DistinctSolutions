#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <map>




using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



char expr[100001];

map<char, int> priority;



struct elts {

    int val;

    int type;

};



bool isDigit(char c) {

    return (c >= '0' && c <= '9');

}



int getNumber(int& i) {

    int ret = 0;

    while (expr[i] != '\0' && isDigit(expr[i]))

        ret = ret * 10 + expr[i] - '0', ++i;

    --i;

    return ret;

}



bool isOperator(char c) {

    return (c == '+' || c == '-' || c == '*' || c == '/');

}



int getRes(int a, int b, char op) {

    if (op == '+')

        return a + b;

    if (op == '-')

        return a - b;

    if (op == '*')

        return a * b;

    if (op == '/')

        return a / b;

}



int compute() {

    stack<char> op;

    vector<elts> val;

    for (int i = 0;expr[i] != '\0';++i) {

        if (isDigit(expr[i]))

            val.push_back({ getNumber(i),0 });

        else if (isOperator(expr[i])) {

            while (!op.empty() && op.top() != '(' && priority[op.top()] >= priority[expr[i]]) {

                val.push_back({ op.top(),1 });

                op.pop();

            }

            op.push(expr[i]);

        }

        else if (expr[i] == '(')

            op.push('(');

        else {

            while (op.top() != '(') {

                val.push_back({ op.top(),1 });

                op.pop();

            }

            op.pop();

        }



    }

    while (!op.empty()) {

        val.push_back({ op.top(),1 });

        op.pop();

    }



    stack<int> res;



    for (int i = 0;i < val.size();++i) {

        if (val[i].type == 0)

            res.push(val[i].val);

        else {

            int a = res.top();

            res.pop();

            int b = res.top();

            res.pop();

            res.push(getRes(b, a, val[i].val));

        }

    }

    return res.top();

}



int main()

{

    fin >> expr;

    priority['+'] = 0;

    priority['-'] = 0;

    priority['*'] = 1;

    priority['/'] = 1;

    fout << compute();



    return 0;

}

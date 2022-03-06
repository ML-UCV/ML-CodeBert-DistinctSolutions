#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

string exp, pol;



int priority(char c) {

    if (c == '(')

        return 0;

    if (c == '-' || c == '+')

        return 1;

    return 2;

}



void genFormaPoloneza(string s) {

    stack<char> oper;

    int poz = 0;



    while (poz < s.length()) {

        if (isdigit(s[poz])) {

            pol += s[poz];

            while (poz + 1 < s.length() && isdigit(s[poz + 1]))

                pol += exp[++poz];

            pol += '.';

        } else if (s[poz] == '(') {

            oper.push('(');

        } else if (s[poz] == ')') {

            while (oper.top() != '(')

                pol += oper.top(), oper.pop();

            oper.pop();

        } else {

            while (!oper.empty() && priority(oper.top()) >= priority(s[poz]))

                pol += oper.top(), oper.pop();

            oper.push(s[poz]);

        }

        poz++;

    }



    while (!oper.empty())

        pol += oper.top(), oper.pop();

}



int evalPol(string s) {

    stack<int> num;

    int poz = -1;



    while (++poz < s.length()) {

        if (isdigit(s[poz])) {

            int nr = 0;

            do {

                nr = nr = nr * 10 + s[poz] - '0';

            } while (poz < s.length() && isdigit(s[++poz]));



            num.push(nr);

        } else {

            int nr = num.top();

            num.pop();



            if (s[poz] == '+')

                num.top() += nr;

            else if (s[poz] == '-')

                num.top() -= nr;

            else if (s[poz] == '*')

                num.top() *= nr;

            else if (s[poz] == '/')

                num.top() /= nr;

        }

    }



    return num.top();

}



int main() {

    fin >> exp;

    genFormaPoloneza(exp);

    fout << evalPol(pol);

    return 0;

}

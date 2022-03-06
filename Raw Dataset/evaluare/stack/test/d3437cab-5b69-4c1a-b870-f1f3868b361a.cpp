#include <bits/stdc++.h>


using namespace std;



ifstream fin ("evaluare.in");

ofstream fout ("evaluare.out");



stack <int> s;

string str, expr;



void opp (int & idx)

{

    while (str[idx] >= '0' && str[idx] <= '9') {

        expr += str[idx];

        idx ++;

    }

    expr += ' ';

    idx --;

}



int priority (int i)

{

    if (str[i] == '*' || str[i] == '/') return 2;

    if (str[i] == '+' || str[i] == '-') return 1;

    return 0;

}



void formaPoloneza (int n)

{

    for (int i = 0; i < n; i ++) {

        if (str[i] >= '0' && str[i] <= '9') opp(i);

        else if (priority(i) != 0) {

            if (s.empty()) s.push(i);

            else {

                while (!s.empty() && priority(s.top()) >= priority(i)) {

                    expr += str[s.top()], s.pop();

                }

                s.push(i);

            }

        }

        else {

            if (str[i] == '(') s.push(i);

            else {

                while (!s.empty() && str[s.top()] != '(') expr += str[s.top()], s.pop();

                expr += ' ';

                if (!s.empty() && str[s.top()] == '(') s.pop();

            }

        }

    }

    while (!s.empty()) expr += str[s.top()], s.pop();

}



int strToInt (int & idx)

{

    int nr = 0;

    while (expr[idx] <= '9' && expr[idx] >= '0') nr = nr * 10 + (expr[idx] - '0'), idx ++;

    idx --;

    return nr;

}



int expresie (int i, int o1, int o2)

{

    if (expr[i] == '+') return o1 + o2;

    else if (expr[i] == '-') return o1 - o2;

    else if (expr[i] == '/') return o1 / o2;

    else return o1 * o2;

}



int evaluare (int n)

{

    int o1, o2;

    while (!s.empty()) s.pop();

    for (int i = 0; i < n; i ++) {

        if (expr[i] >= '0' && str[i] <= '9') s.push(strToInt(i));

        else if (expr[i] != ' ' && s.size() >= 2) {

            o1 = s.top(), s.pop();

            o2 = s.top(), s.pop();

            s.push(expresie(i, o2, o1));

        }

    }

    return s.top();

}



int main()

{

    getline(fin, str);

    int n = str.size();

    formaPoloneza(n);

    fout << evaluare(expr.size());

    return 0;

}

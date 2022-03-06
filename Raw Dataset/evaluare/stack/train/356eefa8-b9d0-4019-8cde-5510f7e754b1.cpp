#include <bits/stdc++.h>


using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



string s;



int apl(int X, int Y, char Z) {

    if(Z == '+') return X + Y;

    if(Z == '-') return X - Y;

    if(Z == '*') return X * Y;

    return X / Y;

}



int prec(const char X) {

    if(X == '+' || X == '-') return 1;

    if(X == '*' || X == '/') return 2;

    return 0;

}



int evexp1(string X) {

    stack<int> nb;

    stack<char> op;

    for(int i = 0; i < X.size(); ++i) {

        if(X[i] == '(') op.push(X[i]);

        else if(isdigit(X[i])) {

            int nr = 0;

            while(i < X.size() && isdigit(X[i]))

                nr = nr * 10 + X[i] - '0', ++i;

            --i, nb.push(nr);

        } else if(X[i] == ')') {

            while(!op.empty() && op.top() != '(') {

                int nr1 = nb.top();

                nb.pop();

                int nr2 = nb.top();

                nb.pop();

                char ope = op.top();

                op.pop();

                nb.push(apl(nr2, nr1, ope));

            }



            if(!op.empty()) op.pop();

        } else {

            while(!op.empty() && prec(op.top()) >= prec(X[i])) {

                int nr1 = nb.top();

                nb.pop();

                int nr2 = nb.top();

                nb.pop();

                char ope = op.top();

                op.pop();

                nb.push(apl(nr2, nr1, ope));

            }

            op.push(X[i]);

        }

    }

    while(!op.empty()) {

        int nr1 = nb.top();

        nb.pop();

        int nr2 = nb.top();

        nb.pop();

        char ope = op.top();

        op.pop();

        nb.push(apl(nr2, nr1, ope));

    }

    return nb.top();

}



int evexp(string X) {

    stack<int> nbs;

    stack<char> ops;

    for(int i = 0; i < X.size(); ++i) {

        if(X[i] == '(') ops.push(X[i]);

        else if(X[i] == ')') {

            while(!ops.empty() && ops.top() != '(') {

                int nr1 = nbs.top();

                nbs.pop();

                int nr2 = nbs.top();

                nbs.pop();

                char ope = ops.top();

                ops.pop();

                nbs.push(apl(nr2, nr1, ope));

            }

            if(!ops.empty()) ops.pop();

        } else if(isdigit(X[i])) {

            int nr = 0;

            while(i < X.size() && isdigit(X[i]))

                nr = nr * 10 + X[i] - '0', ++i;

            --i, nbs.push(nr);

        } else {

            while(!ops.empty() && prec(ops.top()) >= prec(X[i])) {

                int nr1 = nbs.top();

                nbs.pop();

                int nr2 = nbs.top();

                nbs.pop();

                char ope = ops.top();

                ops.pop();

                nbs.push(apl(nr2, nr1, ope));

            }

            ops.push(X[i]);

        }

    }

    while(!ops.empty()) {

        int nr1 = nbs.top();

        nbs.pop();

        int nr2 = nbs.top();

        nbs.pop();

        char ope = ops.top();

        ops.pop();

        nbs.push(apl(nr2, nr1, ope));

    }

    return nbs.top();

}



int main()

{

    getline(fin, s), fout<<evexp(s);

    return 0;

}

#include <bits/stdc++.h>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



short Imp(char op)

{

    if (op == '+' || op == '-')

        return 1;

    if (op == '*' || op == '/')

        return 2;

    return 0;

}



int Operatie(int a, int b, char op)

{

    if (op == '+')return a + b;

    if (op == '-')return a - b;

    if (op == '*')return a * b;

    if (op == '/')return a / b;

}



int eval(string s)

{

    stack<int> t;

    stack<char>op;

    for (int i = 0; i < s.size(); i++)

    {



        if (s[i] == '(')

            op.push(s[i]);

        else if (isdigit(s[i]))

        {

            int val = 0;

            while (i < s.size() && isdigit(s[i])) {

                val = val * 10 + s[i] - '0';

                i++;

            }

            t.push(val);

            i--;

        }

        else if (s[i] == ')')

        {

            while (!op.empty() && op.top() != '(')

            {

                int val1, val2;

                char ope;

                val2 = t.top();

                t.pop();

                val1 = t.top();

                t.pop();

                ope = op.top();

                op.pop();

                t.push(Operatie(val1, val2, ope));

            }

            if (!op.empty())op.pop();

        }

        else

        {



            while (!op.empty() && Imp(op.top()) >= Imp(s[i]))

            {

                int val1, val2;

                char ope;

                val2 = t.top();

                t.pop();

                val1 = t.top();

                t.pop();

                ope = op.top();

                op.pop();

                t.push(Operatie(val1, val2, ope));

            }

            op.push(s[i]);

        }

    }



    while (!op.empty())

    {

        int val1, val2;

        char ope;

        val2 = t.top();

        t.pop();

        val1 = t.top();

        t.pop();

        ope = op.top();

        op.pop();

        t.push(Operatie(val1, val2, ope));



    }

    return t.top();

}



int main()

{

    string s;

    fin >> s;

    fout << eval(s);

    fin.close();

    fout.close();

    return 0;

}

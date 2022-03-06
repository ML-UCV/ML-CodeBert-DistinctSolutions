#include <bits/stdc++.h>
using namespace std;

ifstream fin("evaluare.in");

ofstream fout("evaluare.out");

string tokens;

int n;

stack<char> ops;

stack<int> nr;

int prioritate(char c)

{

    if (c == '-'||c == '+')

        return 1;

    if (c == '*'||c == '/')

        return 2;

    return 0;

}

int culcal(int a,int b,char c)

{

    switch(c){

    case '+': return a+b;

    case '-': return a-b;

    case '*': return a*b;

    case '/': return a/b;

    }

}

int evalexp()

{

    int i = 0;

    int val1,val2,val;

    n = tokens.size();

    while (i != n)

    {

        if (tokens[i] == ' ')

            continue;

        if (tokens[i] == '(') ops.push(tokens[i]);

        else if (isdigit(tokens[i]))

        {

            val = 0;

            while(tokens[i] != '\n' && isdigit(tokens[i]))

            {

                val = val * 10 + (tokens[i] - '0');

                i ++;

            }

            i --;

            nr.push(val);

        }

        else if (tokens[i] == ')')

        {

           while(!ops.empty() && ops.top()!='(')

           {

               val2 = nr.top();

               nr.pop();

               val1 = nr.top();

               nr.pop();

               nr.push(culcal(val1,val2,ops.top()));



               ops.pop();

           }

           if (!ops.empty())

              ops.pop();

        }

        else{

            char op,op1;

            op = tokens[i];

            while (!ops.empty() && prioritate(op) <= prioritate(ops.top()))

            {

                val2 = nr.top();

                nr.pop();

                val1 = nr.top();

                nr.pop();

                op1 = ops.top();

                ops.pop();

                nr.push(culcal(val1,val2,op1));



            }

            ops.push(op);

        }

        i++;

    }

    while(!ops.empty())

    {

        val2 = nr.top();

        nr.pop();

        val1 = nr.top();

        nr.pop();

        nr.push(culcal(val1,val2,ops.top()));



        ops.pop();

        if (!ops.empty())

            if (ops.top() == '(') ops.pop();

    }

    return nr.top();

}

int main()

{

    getline(fin,tokens);

    fout << evalexp() << '\n';

    return 0;

}

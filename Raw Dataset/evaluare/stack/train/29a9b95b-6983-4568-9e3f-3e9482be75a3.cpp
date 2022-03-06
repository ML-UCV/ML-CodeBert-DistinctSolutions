#include <iostream>
#include <fstream>
#include <stack>
using namespace std;



ifstream fin("evaluare.in");

ofstream fout("evaluare.out");



int precedenta(char op)

{

    if(op == '+' || op == '-')

        return 1;

    if(op == '*' || op == '/')

        return 2;

    return 0;

}



int operatie(char op, int x, int y)

{

    switch(op)

    {

    case '+':

        return x+y;

    case '-':

        return x-y;

    case '*':

        return x*y;

    case '/':

        return x/y;



    }

}



int eval(string sir)

{

    int i;

    stack<int> val;

    stack<char> ops;



    for(i=0; i<sir.size(); i++)

    {

        if(sir[i] == '(')

        {

            ops.push(sir[i]);

        }

        else if(isdigit(sir[i]))

        {

            int rez = 0;

            while(i < sir.size() && isdigit(sir[i]))

            {

                rez = rez*10 + (sir[i] - '0');

                i++;

            }

            i--;

            val.push(rez);

        }

        else if(sir[i] == ')')

        {

            while(!ops.empty() && ops.top() != '(')

            {

                int val1, val2, op;

                op = ops.top();

                ops.pop();



                val2 = val.top();

                val.pop();



                val1 = val.top();

                val.pop();



                int rez = operatie(op, val1, val2);

                val.push(rez);



            }

            if(!ops.empty())

                ops.pop();

        }

        else

        {

            while(!ops.empty() && precedenta(ops.top()) >= precedenta(sir[i]))

            {

                int val1, val2, op;

                op = ops.top();

                ops.pop();



                val2 = val.top();

                val.pop();



                val1 = val.top();

                val.pop();



                int rez = operatie(op, val1, val2);

                val.push(rez);

            }

            ops.push(sir[i]);

        }

    }

    while(!ops.empty())

    {

        int val1, val2, op;

        op = ops.top();

        ops.pop();



        val2 = val.top();

        val.pop();



        val1 = val.top();

        val.pop();



        int rez = operatie(op, val1, val2);

        val.push(rez);

    }

    return val.top();

}



int main()

{

    string sir;

    fin>>sir;

    fout<<eval(sir);

    fin.close();

    fout.close();

    return 0;

}

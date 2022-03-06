#include <fstream>
#include <stack>


using namespace std;



stack<int> polo;

stack<char> op;



int priority(char ch)

{

    if (ch=='+'||ch=='-')

        return 1;

    if (ch=='*'||ch=='/')

        return 2;

    return 0;

}



void move_op()

{

    int x,y;

    char semn;

    semn=op.top();

    op.pop();

    y=polo.top();

    polo.pop();

    x=polo.top();

    polo.pop();

    if (semn=='+')

        polo.push(x+y);

    else if (semn=='-')

        polo.push(x-y);

    else if (semn=='*')

        polo.push(x*y);

    else

        polo.push(x/y);

}



int main()

{

    ifstream fin ("evaluare.in");

    ofstream fout ("evaluare.out");

    int nr;

    char ch;

    bool v=0;

    while (fin>>ch)

    {

        if ('0'<=ch&&ch<='9')

            if (v)

                nr=nr*10+(ch-'0');

            else

            {

                v=1;

                nr=ch-'0';

            }

        else

        {

            if (v)

            {

                polo.push(nr);

                v=0;

                nr=0;

            }

            if (ch=='(')

                op.push(ch);

            else if (ch==')')

            {

                while (op.top()!='(')

                    move_op();

                op.pop();

            }

            else

            {

                while (!op.empty()&&priority(ch)<=priority(op.top()))

                    move_op();

                op.push(ch);

            }

        }

    }

    if (v)

        polo.push(nr);

    while (!op.empty())

        move_op();

    fout<<polo.top();

    fin.close();

    fout.close();

    return 0;

}

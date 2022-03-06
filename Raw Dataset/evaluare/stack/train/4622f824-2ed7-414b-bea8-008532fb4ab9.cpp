#include <fstream>
#include <string.h>
#include <stack>




using namespace std;

ifstream fi("evaluare.in");

ofstream fo("evaluare.out");

const int lmax=1e5;

char C[lmax+5];

int n, nr;

stack <char> ops;

stack <int> val;



bool eCifra(char c)

{

    return (c>='0' && c<='9');

}



bool eSemn(char c)

{

    return (c=='+' || c=='-' || c=='*' || c=='/');

}



int operatie(int a, int b, int op)

{

    switch (op)

    {

    case '+':

        return a+b;

        break;

    case '-':

        return a-b;

        break;

    case '*':

        return a*b;

        break;

    case '/':

        return a/b;

    }

}



int ordin(char c)

{

    if(c=='+' || c=='-')

        return 1;

    if(c=='*' || c=='/')

        return 2;

    return 3;

}



int main()

{

    C[0]='(';

    fi>>C+1;

    n=strlen(C+1);

    C[n+1]=')';



    for(int i=0; i<=n+1; i++)

    {

        if(eCifra(C[i]))

        {

            nr=nr*10+(C[i]-'0');

            if(!eCifra(C[i+1]))

            {

                val.push(nr);

                nr=0;

            }

        }

        else

        {

            if(C[i]=='(')

                ops.push(C[i]);

            else

            {

                if(C[i]==')')

                {

                    while(ops.top()!='(')

                    {

                        int b=val.top();

                        val.pop();

                        int a=val.top();

                        val.pop();

                        val.push(operatie(a, b, ops.top()));

                        ops.pop();

                    }

                    ops.pop();

                }

                else if(eSemn(C[i]))

                {

                    if(C[i-1]=='(')

                    {

                        val.push(0);

                    }

                    while(ordin(ops.top())>=ordin(C[i]) && ops.top()!='(')

                    {

                        int b=val.top();

                        val.pop();

                        int a=val.top();

                        val.pop();

                        val.push(operatie(a, b, ops.top()));

                        ops.pop();

                    }

                    ops.push(C[i]);

                }

            }

        }

    }



    fo<<val.top();



    fi.close();

    fo.close();

    return 0;

}

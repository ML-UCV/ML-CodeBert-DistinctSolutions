#include <fstream>
#include <stack>




using namespace std;



ifstream cin("evaluare.in");

ofstream cout("evaluare.out");



int precedence(char op)

{

    if(op == '+'||op == '-')

        return 1;

    if(op == '*'||op == '/')

        return 2;

    return 0;

}



int opera(int a, int b, char op)

{

    if(op == '+')

        return a + b;

    if(op == '-' )

        return a - b;

    if(op == '*')

        return a * b;

    if(op == '/')

        return a / b;

}



int eval(string token)

{

    int i;

    stack <int> values;



    stack <char> ops;



    for(i = 0 ; i < token.length() ; i++)

    {

        if(token[i] == '(')

            ops.push(token[i]);



        else if(isdigit(token[i]))

        {

            int val = 0;



            while(i < token.length() &&

                        isdigit(token[i]))

            {

                val = (val*10) + (token[i]-'0');

                i++;

            }

            i--;

            values.push(val);

        }



        else if(token[i] == ')')

        {

            while(!ops.empty() && ops.top() != '(')

            {

                int val2 = values.top();

                values.pop();



                int val1 = values.top();

                values.pop();



                char oper = ops.top();

                ops.pop();



                values.push(opera(val1, val2, oper) );

            }

            ops.pop();

        }





        else

        {

            while(!ops.empty() && precedence(ops.top()) >= precedence(token[i]))

            {

                int val2 = values.top();

                values.pop();



                int val1 = values.top();

                values.pop();



                char oper = ops.top();

                ops.pop();



                values.push(opera(val1, val2, oper) );

            }

            ops.push(token[i]);

        }

    }



    while(!ops.empty())

    {

        int val2 = values.top();

        values.pop();



        int val1 = values.top();

        values.pop();



        char oper = ops.top();

        ops.pop();



        values.push(opera(val1, val2, oper) );



    }



    return values.top();

}



int main()

{

    string token;

    getline(cin, token);

 cout << eval(token) ;

    return 0;

}

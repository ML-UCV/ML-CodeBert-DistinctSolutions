#include <bits/stdc++.h>
using namespace std;


int precedence(char op)
{
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch(op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

bool is_operator(char to_check)
{
    return to_check=='+' || to_check=='-' ||to_check=='*' ||to_check=='/';

}


bool is_digit(char x)
{
    return x>='0' && x<='9';

}

int get_next_number(const string&x,unsigned&cursor)
{
    int res=0;

    while(is_digit(x[cursor]) && cursor<x.length())
    {
        res=res*10+(x[cursor]-'0');
        cursor++;

    }
    cursor--;

    return res;



}

stack <int> values;
stack <char> ops;

void apply_last_operation()
{
    int a=values.top();
    values.pop();
    int b=values.top();
    values.pop();

    char op=ops.top();

    int c=applyOp(b,a,op);


    values.push(c);

    ops.pop();
}



void eval()
{

    while(ops.top()!='(')
    {
        apply_last_operation();
    }
    ops.pop();

}



int evaluate(string tokens)
{
    for(unsigned i=0; i<tokens.length(); i++)
    {
        if(is_digit(tokens[i]))
        {
            int value=get_next_number(tokens,i);
            values.push(value);
        }
        else if(tokens[i]=='(')
        {
            ops.push(tokens[i]);
        }
        else if(tokens[i]==')')
        {
            eval();
        }

        else if(is_operator(tokens[i]))
        {
            char op=tokens[i];

            while(!ops.empty() && precedence(ops.top())>=precedence(op))
            {
                apply_last_operation();
            }
            ops.push(op);
        }



    }

    while(!ops.empty())
    {
        apply_last_operation();
    }
    return values.top();

}

int main()
{
    ifstream in("evaluare.in");
    string a;
    in>>a;
    ofstream out("evaluare.out");
    out<<evaluate(a);

    return 0;
}

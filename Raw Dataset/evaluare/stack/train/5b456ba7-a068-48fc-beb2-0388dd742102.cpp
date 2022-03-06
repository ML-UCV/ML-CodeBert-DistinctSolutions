#include <iostream>
#include<stack>
#include<fstream>

using namespace std;

bool is_operator(char to_check)
{
    return to_check =='+'||to_check=='-'||to_check=='/'||to_check=='*'||to_check=='^';
}

int apply_operator(int a,int b,char op)
{
    switch(op)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '^':
        return a^b;


    }


}


int get_precedence(char to_get)
{


    switch(to_get)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    }

    return 0;
}

bool is_character(char to_check)
{

    return to_check>='0' &&to_check<='9';

}

int get_next_number(const std::string&s,unsigned&cursor)
{
    int to_return=0;


    while(is_character(s[cursor]))
    {
        to_return=to_return*10+(s[cursor++]-'0');
    }
    cursor--;

    return to_return;
}


string get_infix(const std::string&postfix)
{
    stack<char> operators;
    string to_return;

    for(unsigned i=0; i<postfix.length(); i++)
    {
        char here=postfix[i];

        if(is_character(here))
        {
            int p=get_next_number(postfix,i);

            to_return+=to_string(p)+',';
        }
        else if(here=='(')
        {
            operators.push(here);
        }
        else if(here==')')
        {
            while(operators.size()&&operators.top()!='(')
            {
                to_return+=operators.top();
                operators.pop();
            }
            if(operators.size())
                operators.pop();
        }
        else if(is_operator(here))
        {
            while(operators.size() && get_precedence(here)<=get_precedence(operators.top()))
            {
                to_return+=operators.top();
                operators.pop();
            }
            operators.push(here);
        }
    }
    while(operators.size())
    {
        to_return+=operators.top();
        operators.pop();
    }


    return to_return;
}



int get_result(const std::string&infix)
{
    stack<int> values;

    for(unsigned i=0; i<infix.length(); i++)
    {
        char here=infix[i];
        if(is_character(here))
        {
            int to_add=get_next_number(infix,i);
            values.push(to_add);
        }
        else if(is_operator(here))
        {
            int a=values.top();
            values.pop();
            int b=values.top();
            values.pop();



            values.push(apply_operator(b,a,here));
        }

    }
    return values.top();



}


int main()
{

    ifstream in("evaluare.in");
    ofstream out("evaluare.out");
    string to_eval;
    in>>to_eval;

    string infix=get_infix(to_eval);

    out<<get_result(infix);
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

ifstream in("evaluare.in");
ofstream out("evaluare.out");


string to_eval;

bool is_operator(char x)
{

    return x=='+'||x=='-'||x=='*'||x=='/';

}



bool is_digit(char a)
{

    return a>='0' &&a<='9';
}

int apply(int a,int b,char op)
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
    default:
        return -1;
    }


}


int get_int_at(string&r,int&index)
{
    int result=0;

    while(is_digit(r[index]))
    {
        result=result*10+(r[index]-'0');
        index++;
    }
    index--;
    return result;
}



int operator_order(char x)
{
    switch(x)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return -1;
    }

}

string get_polish_form(string expression)
{
    stack<char> st;
    string to_return;

    for(int i=0; i<expression.length(); i++)
    {
        if(expression[i]=='(')
        {
            st.push('(');
        }
        else if(is_digit(expression[i]))
        {
            to_return+=to_string(get_int_at(expression,i))+" ";
        }
        else if(is_operator(expression[i]))
        {
            while(st.size() && operator_order(st.top())>=operator_order(expression[i]))
            {
                to_return+=st.top();
                st.pop();
            }
            st.push(expression[i]);
        }
        else if(expression[i]==')')
        {
            while(st.size() && st.top()!='(')
            {
                to_return+=st.top();
                st.pop();
            }
            if(st.top()=='(')
                st.pop();
        }

    }
    while(st.size())
    {
        to_return+=st.top();
        st.pop();
    }


    return to_return;
}

int evaluate_polish_form(string polish)
{
    stack<int>processed;
    for(int i=0; i<polish.length(); i++)
    {
        if(is_digit(polish[i]))
        {
            int to_push=get_int_at(polish,i);
            processed.push(to_push);
        }
        else if(is_operator(polish[i]))
        {
            int a,b;
            a=processed.top();
            processed.pop();
            b=processed.top();
            processed.pop();

            processed.push(apply(b,a,polish[i]));
        }


    }
    return processed.top();



}

int main()
{
    in>>to_eval;
    string polish=get_polish_form(to_eval);
    out<<evaluate_polish_form(polish);



}

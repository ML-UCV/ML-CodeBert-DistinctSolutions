#include<fstream>
#include<iostream>
using namespace std;
string expresion;
ifstream in("evaluare.in");
ofstream out("evaluare.out");
char is_digit(char a)
{
    return a>='0'&&a<='9';
}
int get_number(int&to_start)
{
    int f=0;
    for(; is_digit(expresion[to_start]); to_start++)
    {
        f=f*10+(expresion[to_start]-'0');
    }
    to_start--;
    return f;

}
void encapsulate(string&a)
{
    a='('+a+')';
}
bool is_operator(char a)
{
    return a=='+'||a=='-';
}
bool is_operator2(char a)
{
    return a=='*'||a=='/';
}
void evaluate(int&last,int now,char oper)
{
    switch(oper)
    {
    case '+':
        last+=now;
        break;
    case '-':
        last-=now;
        break;
    case '/':
        last/=now;
        break;
    case '*':
        last*=now;
        break;

    }

}
int get_factor(int&to_start);
int solve_paranthesis(int&to_start);
int get_factor(int&to_start)
{
    int first;
    if(expresion[to_start]!='(')
    {
        first=get_number(to_start);
        to_start++;
    }
    else
    {
        to_start++;
        first=solve_paranthesis(to_start);
        to_start++;

    }
    while(is_operator2(expresion[to_start]))
    {
        char last=expresion[to_start];
        to_start++;
        if(is_digit(expresion[to_start]))
        {
            int num=get_number(to_start);
            evaluate(first,num,last);
        }
        else
        {
            if(expresion[to_start]=='(')
            {
                to_start++;
                int p=solve_paranthesis(to_start);
                evaluate(first,p,last);


            }

        }
        to_start++;
    }
    to_start--;
    return first;


}
int solve_paranthesis(int&to_start)
{
    char last_operator='+';
    int last_result=0;
    for(; expresion[to_start]!=')'; to_start++)
    {
        if(!is_operator(expresion[to_start]))
        {
            int p=get_factor(to_start);
            evaluate(last_result,p,last_operator);
        }
        else
        {
            last_operator=expresion[to_start];
        }
    }
    return last_result;



}
int main()
{
    in>>expresion;
    encapsulate(expresion);
    int cursor=1;
    out<<solve_paranthesis(cursor);
}

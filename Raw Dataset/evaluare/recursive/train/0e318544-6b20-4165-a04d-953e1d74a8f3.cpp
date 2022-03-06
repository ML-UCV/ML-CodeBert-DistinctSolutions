#include <iostream>
#include<fstream>
using namespace std;
ifstream in("evaluare.in");
ofstream out("evaluare.out");


string to_calculate;

int get_factor(int&cursor);
int solve_parentheses(int&cursor);



bool is_digit(char character)
{
    return character>='0' &&character<='9';
}

int to_digit(char character)
{
    return character-'0';

}


bool is_operator(char c)
{
    return c=='+'||c=='-';

}

bool is_factor(char c)
{
    return c=='*' ||c=='/';
}

int get_next_number(int&cursor)
{
    int to_return=0;

    while(cursor<to_calculate.length() &&is_digit(to_calculate[cursor]))
    {
        to_return=to_return*10+to_digit(to_calculate[cursor]);
        cursor++;
    }
    cursor--;

    return to_return;

}


void add_result(char oper,int &to,int what)
{
    if(oper=='+')
    {
        to+=what;
    }
    else if(oper=='-')
        to-=what;
}

int get_factor(int&cursor)
{
    int result;

    if(is_digit(to_calculate[cursor]))
        result=get_next_number(cursor);
    else
    {
        cursor++;
        result=solve_parentheses(cursor);
    }

    cursor++;

    while(is_factor(to_calculate[cursor]))
    {
        char factor=to_calculate[cursor];
        cursor++;

        int to_add=1;

        if(is_digit(to_calculate[cursor]))
        {
            to_add=get_next_number(cursor);
        }
        else
        {
            cursor++;
            to_add=solve_parentheses(cursor);
        }

        if(factor=='*')
            result*=to_add;
        else
            result/=to_add;

        cursor++;
    }
    cursor--;
    return result;
}

int solve_parentheses(int&cursor)
{
    int result=0;
    char last_operator='+';


    while(to_calculate[cursor]!=')')
    {
        char here=to_calculate[cursor];
        if(is_operator(here))
        {
            last_operator=here;
        }
        else
        {
            int to_add=get_factor(cursor);
            add_result(last_operator,result,to_add);
        }

        cursor++;

    }
    return result;


}



void read()
{
    in>>to_calculate;
    to_calculate='('+to_calculate+')';

}


int main()
{
    read();
    int cursor=1;
    out<<solve_parentheses(cursor);

    return 0;
}
